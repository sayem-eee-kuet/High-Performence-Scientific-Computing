#include "dudt.hpp"

#include <cmath>
#include <cstdlib>
#include <iomanip>
#include <iostream>

/****************************************
 * Input:  double x - Location
 *         double t - time
 * Output: double du(x)dt - 
 *         value of the time derivative
 * **************************************/ 

double dudt(double x, double t)
{
    const double c = 1.0;
    const double pi = 3.141592653589793;
    double value;

    value = -2.0 * pi * c * cos(2.0 * pi * (x - c * t));

    return value;
}