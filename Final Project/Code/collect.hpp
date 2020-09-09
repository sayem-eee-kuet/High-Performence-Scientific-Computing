#ifndef COLLECT_H_INCLUDED
#define COLLECT_H_INCLUDED

#include <cmath>
#include <cstdlib>
#include <mpi.h>

#include "update.hpp"
//#include "collect.hpp"
#include "exact.hpp"
#include "dudt.hpp"

using namespace std;

void collect(int id, int p, int n_global, int n_local, int nsteps,
             double dt, double u_local[]);

#endif