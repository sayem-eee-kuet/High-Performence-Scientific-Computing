#include <iostream>
#include <cmath>
#include <iomanip> 

using namespace std;

int main(int argc, char **argv)
{
    unsigned int runScored = atol(argv[1]);
    unsigned int runAllowed = atoi(argv[2]);
    double a = pow((double)runScored, 1.8);
    double b = pow((double)runAllowed, 1.8) + a;
    double W = a/b;
    cout.precision(3);
    cout<< std::fixed;
    
    cout <<"W " << W << endl;

return 0;

}