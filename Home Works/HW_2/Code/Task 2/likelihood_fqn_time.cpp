#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>

using namespace std;

double integration_fqn(long int NumPoint);                 // main calculation
double error(double itegral);                              //Error calculation
double likelihood_fqn(double x, double y);                 // To check where is the point
double interval_map(double a, double b);                   // mapping the interval
double volume(double a1, double b1, double a2, double b2); // function for 2D voulume calculation

int main(int argc, char **argv)
{
    double intigral;
    srand(time(NULL));
    //Declearation and Initialization of the variables
    long int N = atol(argv[1]); // Number of Random point
    intigral = integration_fqn(N);
    // cout << N << " " << piN << " " << error(piN) << endl;
    //cout << N << " " << intigral << " " << log(intigral) << endl;
    return 0;
}

double integration_fqn(long int NumPoint)
{
    long int N_attemps = NumPoint; //Total Number of points
    double I = 0.0;                //Approximate integration
    double a = -5.0;               //lower bound
    double b = 5.0;                // upper bound
    double N_hits = 0.0;

    for (long int i = 0; i < N_attemps; i++)
    {
        double x = interval_map(a, b);
        double y = interval_map(a, b);
        N_hits = N_hits + likelihood_fqn(x, y);
    }

    double v = volume(-5.0, 5.0, -5.0, 5.0);

    I = v * (N_hits / (double)N_attemps);

    // cout << N_attemps << " " << pi << " " << error(pi) << endl;
    return I;
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

double likelihood_fqn(double x, double y)
{
    return exp(-(pow((1.00 - x), 2.00)) - 100.00 * (pow((y - pow(x, 2.00)), 2.00)));
}

double volume(double a1, double b1, double a2, double b2)
{
    return (b1 - a1) * (b2 - a2);
}

double error(double piN)
{
    const double pi = 3.141592653589793;
    double absolute_error = fabs(piN - pi);
    return absolute_error;
}
