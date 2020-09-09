/*******************
 * 10D Monte Carlo
********************/
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <omp.h>

using namespace std;

double integration_fqn(unsigned long long int NumPoint, int dimention);    // main calculation
double error_per_step(double current, double previous);                    //Error calculation
double fqn(double *x, int y);                                              // Lets take a simple fqn: f(x) = x in 10D.           // To check where is the point
double interval_map(double lowerLim, double upperLim, unsigned int *seed); // mapping the interval
double volume(double a, double b, int dim);                                //, double a2, double b2); // function for 2D voulume calculation
double lnLtest(int dimention);
double lnL(int dim);

int main(int argc, char **argv)
{

    int dimention = 10; // In this case 10D intigration

    double y = lnLtest(dimention);
    cout << "For x_i = 2: lnL = " << y << " L = exp(" << y << ")" << endl;

    return 0;
}

/*Bayesian Likelihood Function*/

double lnL(double *x, int dim)
{

    double fqn = 0.0;

    for (int i = 0; i < dim - 1; ++i) //sum 0 to 9
    {
        fqn = fqn + (1.0 - x[i]) * (1.0 - x[i]) + 100. * (x[i + 1] - x[i] * x[i]) * (x[i + 1] - x[i] * x[i]);
    }

    fqn = -fqn;

    return fqn;
}

double lnLtest(int dimention)
{
    double *x;
    double sum = 0.0;
    x = new double[dimention];
    for (int j = 0; j < dimention; ++j)
    {
        x[j] = 2;
    }
    sum = sum + lnL(x, dimention);
    delete[] x;

    return sum;
}
