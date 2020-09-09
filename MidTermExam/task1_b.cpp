#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <omp.h>

double g(double x);
double h(double x);

int main(int argc, char **argv)
{
    std::cout.precision(11);
    std::cout << std::fixed;

    //int x = atoi(argv[1]);
    double x = atof(argv[1]);
    omp_set_num_threads(2);
    double g_v = 0.0;
    double h_v = 0.0;
#pragma omp parallel //lastprivate(g_v,h_v) 
    {
        // double g_v = 0.0;
        // double h_v = 0.0;
        double sum = 0.0;
        const int thread_rank = omp_get_thread_num();
        if(thread_rank == 0)
        {
            g_v = g(x);
            printf("threasd %d, g(%0.1f) = %0.11f\n", thread_rank, x, g_v);
            //std::cout << "thread " << thread_rank << "," << " g("<<x<<")= " << g_v <<"\n";
        } else
        {
            h_v = h(x);
            printf("threasd %d, h(%0.1f) = %0.11f\n", thread_rank, x, h_v);
            //std::cout << "thread " << thread_rank << "," << " h("<< x <<")= " << h_v <<"\n";
        }
#pragma omp master 
        sum = g_v + h_v;
#pragma omp master 
        printf("f(%0.1f) = %0.11f\n", x, sum);
#pragma omp barrier

        
    // double f = 0.0;
    // f = g(x) + h(x);
    // std::cout << "f(" << x << ") = " << f << std::endl;
    }
   return 0; 
   }

double g(double x)
{
    return sin(x);
}

double h(double x)
{
    return cos(x);
}