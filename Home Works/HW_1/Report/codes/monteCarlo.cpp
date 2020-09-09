#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>

using namespace std;

double fqn(double x);         // function declearation
double error(double itegral); //Error calculation

int main(int argc, char **argv)
{

    //Declearation and Initialization of the variables
    int N = atoi(argv[1]); // Number of mesh
    double I_1 = 0.0;      //Approximate integration
    double a = -1.0;       //lower bound
    double b = 1.0;        // upper bound
    double V = b - a;      // volume of the intergral

    srand(time(NULL));

    for (int i = 0; i < N; i++)
    {
        int randNum = rand();
        double x = ((double)randNum / (double)RAND_MAX);
        cout << x << endl;
        I_1 = I_1 + fqn(x);
    }

    //Computitation
    I_1 = V * (1.0 / N) * I_1;
    //cout << "Value of Integration = " << I_1 << endl;
    cout << N << " " << error(I_1) << endl;
    return 0;
}

double fqn(double x)
{

    return (1.00) / (1 + x * x);
}

double error(double itegral)
{
    const double pi = 3.141592653589793;
    double absolute_error = fabs(itegral - (pi / 2.0));
    return absolute_error;
}
