#include <stdio.h>
#include <stdlib.h> // needed to use the function atoi
#include <math.h>
#include <omp.h>

double error(double integral);

int main(int argc, char **argv)
{
  omp_set_num_threads(4);
  unsigned long long int N = atoll(argv[1]);
  double dx = 2.0 / (N - 1);
  double integral = 0.0;
  double x = 0.0;
  double f = 0.0;
  double integral_thread[4] = {0};

#pragma omp parallel private(x, f)
  {
    int id = omp_get_thread_num();
#pragma omp for
    for (long long int i = 0; i < N; ++i)
    {
      x = -1 + dx * i;
      f = 1.0 / (1.0 + x * x);
      if (i == 0 || i == N - 1)
      {
        integral_thread[id] = integral_thread[id] + 0.5 * dx * f;
      }
      else
      {
        integral_thread[id] = integral_thread[id] + dx * f;
      }
    }
  }
  //each thread will contribute its portion to the total integral
  //double integral = 0.0;
  for (int i = 0; i < 4; i++)
  {
    integral = integral + integral_thread[i];
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