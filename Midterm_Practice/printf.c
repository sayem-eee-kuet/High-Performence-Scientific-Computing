#include <stdio.h>

int main()
{
    int N = 5;

    for (int i = 0; i < N; ++i)
    {
        printf("%e\n", (double)i);
    }

    return 0;
}