#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <mpi.h>
#include <chrono>

using namespace std;

int int_interval_map(int lowerLim, int upperLim, unsigned int *seed);
int simple_rand_map(int lowerLim, int upperLim);

int main(int argc, char **argv)
{
    int rank, size;
    MPI_Status status;
    int dealer = 0;

    MPI_Init(&argc, &argv);               // initializes MPI
    MPI_Comm_rank(MPI_COMM_WORLD, &rank); // get current MPI-process ID. O, 1, ...
    MPI_Comm_size(MPI_COMM_WORLD, &size); // get the total number of processes

    srand(time(NULL) * (rank + 1)); // each MPI process gets a unique seed
    //unsigned int seed = (time(NULL) * rank);
    // int Call = 0;

    int Call = simple_rand_map(2, 21);
    int dealerNum = 0;
    int playerMoney = 0;
    int teamMoney = 0;

    if (rank == dealer)
    {
        cout << "Dealer picked " << Call << endl;
        for (int i = 1; i < size; ++i)
        {
            MPI_Send(&Call, 1, MPI_INT, i, 0, MPI_COMM_WORLD);
        }
        //MPI_Bcast(&Call, 1, MPI_INT, dealer, MPI_COMM_WORLD);
    }
    else
    {
        MPI_Recv(&dealerNum, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, &status);

        if (dealerNum >= Call)
        {
            playerMoney = -1;
        }
        else
        {
            playerMoney = 1;
        }
        cout << "Player " << rank << " picks " << Call << ". Money = " << playerMoney << endl;
        //cout << "Dealer has " << dealerNum << "," << " player " << rank +1 <<" has " << Call << "," << " Money " << playerMoney <<endl;
    }

    //cout << "Player " << rank + 1 << " picks " << Call <<". Money = " << playerMoney <<endl;

    MPI_Reduce(&playerMoney, &teamMoney, 1, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);

    if (rank == dealer)
    {
        cout << "Team Winning " << teamMoney << endl;
    }

    // printf("[%d]: After Bcast, buf is %d\n", rank, Call);

    MPI_Finalize();
    return 0;
}

int int_interval_map(int lowerLim, int upperLim, unsigned int *seed)
{
    int range = upperLim - lowerLim + 1;
    int randomNumber = lowerLim + (rand_r(seed)) % (range);
    return randomNumber;
    //return ((upperLim - lowerLim) * randomNumber + lowerLim);
}

int simple_rand_map(int lowerLim, int upperLim)
{
    int range = upperLim - lowerLim + 1;
    int randomNumber = lowerLim + rand() % (range);
    return randomNumber;
}