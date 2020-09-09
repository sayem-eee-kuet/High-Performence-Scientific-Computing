#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>

double g(double x);
double h(double x);

int main(int argc, char **argv)
{
    std::cout.precision(11);
    std::cout << std::fixed;

    //int x = atoi(argv[1]);
    double x = atof(argv[1]);
    //int y = (int)x;

    double f = 0.0;
    f = g(x) + h(x);
    std::cout << "f(" << x << ") = " << f << std::endl;

    return 0;
}

double g(double x)
{
    return sin(x);
}

double h(double x)
{
    return cos(x);
}