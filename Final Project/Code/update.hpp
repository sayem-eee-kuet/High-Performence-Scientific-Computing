#ifndef UPDATE_H_INCLUDED
#define UPDATE_H_INCLUDED

#include <cmath>
#include <cstdlib>
#include <mpi.h>
#include <iomanip>
#include <iostream>

//#include "update.hpp"
// #include "collect.hpp"
#include "exact.hpp"
#include "dudt.hpp"

using namespace std;

double *update(int id, int p, int n_global, int n_local, int nsteps,
               double dt, double propagation_constant);

#endif