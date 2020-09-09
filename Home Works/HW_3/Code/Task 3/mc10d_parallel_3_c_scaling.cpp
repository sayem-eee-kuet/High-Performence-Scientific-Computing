#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <omp.h>
#include <chrono>

using namespace std;

void interval_map(const double a, const double b, const int dim, unsigned int *seed, double *x)
{

    for (int i = 0; i < dim; ++i)
    {
        double random = ((double)rand_r(seed)) / ((double)RAND_MAX);
        random = (b - a) * random + a;
        x[i] = random;
    }
}

double L(double *x, int dim)
{

    double fqn = 0.0;

    for (int i = 0; i < dim - 1; ++i) //sum 0 to 9
    {
        fqn = fqn + (1.0 - x[i]) * (1.0 - x[i]) + 100.0 * (x[i + 1] - x[i] * x[i]) * (x[i + 1] - x[i] * x[i]);
    }

    fqn = exp(-fqn);

    return fqn;
}

double lnL(double *x, int dim)
{

    double fqn = 0.0;

    for (int i = 0; i < dim - 1; ++i) //sum 0 to 9
    {
        fqn = fqn + (1.0 - x[i]) * (1.0 - x[i]) + 100.0 * (x[i + 1] - x[i] * x[i]) * (x[i + 1] - x[i] * x[i]);
    }

    fqn = -fqn;

    return fqn;
}

double volume(double a, double b, int dim) //, double a2, double b2)
{
    int length = b - a;
    /*************
     * V = L**dim
    **************/
    return std::pow(length, dim);
}

void intigration(unsigned long long int N, const int dimention)
{
    const double a = -0.5;
    const double b = 0.5;
    const double V = volume(a, b, dimention);
    unsigned long long int start_loop = 1;
    unsigned long long int end_loop = 4;

    bool continue_work = true;
    double sumFinal = 0.0;

    double x[dimention]; // array of random numbers
    double sum = 0.0;

#pragma omp parallel firstprivate(x) shared(start_loop, end_loop, sum, continue_work)
    {
        //double sum = 0.0;
        double previous = 0.0;
        const int thread_rank = omp_get_thread_num();
        //printf("Thread %i reporting for work.\n", thread_rank);
        //cout << "Thread " << thread_rank << " reporting for work" << endl;
        unsigned int seed = time(NULL) * (int)(thread_rank + 1);
        while (continue_work)
        {
#pragma omp for //reduction(+ \
                          : sum)
            for (unsigned int i = start_loop; i <= end_loop; ++i)
            {
                interval_map(a, b, dimention, &seed, x);
                double fqn_value = L(x, dimention);
#pragma omp atomic
                sum += fqn_value;
            }
// #pragma omp atomic
//             sumFinal = sumFinal + sum;
#pragma omp barrier
#pragma omp master
            {
                double current = V * sum / (double)end_loop;
                double err_per_step = fabs(current - previous);
                previous = current;
                // cout << end_loop << " " << current << " " << err_per_step << endl;
                start_loop = end_loop + 1;
                if (start_loop >= N)
                {
                    continue_work = false;
                }
                else
                {
                    if (end_loop > (N / 4))
                    {
                        end_loop = N;
                    }
                    else
                    {
                        end_loop = 4 * end_loop;
                    }
                }
            }
#pragma omp barrier
        }
    }
    //return 0;
}

int main(int argc, char **argv)
{
    const unsigned long long int N = atol(argv[1]);
    const int NThreads = atoi(argv[2]);
    const int dimention = 10;
    omp_set_num_threads(NThreads);
    double timeStart = omp_get_wtime();
    intigration(N, dimention);
    double timeEnd = omp_get_wtime();
    double wallTime = timeEnd - timeStart;
    cout << N << " " << wallTime << " " << omp_get_max_threads() << endl;
    // << "s" << endl;
    return 0;
}