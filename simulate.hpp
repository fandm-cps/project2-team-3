#ifndef SIMULATE
#define SIMULATE
#include "Scheduler.hpp"
#include "ArrayList.hpp"
#include "Process.hpp"

double* simulate(Scheduler* sched, int numCPUBound, int numIOBound, int numCycles);

#endif