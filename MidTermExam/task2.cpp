#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <omp.h>
#include <mpi.h>

double g(double x);
double h(double x);

int main(int argc, char **argv)
{
    std::cout.precision(11);
    std::cout << std::fixed;

    int rank, size;
    //omp_set_num_threads(3);
   // MPI_Status status;

    MPI_Init(&argc, &argv);               // initializes MPI
    MPI_Comm_rank(MPI_COMM_WORLD, &rank); // get current MPI-process ID. O, 1, ...
    MPI_Comm_size(MPI_COMM_WORLD, &size); // get the total number of processes
    //omp_set_num_threads(3);

    for(int i = rank; i < size; ++i)
    {
        omp_set_num_threads(rank+1);
        #pragma omp parallel // num_threads()
        {
            int thread = omp_get_num_threads();
            printf("Hello world from process %d thread %d\n",rank, thread);
        }

    }


    MPI_Finalize();
    return 0;





}
