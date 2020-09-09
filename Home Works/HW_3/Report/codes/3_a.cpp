
double integration_fqn(unsigned long long int NumPoint, int dimention)
{
    unsigned long long int N_attemps = NumPoint; //Total Number of points
    double I = 0.0;                              //Approximate integration
    double a = -0.5;                             //lower bound
    double b = 0.5;                              // upper bound
    //int D = dimention;
    double *x;
    x = new double[dimention];
    double sum = 0.0;
    double sumFinal = 0.0;
    double V = volume(a, b, dimention);
    //unsigned long long int check = 4;
    //double previous = 0.0;
    unsigned int seed = 0;
    double timeStart = omp_get_wtime();

#pragma omp parallel firstprivate(x, sum) private(seed)
    {
        //double sum = 0.0;
        const int thread_rank = omp_get_thread_num();
        seed = time(NULL) * (int)(thread_rank+1);
        //cout << "Thread " << thread_rank << " reporting for work<< endl;
        // printf("Thread %i is reporting for work \n", thread_rank);

#pragma omp for
        for (unsigned long long int i = 0; i < N_attemps; ++i)
        {

            interval_map(a, b, dimention, &seed, x);
            sum = sum + L(x, dimention);
        }
#pragma omp atomic
        sumFinal = sumFinal + sum;
    }

    double timeEnd = omp_get_wtime();
    double wallTime = timeEnd - timeStart;
    delete[] x;

    I = V * sumFinal / (double)N_attemps;
    //I = exp(I);
    cout << N_attemps << " " << I << " " << wallTime << " " << omp_get_max_threads() << endl;

    return 0;
}

void interval_map(const double a, const double b, const int dim, unsigned int *seed, double *x)
{

    for (int i = 0; i < dim; ++i)
    {
        double random = ((double)rand_r(seed)) / ((double)RAND_MAX);
        random = (b - a) * random + a;
        x[i] = random;
    }

}
    
