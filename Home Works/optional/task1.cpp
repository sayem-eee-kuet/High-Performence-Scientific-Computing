#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>

using namespace std;
using INT = unsigned long long int;

bool isSquare(INT N )
{
   INT r = sqrt( 0.5 + N );  // Deliberate use of truncation
   return r * r == N;
}



int main(int argc, char **argv)
{
    // long int N0 = 0;
    // long int N1 = 1;
    // //cout << N0 << endl;
    // cout << N1 << endl;

    // for (int i = 1; i < 10; ++i)
    // {
    //     long int N2 = 34*N1 - N0 + 2;
    //     cout << N2 << endl;
    //     N0 = N1;
    //     N1 = N2;
    // }
    INT sum = 0;
    //INT out = 0;

    for (INT i = 1; i < 100000000; ++i){
        sum += i;
        //cout << sum << endl;
        if (isSquare(sum) == true)
        {
            cout << sum << endl;
        }
    }


    return 0;
}