#include "Process.hpp"
#include "Scheduler.hpp"
#include "ArrayList.hpp"
#include "simulate.hpp"
#include <iostream>


int main()
{
  RoundRobin myRob = RoundRobin();
  //Simulate newSim;
  double* regResults = simulate(&myRob, 100, 100, 300);

  FastRoundRobin fastRob = FastRoundRobin();
  double* fastResults = simulate(&fastRob, 100, 100, 300);



  //make sure we deallocate the results arrayt when done
  
  
}
