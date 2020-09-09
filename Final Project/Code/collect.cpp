#include "collect.hpp"

/*************************************************
 * Input:
 *      id   = ID of the process
 *      p    = Number of process
 *  n_global = Total number of points
 *  n_local  = Number of point for each process
 *  nsteps   = number of time steps
 *    dt     = size of the time step
 *  u_local[n_local] = soution by each process
 * ************************************************/

void collect(int id, int p, int n_global, int n_local, int nsteps,
             double dt, double u_local[])
{
    int buffer[2];
    int collect1 = 10;
    int collect2 = 20;
    int i;
    int i_global;
    int i_global_hi;
    int i_global_lo;
    int i_local;
    int i_local_hi;
    int i_local_lo;
    int n_local2;
    MPI_Status status;
    double t;
    double *u_global;
    double x;

    i_global_lo = (id * (n_global - 1)) / p;
    i_global_hi = ((id + 1) * (n_global - 1)) / p;
    if (0 < id)
    {
        i_global_lo = i_global_lo - 1;
    }

    i_local_lo = 0;
    i_local_hi = i_global_hi - i_global_lo;

    //  Master collects worker results into the u_global array
    if (id == 0)
    {
        //
        //  Create the global array.
        //
        u_global = new double[n_global];
        //
        //  Copy the master's results into the global array.
        //
        for (i_local = i_local_lo; i_local <= i_local_hi; i_local++)
        {
            i_global = i_global_lo + i_local - i_local_lo;
            u_global[i_global] = u_local[i_local];
        }
        //
        //  Contact each worker.
        //
        for (i = 1; i < p; i++)
        {
            //
            //  Message "collect1" contains the global index and number of values.
            //
            MPI_Recv(buffer, 2, MPI_INT, i, collect1, MPI_COMM_WORLD, &status);

            i_global_lo = buffer[0];
            n_local2 = buffer[1];

            if (i_global_lo < 0)
            {
                cerr << "  Illegal I_GLOBAL_LO = " << i_global_lo << "\n";
                exit(1);
            }
            else if (n_global <= i_global_lo + n_local2 - 1)
            {
                cerr << "  Illegal I_GLOBAL_LO + N_LOCAL2 = "
                     << i_global_lo + n_local2 << "\n";
                exit(1);
            }
            //
            //  Message "collect2" contains the values.
            //
            MPI_Recv(&u_global[i_global_lo], n_local2, MPI_DOUBLE, i, collect2,
                     MPI_COMM_WORLD, &status);
        }
        //  Print the results.
        t = dt * (double)nsteps;
        for (i_global = 0; i_global < n_global; i_global++)
        {
            x = (double)(i_global) / (double)(n_global - 1);
            cout << i_global << " " << setprecision(3) << x << " " << setprecision(3) << u_global[i_global] << " " << setprecision(3) << exact(x, t) << "\n";
        }

        delete[] u_global;
    }
    //
    //  Workers send results to process 0.
    //
    else
    {
        //
        //  Message "collect1" contains the global index and number of values.
        //
        buffer[0] = i_global_lo;
        buffer[1] = n_local;
        MPI_Send(buffer, 2, MPI_INT, 0, collect1, MPI_COMM_WORLD);
        //
        //  Message "collect2" contains the values.
        //
        MPI_Send(u_local, n_local, MPI_DOUBLE, 0, collect2, MPI_COMM_WORLD);
    }

    return;
}