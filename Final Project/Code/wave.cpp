#include "update.hpp"
#include "collect.hpp"
#include "exact.hpp"
#include "dudt.hpp"
//#include <mpi.h>
#include <chrono>
#include <ctime>

using namespace std;
/******************************************************************************
 * The wave equation in 1-D :
 *     d^2 u/dt^2 - c^2 * d^2 u/dx^2 = 0  for 0 < x < 1, 0 < t
 * Initial Conditions:
 *     u(x=x,t=0) = g(x,t=0) = sin[2*pi*(x-c*t)] = sin(2*pi*x)
 *    u'(x=x,t=0) = h(x,t=0) = - 2*pi*c*cos[2*pi*x]
 * Boundary Condition:
 *      u(x=0,t) = u0(t) = sin(2*pi*(0-c*t)) = sin(-2*pi*c*t)
 *      u(x=1,t) = u1(t) = sin(2*pi*(1-c*t))
 * Let, the alpha = c*du/dt, for stablity: alpha <= c*dt/dx
 * Using the Finite Difference Method, we can write:
 *    U(x,t+dt) = 2 U(x,t) - U(x,t-dt) 
 *                + alpha^2[U(x-dx,t)-2U(x,t)+U(x+dx,t)]
 * 
 * 
 * Role of the functions:
 *   1. update.hpp : for each time step calculate the u(x,t) and update the local array
 *                   also check the stabilty condition.
 *   2. collect.hpp: collect all data from the all local arrays
 *   3. exact.hpp  : calculate the exact solution and IC and BC
 *   4. dudt.hpp   : calculate the derivative of the function u(x,t)  
 * ***************************************************************************************/

int main(int argc, char *argv[])
{
  double dt = 0.00125; //time step
  int i_global_hi;
  int i_global_lo;
  int id;             //the MPI process ID
  int n_global = 901; //the total number of points
  int n_local;        //number of total point per process
  int nsteps = 4000;  //the number of time steps
  int p;              //the number of MPI processes
  double *u1_local;
  double propagation_constant = atof(argv[1]);
  double s_time, e_time, time;
  s_time = MPI_Wtime(); 
  auto start = std::chrono::system_clock::now();
  /******Initialize MPI********/

  MPI_Init(&argc, &argv);

  MPI_Comm_rank(MPI_COMM_WORLD, &id);

  MPI_Comm_size(MPI_COMM_WORLD, &p);

  /*********Determine N_LOCAL************
   *        Domain decomposition        *
   * ************************************/
  i_global_lo = (id * (n_global - 1)) / p;
  i_global_hi = ((id + 1) * (n_global - 1)) / p;
  if (0 < id)
  {
    i_global_lo = i_global_lo - 1;
  }

  n_local = i_global_hi + 1 - i_global_lo;
  //calculation
  u1_local = update(id, p, n_global, n_local, nsteps, dt, propagation_constant);
  //collect from all process
  collect(id, p, n_global, n_local, nsteps, dt, u1_local);
  //MPI_Barrier(MPI_COMM_WORLD); 
 
  MPI_Finalize();
  
  // e_time = MPI_Wtime();
  // time = e_time - s_time;
   if(id == 0)
  {
  // auto end = std::chrono::system_clock::now();
  // std::chrono::duration<double> elapsed_seconds = end-start;
  // std::time_t end_time = std::chrono::system_clock::to_time_t(end);
  // std::cout << elapsed_seconds.count() << std::endl;
  e_time = MPI_Wtime();
  time = e_time - s_time;
  cout << time << endl;
  }
  
  delete[] u1_local;

  return 0;
}
