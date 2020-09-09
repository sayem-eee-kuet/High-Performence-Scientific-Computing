#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <mpi.h>

void sample_rand(const double a, const double b, const int dim, double *x);
double f(double *x);

int main(int argc, char **argv)
{
    int rank, size;
    //double send_number = 9;
    //double rec_number;
   // MPI_Status status;

    MPI_Init(&argc, &argv);               // initializes MPI
    MPI_Comm_rank(MPI_COMM_WORLD, &rank); // get current MPI-process
    MPI_Comm_size(MPI_COMM_WORLD, &size); // get the total number of processes

    long int N = atol(argv[1]);
    srand(time(NULL) * rank); // each MPI process gets a unique seed

    const int dim = 2;
    double x[dim]; // array of random numbers

    // search for the function's maximum
    double max = -1;
    srand(time(NULL) * rank);

    for (long int i = 1; i <= N; ++i)
    {
        sample_rand(-5.0, 5.0, dim, x);
        double f_i = f(x);
        if (f_i > max)
        {
            max = f_i;
            //send_number = max;
        }
    }

    //printf("Process %d of %d local max = %f\n", rank, size, max);

    double process_local_max = max; // this is the maximum found by the process
    double process_global_max = -100;        // processor 0 will hold the global maximum
    MPI_Reduce(&process_local_max, &process_global_max, 1, MPI_DOUBLE, MPI_MAX, 0, MPI_COMM_WORLD);
    printf("Process ID %i, Local max, x = %f, Global max = %f\n", rank, process_local_max, process_global_max);
    MPI_Finalize(); // programs should always perform a "graceful" shutdown


    return 0;
}

void sample_rand(const double a, const double b, const int dim, double *x)
{
    for (int i = 0; i < dim; ++i)
    {
        double tmp = ((double)rand()) / ((double)RAND_MAX);
        x[i] = (b - a) * tmp + a;
    }
}

double f(double *x)
{
    double x1 = x[0];
    double x2 = x[1];
    //return exp(-(pow((1.00 - x), 2.00)) - 100.00 * (pow((y - pow(x, 2.00)), 2.00)));
    return exp(-(1.0 - x1) * (1.0 - x1) - 100.0 * (x2 - x1 * x1) * (x2 - x1 * x1));
}

