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
    double send_number = 9;
    double rec_number;
    MPI_Status status;
    //double max_number = -1;

    MPI_Init(&argc, &argv);               // initializes MPI
    MPI_Comm_rank(MPI_COMM_WORLD, &rank); // get current MPI-process ID. O, 1, ...
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

    // printf("Process %d of %d local max = %f\n", rank, size, max);
    // printf("========Ring Starts========\n");
    if (rank == 0)
    {
        // only the process with rank ID = 0 will be in this block of code.
        // send data to process 1
        send_number = max;
        MPI_Send(&send_number, 1, MPI_DOUBLE, 1, 0, MPI_COMM_WORLD);
        // receive data from process size-1
        MPI_Recv(&rec_number, 1, MPI_DOUBLE, size - 1, 0, MPI_COMM_WORLD, &status);
    }
    else if (rank == size - 1)
    {

        // receive data from process rank-1 (it "left" neighbor")
        MPI_Recv(&rec_number, 1, MPI_DOUBLE, rank - 1, 0, MPI_COMM_WORLD, &status);
        // send data to its "right neighbor", rank 0
        if (rec_number > max)
        {
            send_number = rec_number;
            MPI_Send(&send_number, 1, MPI_DOUBLE, 0, 0, MPI_COMM_WORLD);
        }
        else
        {
            send_number = max;
            MPI_Send(&send_number, 1, MPI_DOUBLE, 0, 0, MPI_COMM_WORLD);
        }
    }
    else
    {
        // receive data from process rank-1 (it "left" neighbor")
        MPI_Recv(&rec_number, 1, MPI_DOUBLE, rank - 1, 0, MPI_COMM_WORLD, &status);
        if (rec_number > max)
        {
            send_number = rec_number;
            // send data to its "right neighbor" (rank+1)
            MPI_Send(&send_number, 1, MPI_DOUBLE, rank + 1, 0, MPI_COMM_WORLD);
        }
        else
        {
            send_number = max;
            MPI_Send(&send_number, 1, MPI_DOUBLE, rank + 1, 0, MPI_COMM_WORLD);
        }
    }

    printf("Process %i send %f and recieved %f\n", rank, send_number, rec_number);
    if (rank == 0)
    {
        printf("Global maximum is %f\n", rec_number);
    }

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

