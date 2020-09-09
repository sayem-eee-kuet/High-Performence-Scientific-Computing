// compute
//
//           \int_{-1}^1 1 / (1+x^2) dx
//
// with the extended trapezoidal rule
#include <stdio.h>
#include <stdlib.h> // needed to use the function atoi
#include <math.h>

double error(double integral);

int main(int argc, char **argv)
{

  unsigned long long int N = atoll(argv[1]); // convert command-line input to N = number of points
  //printf("N = %i\n",N);
  double dx = 2.0 / (N - 1); // \delta x spacing when interval is [-1,1]
  double integral = 0.0;

  for (unsigned long long int i = 0; i < N; ++i)
  {
    double x = -1. + dx * i;      // compute x_i
    double f = 1. / (1. + x * x); // compute f_i = f(x_i)

    // easy to code, but its generally better to aviod if statements
    // inside of a for-loop (slows down the code)
    if (i == 0 || i == N - 1)
    {                                     // end points of trapezoidal rule treated specially
      integral = integral + 0.5 * dx * f; // or integral += 0.5*dx*f;
    }
    else
    {
      integral = integral + dx * f;
    }
    //integral += dx*f; // sneaky bug: will give first-order convergence
  }

  double err = error(integral);
  //printf("%i %1.16lf\n",N, integral);
  printf("%lli %1.2e\n", N, err);
  return 0;
}

double error(double integral)
{
  const double pi = 3.141592653589793;
  double absolute_error = fabs(integral - pi / 2.);
  return absolute_error;
}
