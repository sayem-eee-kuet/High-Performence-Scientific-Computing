#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <mpi.h>
#include <chrono> //C++ timming library
#include "secret_function.h"

double interval_map(double lowerLim, double upperLim, unsigned int *seed);
void mpiFqn(int argc, char **argv);

int main(int argc, char **argv)
{
    std::cout.precision(6);
    std::cout << std::fixed;
    //auto t_start = std::chrono::high_resolution_clock::now();
    // MPI_Init(&argc, &argv);
    // unsigned long N = atol(argv[1]);
    mpiFqn(argc, argv);
    //std::cout<<"Hi"<<std::endl;
    // MPI_Finalize();
    // auto t_end = std::chrono::high_resolution_clock::now();
    // std::chrono::duration<double, std::milli> duration = (t_end - t_start);
    // std::cout << "Time for total program = " << duration.count() << " ms " << std::endl;
    return 0;
}

void mpiFqn(int argc, char **argv)
{
    int rank, size;
    //const int master = 0;
    MPI_Init(&argc, &argv);
    const int master = 0;
    double t_start = 0.0;
    double t_end = 0.0;

    double s_reductionTime = 0.0;
    double e_reductionTime = 0.0;

    t_start = MPI_Wtime();
    // if (rank == master)
    // {
    //     double t_start = MPI_Wtime();
    // }
    unsigned long int N = atol(argv[1]);
    // int rank, size;

    //MPI_Init(&argc, &argv);               // initializes MPI
    MPI_Comm_rank(MPI_COMM_WORLD, &rank); // get current MPI-process ID. O, 1, ...
    MPI_Comm_size(MPI_COMM_WORLD, &size); // get the total number of processes
    //unsigned long N = atol(argv[1]);
    //rand(time(NULL) * rank); // each MPI process gets a unique seed

    unsigned int seed = (int)(time(NULL)) * (rank + 1);

    const double a = -512.0;
    const double b = 512.0;

    const int dim = 2;
    double *x;
    x = new double[dim];

    double f_i = 0.0;
    double localMin = 100000.0;
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

    MPI_Barrier(MPI_COMM_WORLD);
    std::cout << "Process: " << rank << " Local min = " << localMin << std::endl;
    s_reductionTime = MPI_Wtime();
    MPI_Reduce(&localMin, &globalMin, 1, MPI_DOUBLE, MPI_MIN, 0, MPI_COMM_WORLD);
    e_reductionTime = MPI_Wtime();
    // MPI_Barrier(MPI_COMM_WORLD);

    t_end = MPI_Wtime();

    if (rank == master)
    {
        std::cout << "Global Min = " << globalMin << std::endl;
        // //t_end = MPI_Wtime();
        // auto t_end = std::chrono::high_resolution_clock::now();
        // std::chrono::duration<double, std::milli> duration = (t_end - t_start);
        // std::cout << "Time for total program = " << duration.count() << " ms " << std::endl;
        // //std::cout << "Time for total program = " << t_end - t_start << "s" << std::endl;
        // double t_end = MPI_Wtime();
        std::cout << "Time for Reduction = " << e_reductionTime - s_reductionTime << "s" << std::endl;
        std::cout << "Time for total program = " << t_end - t_start << "s" << std::endl;
    }

    MPI_Finalize();

    delete[] x;
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