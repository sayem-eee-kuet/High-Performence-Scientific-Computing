#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
//#include <mpi.h>
#include "secret_function.h"

double interval_map(double lowerLim, double upperLim, unsigned int *seed);

int main(int argc, char **argv)
{
    std::cout.precision(6);
    std::cout << std::fixed;
    const int master = 0;

    int rank = 0;
    int size = 0;
    // MPI_Init(&argc, &argv);               // initializes MPI
    // MPI_Comm_rank(MPI_COMM_WORLD, &rank); // get current MPI-process ID. O, 1, ...
    // MPI_Comm_size(MPI_COMM_WORLD, &size); // get the total number of processes
    unsigned long N = atol(argv[1]);
    //rand(time(NULL) * rank); // each MPI process gets a unique seed

    unsigned int seed = (int)(time(NULL)) * (rank + 1);

    const double a = -512.0;
    const double b = 512.0;

    const int dim = 2;
    double *x;
    x = new double[dim];

    double f_i = 0.0;
    double localMin = 1000000.0;
    double globalMin = 0.0;
    for (unsigned long int i = 0; i < N; ++i)
    {
        //std::cout << "For i = " << i << std::endl;
        x[0] = interval_map(a, b, &seed);
        x[1] = interval_map(a, b, &seed);
        f_i = secret_function(x[0], x[1]);
        std::cout << "For process: " << rank << " Sample: " << i + 1 << " f_i = " << f_i << std::endl;
        if (localMin > f_i)
        {
            localMin = f_i;
        }
    }

    //MPI_Barrier(MPI_COMM_WORLD);
    std::cout << "Process: " << rank << " Local min = " << localMin << std::endl;
    //MPI_Reduce(&localMin, &globalMin, 1, MPI_DOUBLE, MPI_MIN, 0, MPI_COMM_WORLD);
    // MPI_Barrier(MPI_COMM_WORLD);
    // std::cout << "Process: " << rank << " Local min = " << f_i << std::endl;
    // MPI_Barrier(MPI_COMM_WORLD);
    // if (rank == master)
    // {
    //     std::cout << "Global Min = " << globalMin << std::endl;
    // }

    // MPI_Finalize();

    delete[] x;
    return 0;
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