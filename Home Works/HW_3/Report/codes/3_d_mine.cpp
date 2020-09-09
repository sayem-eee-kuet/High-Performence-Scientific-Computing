double integration_fqn(unsigned long long int NumPoint, int dimention)
{
    unsigned long long int N_attemps = NumPoint; //Total Number of points
    //double I = 0.0;                              //Approximate integration
    double a = -0.5; //lower bound
    double b = 0.5;  // upper bound
    //int D = dimention;
    double *x;
    x = new double[dimention];
    double sum = 0.0;
    double sumFinal = 0.0;
    double V = volume(a, b, dimention);
    unsigned long long int check = 4;
    double previous = 0.0;
    unsigned int seed = 0;
    double timeStart = omp_get_wtime();
    //  int counter = 0;

#pragma omp parallel firstprivate(x) private(seed)
    {
        const int thread_rank = omp_get_thread_num();
        seed = time(NULL) * (int)(thread_rank + 1);
#pragma omp for reduction(+ \
                          : sum)
        for (unsigned long long int i = 0; i < N_attemps; ++i)
        {

            for (int j = 0; j < dimention; ++j)
            {
                x[j] = interval_map(a, b, &seed);
            }
            //#pragma omp atomic
            sum += L(x, dimention);
#pragma omp atomic
            sumFinal = sumFinal + sum;
//#pragma omp barrier
#pragma omp critical
            {
                if (i == check)
                {
                    double current = V * sumFinal / double(i);
                    double err_per_step = error_per_step(current, previous);
                    double absErr = absError(current);
                    previous = current;
                    check = 4 * check;
                    int th = omp_get_thread_num();
                    // double timeEnd = omp_get_wtime();
                    // double wallTime = timeEnd - timeStart;
                    cout << i << " " << current << " " << absErr << endl;
                    // << " " << th << endl;
                    //cout << i << " " << current << " " << err_per_step << " " << wallTime << endl;
                }
            }
        }
    }

    delete[] x;

    double timeEnd = omp_get_wtime();
    double wallTime = timeEnd - timeStart;
    cout << "Total wallTime: " << wallTime << " "
         << "s" << endl;

    return 0;
}

double interval_map(double lowerLim, double upperLim, unsigned int *seed)
{
    /**************************************************************
     * Mapping the [0,1]=>[lowerLim, upperLim]
     * f(x) = mx + c, f(0) = lowerLim and f(1) = upperLim
     * Solving this we get, f(x) = (upperLim-lowerLim)x + lowerLim
    ***************************************************************/
    // double upperLim = b;
    // double lowerLim = a;
    double randomNumber = ((double)rand_r(seed)) / ((double)RAND_MAX);
    return ((upperLim - lowerLim) * randomNumber + lowerLim);
}
