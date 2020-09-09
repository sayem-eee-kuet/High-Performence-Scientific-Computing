#include "exact.hpp"

double exact(double x, double t)

/****************************************
 * Input:  double x - Location
 *         double t - time
 * Output: double exact - 
 *         the real solution
 * **************************************/
{
    const double c = 1.0;
    const double pi = 3.141592653589793;
    double value;

    value = sin(2.0 * pi * (x - c * t));

    return value;
}