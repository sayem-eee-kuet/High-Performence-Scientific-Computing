#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <omp.h>
#include <chrono>

using namespace std;

double interval_map(double lowerLim, double upperLim, unsigned int *seed);
double dice(unsigned long long int N, const int NThreads);

int main(int argc, char **argv)
{
    unsigned long long int N = atol(argv[1]);
    const int NThreads = atoi(argv[2]);

    double timeStart = omp_get_wtime();
    double avg = dice(N, NThreads);
    double timeEnd = omp_get_wtime();
    double wallTime = timeEnd - timeStart;
    cout << N << " " << wallTime << "s " << avg << " Number of threads: " << NThreads << endl;
    return 0;
}

double dice(unsigned long long int N, const int NThreads)
{
    omp_set_num_threads(NThreads);

    double total = 0.0;
    // unsigned int seed = 0;
    double a = 1.0;
    double b = 6.0;

#pragma omp parallel //private(seed)
    {
        const int thread_rank = omp_get_thread_num();
        unsigned int seed = time(NULL) * (int)(thread_rank + 1);
#pragma omp for reduction(+ : total)
        for (unsigned long long int i = 0; i < N; ++i)
        {
            double dice1 = interval_map(a, b, &seed);
            double dice2 = interval_map(a, b, &seed);
            // cout << dice1 << " " << dice2 << endl;
//#pragma omp atomic
            total = total + dice1 + dice2;
        }
    }
    double avg = total / N;
    //cout << N << " " << (int)avg << endl;
    //cout << N << " " << avg << endl;
    return avg;
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