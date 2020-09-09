/*******************
 * 10D Monte Carlo
********************/
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>

using namespace std;

double integration_fqn(unsigned long long int NumPoint, int dimention, unsigned long long int &itr, double &err, double &I); // main calculation
double error_per_step(double current, double previous);                                                                      //Error calculation
double fqn(double *x, int y);                                                                                                // Lets take a simple fqn: f(x) = x in 10D.           // To check where is the point
double interval_map(double lowerLim, double upperLim);                                                                       // mapping the interval
double volume(double a, double b, int dim);
double fqn(double *x, int dim);
// unsigned long long int Iteration = 0;
// double step_by_step_error = 0.0;

int main(int argc, char **argv)
{
    //double intigral = 0.0;
    srand(time(NULL));
    unsigned long long int Iteration = 0;
    double step_by_step_error = 0.0;
    //Declearation and Initialization of the variables
    unsigned long long int N = atoll(argv[1]); // Number of Random point
    int dimention = 10;
    double Int = 0.0; 
    //intigral = integration_fqn(N, dimention);
    integration_fqn(N, dimention, Iteration, step_by_step_error, Int);
    // cout << N << " " << piN << " " << error(piN) << endl;
    //cout << Iteration << " " << Int <<" "<< step_by_step_error << endl;
    return 0;
}

double integration_fqn(unsigned long long int NumPoint, int dimention, unsigned long long int &itr, double &err, double &I)
{
    unsigned long long int N_attemps = NumPoint; //Total Number of points
    //double I = 0.0;   //Approximate integration
    double a = -5.0; //lower bound
    double b = 5.0;  // upper bound
    //int D = dimention;
    double *x;
    x = new double[dimention];
    double sum = 0.0;
    double V = volume(a, b, dimention);
    unsigned long long int check = 4;
    double previous = 0.0;

    for (unsigned long long int i = 0; i < N_attemps; ++i)
    {
        for (int j = 0; j < dimention; ++j)
        {
            x[j] = interval_map(a, b);
        }
        //double value = fqn(x, dimention);
        sum = sum + fqn(x, dimention);
        if (i == check)
        {
            double current = V * sum / double(i);
            double err_per_step = error_per_step(current, previous);
            previous = current;
            check = 4 * check;
            itr = i;
            err = err_per_step;
            I = current;
            /*************************
             * Its a bad practice :(
            **************************/
            cout << itr << " " << I << " " << err << endl;
        }
    }

    delete[] x;
    return 0;
}

double interval_map(double lowerLim, double upperLim)
{
    /**************************************************************
     * Mapping the [0,1]=>[lowerLim, upperLim]
     * f(x) = mx + c, f(0) = lowerLim and f(1) = upperLim
     * Solving this we get, f(x) = (upperLim-lowerLim)x + lowerLim
    ***************************************************************/
    // double upperLim = b;
    // double lowerLim = a;
    double randomNumber = ((double)rand()) / ((double)RAND_MAX);
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
