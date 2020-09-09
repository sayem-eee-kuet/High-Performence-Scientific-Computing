#include <iostream>
#include <cmath>
#include <iomanip>
#include <omp.h>

using namespace std;

int main(int argc, char **argv)
{
    const int NThreads = 4;
    omp_set_num_threads(NThreads);

    int count = 0;

#pragma omp parallel for //private(count)
    for (int i = 0; i < 1000; ++i)
    {
#pragma omp atomic
        count++;
    }

    cout << count << endl;

    return 0;
}