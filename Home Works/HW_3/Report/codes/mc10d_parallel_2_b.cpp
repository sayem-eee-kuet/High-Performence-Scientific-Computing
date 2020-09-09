/*******************
 * 10D Monte Carlo
********************/
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <omp.h>
#include <chrono>


using namespace std;

double integration_fqn(unsigned long long int NumPoint, int dimention);    // main calculation
double error_per_step(double current, double previous);                    //Error calculation
double fqn(double *x, int y);                                              // Lets take a simple fqn: f(x) = x in 10D.           // To check where is the point
double interval_map(double lowerLim, double upperLim, unsigned int *seed); // mapping the interval
double volume(double a, double b, int dim);                                //, double a2, double b2); // function for 2D voulume calculation

int main(int argc, char **argv)
{
    //double intigral = 0.0;
    //srand(time(NULL));
    //Declearation and Initialization of the variables
    unsigned long long int N = atoll(argv[1]); // Number of Random point
    const int NThreads = 4;                    // atoi(argv[2]);
    int dimention = 10;                        // In this case 10D intigration
    omp_set_num_threads(NThreads);
    integration_fqn(N, dimention);
    // cout << N << " " << piN << " " << error(piN) << endl;
    //cout << N << " " << intigral << endl;
    return 0;
}

double integration_fqn(unsigned long long int NumPoint, int dimention)
{
    unsigned long long int N_attemps = NumPoint; //Total Number of points
    double I = 0.0;                              //Approximate integration
    double a = -1.0;                             //lower bound
    double b = 1.0;                              // upper bound
    //int D = dimention;
    double *x;
    x = new double[dimention];
    double sum = 0.0;
    double sumFinal = 0.0;
    double V = volume(a, b, dimention);
    unsigned long long int check = 4;
    double previous = 0.0;
    unsigned int seed = 0;
    double timeStart = omp_get_wtime();
    //  int counter = 0;

#pragma omp parallel firstprivate(x, sum, check) private(seed)
    {
        const int thread_rank = omp_get_thread_num();
        seed = time(NULL) * (int)(thread_rank + 1);
#pragma omp for
        for (unsigned long long int i = 0; i < N_attemps; ++i)
        {

            for (int j = 0; j < dimention; ++j)
            {
                x[j] = interval_map(a, b, &seed);
            }
            sum = sum + fqn(x, dimention);
#pragma omp critical
            {
                sumFinal = sumFinal + sum;
                if (i == check)
                {
                    double current = V * sum / double(i);
                    double err_per_step = error_per_step(current, previous);
                    previous = current;
                    check = 4 * check;
                    int th = omp_get_thread_num();
                    double timeEnd = omp_get_wtime();
                    double wallTime = timeEnd - timeStart;
                    cout << i << " " << current << " " << err_per_step << " " << th << endl;
                    //cout << i << " " << current << " " << err_per_step << " " << wallTime << endl;
                }
            }
        }
    }

    // double timeEnd = omp_get_wtime();
    // double wallTime = timeEnd - timeStart;
    delete[] x;

    // I = V * sumFinal / (double)N_attemps;
    // cout << N_attemps << " " << I << " " << wallTime << " " << omp_get_max_threads() << endl;
    // // //cout << counter << endl;
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

/*********************************************************
 * ****************f(x) = x in 10D: **********************
 * f(x1,x2....,x10) = 1 + x1 + x2 + x3 +...+ x10 = 2**10 *
**********************************************************/
double fqn(double *x, int dim)
{
    double value = 0.0;
    for (int i = 0; i < dim; ++i)
    {
        value = value + x[i];
    }
    value = 1 + value;
    return value;
}

double volume(double a, double b, int dim) //, double a2, double b2)
{
    int length = b - a;
    /*************
     * V = L**dim
    **************/
    return std::pow(length, dim);
}

double error_per_step(double a, double b)
{
    // const double pi = 3.141592653589793;
    // double absolute_error = fabs(piN - pi);
    // return absolute_error;
    return fabs(a - b);
}
