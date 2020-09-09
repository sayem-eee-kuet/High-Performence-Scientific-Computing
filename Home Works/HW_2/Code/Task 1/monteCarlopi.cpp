#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>

using namespace std;

double mcpi(long int NumPoint);          // main calculation
double error(double itegral);            //Error calculation
int indicator_fqn(double x, double y);   // To check where is the point
double interval_map(double a, double b); // mapping the interval

int main(int argc, char **argv)
{
    double piN;
    srand(time(NULL));
    //Declearation and Initialization of the variables
    long int N = atol(argv[1]); // Number of Random point
    piN = mcpi(N);
    // cout << N << " " << piN << " " << error(piN) << endl;
    cout << N << " " << error(piN) << endl;
    return 0;
}

double mcpi(long int NumPoint)
{
    long int N_attemps = NumPoint; //Total Number of points
    double pi = 0.0;               //Approximate integration
    double a = -1.0;               //lower bound
    double b = 1.0;                // upper bound
    long int N_hits = 0.0;

    for (long int i = 0; i < N_attemps; i++)
    {
        double x = interval_map(a, b);
        double y = interval_map(a, b);
        N_hits = N_hits + indicator_fqn(x, y);
    }

    //cout << N_hits << endl;

    /*******************************
     *      pi = 4 * (Nhits/N)
    *******************************/
    pi = 4 * (N_hits / (double)N_attemps);
    // cout << N_attemps << " " << pi << " " << error(pi) << endl;
    return pi;
}

double interval_map(double a, double b)
{
    /*****************************************************
     * Mapping the [0,1]=>[lowerLim, upperLim]
     * f(x) = mx + c, f(0) = lowerLim and f(1) = upperLim
     * Solving this we get, f(x) = (upperLim-lowerLim)x + lowerLim
    ******************************************************/
    double upperLim = b;
    double lowerLim = a;
    double randomNumber = ((double)rand()) / ((double)RAND_MAX);
    return ((upperLim - lowerLim) * randomNumber + lowerLim);
}

int indicator_fqn(double x, double y)
{
    /*****************************
     * For MC pi, x^2 + y^2 <= 1
    ******************************/
    if (x * x + y * y <= 1.0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

double error(double piN)
{
    const double pi = 3.141592653589793;
    double absolute_error = fabs(piN - pi);
    return absolute_error;
}
