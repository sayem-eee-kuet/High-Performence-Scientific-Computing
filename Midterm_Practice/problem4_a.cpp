#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <omp.h>
#include <chrono>

using namespace std;
double interval_map(double lowerLim, double upperLim, unsigned int *seed);
int int_interval_map(int lowerLim, int upperLim, unsigned int *seed);

int main(int argc, char **argv)
{
    const int NThreads = 4; // atoi(argv[2]);
    omp_set_num_threads(NThreads);
    int team_win = 0;
    //srand(time(NULL));

#pragma omp parallel
    {
        const int thread_rank = omp_get_thread_num();
        unsigned int seed = time(NULL) * (int)(thread_rank + 1);
        int player_win = 0;

        int player = 1 + omp_get_thread_num();
        int rolls = int_interval_map(1, 6, &seed);

        if (rolls <= player)
        {
            //cout << "Player " << player << "," << "rolls " << "," << "wins money" << endl;
            printf("Player %i, rolls %i, wins money\n", player, rolls);
            player_win = 1;
        }
        else
        {
            printf("Player %i, rolls %i, lost money\n", player, rolls);
            player_win = -1;
        }
#pragma omp atomic
        team_win = team_win + player_win;
    }

    std::cout << "Team wins = " << team_win << endl;
    // printf("Team wins = %i", team_win);

    return 0;
}

int int_interval_map(int lowerLim, int upperLim, unsigned int *seed)
{
    int range = upperLim - lowerLim + 1;
    int randomNumber = lowerLim + (rand_r(seed)) % (range);
    return randomNumber;
    //return ((upperLim - lowerLim) * randomNumber + lowerLim);
}

double interval_map(double lowerLim, double upperLim, unsigned int *seed)
{
    /**************************************************************
     * Mapping the [0,1]=>[lowerLim, upperLim]
     * f(x) = mx + c, f(0) = lowerLim and f(1) = upperLim
     * Solving this we get, f(x) = (upperLim-lowerLim)x + lowerLim
    ***************************************************************/
    // double upperLim = b;
    // double lowerLim = a;
    double randomNumber = ((double)rand_r(seed)) / ((double)RAND_MAX);
    return ((upperLim - lowerLim) * randomNumber + lowerLim);
}