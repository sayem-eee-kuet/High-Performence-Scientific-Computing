#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
//#include <mpi.h>

void sample_rand(const double a, const double b, const int dim, double *x);
double f(double *x);

int main(int argc, char **argv)
{

    long N = atol(argv[1]);
    srand(time(NULL));

    const int dim = 2;
    double x[dim];
    double max = -1;

    for (long int i = 1; i <= N; ++i)
    {
        sample_rand(-5.0, 5.0, dim, x);
        double f_i = f(x);
        if (f_i > max)
        {
            max = f_i;
        }
    }

    //printf("Local max = %1.5e\n", max);
    printf("%f", max);
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