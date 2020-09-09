#include "update.hpp"

double *update(int id, int p, int n_global, int n_local, int nsteps,
               double dt, double propagation_constant)
{
    double alpha;                    // stability constant
    double c = propagation_constant; // propagation constant
    double dx;
    int i;
    int i_global;
    int i_global_hi;
    int i_global_lo;
    int i_local;
    int i_local_hi;
    int i_local_lo;
    int ltor = 20;
    int rtol = 10;
    MPI_Status status;
    double t;
    double *u0_local;
    double *u1_local;
    double *u2_local;
    double x;

    /**************************************
   * Calculating the value of alpha *
   ***************************************/
    //c = propagation_constant;
    dx = 1.0 / (double)(n_global - 1);
    alpha = c * dt / dx;

    //check for stability
    if (1.0 <= fabs(alpha))
    {
        if (id == 0)
        {
            cerr << "\n";
            cerr << "------Warning!-----\n";
            cerr << " 1 <= |alpha| = | C * dT / dX |.\n";
            cerr << "C = " << c << "\n";
            cerr << "dT = " << dt << "\n";
            cerr << "dX = " << dx << "\n";
            cerr << "alpha = " << alpha << "\n";
            cerr << "Computation will not be stable!\n";
        }
        MPI_Finalize();
        exit(1);
    }

    i_global_lo = (id * (n_global - 1)) / p;
    i_global_hi = ((id + 1) * (n_global - 1)) / p;
    if (0 < id)
    {
        i_global_lo = i_global_lo - 1;
    }

    i_local_lo = 0;
    i_local_hi = i_global_hi - i_global_lo;

    u0_local = new double[n_local]; //left
    u1_local = new double[n_local]; //middle
    u2_local = new double[n_local]; //right

    t = 0.0;
    for (i_global = i_global_lo; i_global <= i_global_hi; i_global++)
    {
        x = (double)(i_global) / (double)(n_global - 1);
        i_local = i_global - i_global_lo;
        u1_local[i_local] = exact(x, t);
    }

    for (i_local = i_local_lo; i_local <= i_local_hi; i_local++)
    {
        u0_local[i_local] = u1_local[i_local];
    }
    //calculation per timestep
    for (i = 1; i <= nsteps; i++)
    {
        t = dt * (double)i;
        //  For the first time step, we need to use the initial derivative information.
        if (i == 1)
        {
            for (i_local = i_local_lo + 1; i_local < i_local_hi; i_local++)
            {
                i_global = i_global_lo + i_local;
                x = (double)(i_global) / (double)(n_global - 1);
                u2_local[i_local] =
                    +0.5 * alpha * alpha * u1_local[i_local - 1] + (1.0 - alpha * alpha) * u1_local[i_local] + 0.5 * alpha * alpha * u1_local[i_local + 1] + dt * dudt(x, t);
            }
        }
        //  After the first time step, we can use the previous two solution estimates.
        else
        {
            for (i_local = i_local_lo + 1; i_local < i_local_hi; i_local++)
            {
                u2_local[i_local] = alpha * alpha * u1_local[i_local - 1] + 2.0 * (1.0 - alpha * alpha) * u1_local[i_local] + alpha * alpha * u1_local[i_local + 1] - u0_local[i_local];
            }
        }
        //  Exchange data with "left-hand" neighbor.
        if (0 < id)
        {
            MPI_Send(&u2_local[i_local_lo + 1], 1, MPI_DOUBLE, id - 1, rtol,
                     MPI_COMM_WORLD);
            MPI_Recv(&u2_local[i_local_lo], 1, MPI_DOUBLE, id - 1, ltor,
                     MPI_COMM_WORLD, &status);
        }
        else
        {
            x = 0.0;
            u2_local[i_local_lo] = exact(x, t);
        }

        //  Exchange data with "right-hand" neighbor.
        if (id < p - 1)
        {
            MPI_Send(&u2_local[i_local_hi - 1], 1, MPI_DOUBLE, id + 1, ltor,
                     MPI_COMM_WORLD);
            MPI_Recv(&u2_local[i_local_hi], 1, MPI_DOUBLE, id + 1, rtol,
                     MPI_COMM_WORLD, &status);
        }
        else
        {
            x = 1.0;
            u2_local[i_local_hi] = exact(x, t);
        }

        //  Shift data for next time step
        for (i_local = i_local_lo; i_local <= i_local_hi; i_local++)
        {
            u0_local[i_local] = u1_local[i_local];
            u1_local[i_local] = u2_local[i_local];
        }
    }

    //  Free memory.
    delete[] u0_local;
    delete[] u2_local;

    //return the local value for collection
    return u1_local;
}
