//A simple integration
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double fqn(double x);
double error(double itegral);

int main(int argc, char **argv)
{
    int N = atoi(argv[1]);
    double delx = 0.0, x = 0.0;
    double sum = 0.0;
    double a = -1.0, b = 1.0;
    double intrgration = 0.0;

    //printf("i = %i \n", N);

    delx = 2.0 / (N - 1.0); //Grid

    for (int i = 1; i < N - 1; i++)
    {
        x = -1.0 + (delx * i);
        sum = sum + fqn(x);
    }

    intrgration = (delx / 2.0) * (fqn(a) + 2.0 * sum + fqn(b));
    //printf("%e\n", intrgration);
    double e = error(intrgration);
    printf("%d %e\n", N, e);

    return 0;
}

double error(double integral)
{
    const double pi = 3.141592653589793;
    double absolute_error = fabs(integral - (pi / 2.0));
    return absolute_error;
}

double fqn(double x)
{
    return (1.0 / (1.0 + x * x));
}