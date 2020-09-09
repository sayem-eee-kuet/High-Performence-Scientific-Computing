#include <omp.h>
#include <stdio.h>

int main()
{
    int NumThread = 10;
    omp_set_num_threads(NumThread);

    #pragma omp parallel
    {
        printf("Hello from the thread %d\n", omp_get_thread_num());
    }
    return 0;
}
