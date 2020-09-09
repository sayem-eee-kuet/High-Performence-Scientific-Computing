#include <iostream>
#include <cmath>
#include <iomanip>
#include <omp.h>

using namespace std;

int main(int argc, char **argv)
{
    const int NThreads = 4;
    omp_set_num_threads(NThreads);
    unsigned long int N = atoi(argv[1]);

    double x;
    double dx = 0.1;
    double *y;
    y = new double[N];

#pragma omp parallel
    {
#pragma omp for //private(x)
        for (unsigned long int i = 0; i < N; ++i)
        {
            double x = i * dx;
            y[i] = sin(x) * cos(x) * sqrt(6 * x + 5);
        }
    }
    for (unsigned long int i = 0; i < N; ++i)
    {
        double x = double(i) * dx;
        cout << x << " " << y[i] << endl;
    }

    delete[] y;

    return 0;
}