#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>

using namespace std;

int main(int argc, char **argv)
{
    int N = atoi(argv[1]);
    double I_0 = 0.01;
    for (int i = 1; i <= N; ++i)
    {
        cout << i << ", " << I_0 << endl;
        I_0 = I_0 * 2;
        //I_0 = I;
    }
    return 0;
}