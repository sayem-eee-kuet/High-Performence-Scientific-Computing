#include <chrono>
int main(int argc, char **argv)
{
    double piN;
    srand(time(NULL));
    //Declearation and Initialization of the variables
    long int N = atol(argv[1]); // Number of Random point
    auto t_start = std::chrono::high_resolution_clock::now();
    piN = mcpi(N);
    auto t_end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> duration = (t_end - t_start);
    cout << N << " " << duration.count() << " " << error(piN) << endl;
    return 0;
}
