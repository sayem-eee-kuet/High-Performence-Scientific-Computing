#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char **argv)
{
    FILE *fp;

    fp = fopen("rand.dat", "w+");
    //fprintf(fp, "This is testing for fprintf...\n");
    //fputs("This is testing for fputs...\n", fp);

    srand(time(NULL));

    int N = atoi(argv[1]);
    for (int i = 0; i < N; ++i)
    {
        int rand_int = rand();

        double x = ((double)rand_int / (double)RAND_MAX);

        fprintf(fp, "%lf\n", x);
    }

    fclose(fp);

    return 0;
}