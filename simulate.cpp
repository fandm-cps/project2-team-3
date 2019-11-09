#include <chrono>
#include "simulate.hpp"
#include "ArrayList.hpp"
#include "Process.hpp"
#include <iostream>

using namespace std;

double* simulate(Scheduler* sched, int numCPUBound, int numIOBound, int numCycles)
{
  
  ArrayList<Process*> *cpuBound = new ArrayList<Process*>();
  for (int i = 0; i < numCPUBound; i++){
    CPUBoundProcess* newCPU = new CPUBoundProcess(i);
    cpuBound->pushBack(newCPU);
    sched->addProcess(newCPU);
  }

  ArrayList<IOBoundProcess*>* ioBound = new ArrayList<IOBoundProcess*>();
  for (int i = 0; i < numIOBound; i++){
    IOBoundProcess* newIO = new IOBoundProcess(i);
    ioBound->pushBack(newIO);
    sched->addProcess(ioBound->getItem(i));
  }

  Process* next;
  int simCycles = 0;
  double accSched = 0;
  int cyclesConsumed;

  //start the timer
  auto start = std::chrono::system_clock::now();
  while (simCycles < numCycles){
    accSched += 1;
    
    next = sched->popNext(simCycles); //Get the next process from the schedule
      
    if (next == 0){     //If the scheduler returns a null pointer
	    simCycles += 10;  //just increment the cycle number by 10
	  }
    else{
      cyclesConsumed = next->useCPU(simCycles, 10); //the number of cycles used by the process
      simCycles = simCycles + cyclesConsumed; // Add that to the number of simulated cycles so far.
      sched->addProcess(next);  //Add the process back into the scheduler
    }
      
  }
  
  auto end = std::chrono::system_clock::now();  //end the timer
  auto dur = end - start; //get the duration
  auto durNS = chrono::duration_cast<chrono::nanoseconds>(dur); //get the nanosecond
  double elapsed = durNS.count(); //get the number of ticks
  
  double* retArr = new double[5]; //allocate and fill a 5 element array

  //The number of actual nanoseconds the simulation took divided by the number
  //of times you used the scheduler. This gives a sense of how much overhead
  //the scheduler causes on each insertion/removal of a process from the
  //data structure
  retArr[0] = elapsed / accSched; //insert into first spot in array
  
  //The average CPU time of all CPU-bound processes
  //(using the getCPUTime method)
  int cpuSize = cpuBound->getSize();
  double avgCPU = 0;
  double avgCPUWait = 0;
  double totalCPU = 0;
  double totalCPUWait = 0;
  for (int i = 0; i < cpuSize; i++)
    {
      Process* currentCPU = cpuBound->getItem(i);
      totalCPU = totalCPU + currentCPU->getCPUTime();
      totalCPUWait = totalCPUWait + currentCPU->getWaitTime(i);
    }
  avgCPU = totalCPU / cpuSize;
  avgCPUWait = totalCPUWait / cpuSize;
  //return to the second spot in the array
  retArr[1] = avgCPU;
  retArr[2] = avgCPUWait;
  //done #2 & #3

  //The average CPU time of all I/O-bound processes
  int ioSize = ioBound->getSize();
  double avgIO = 0;
  double avgIOWait = 0;
  double totalIO = 0;
  double totalIOWait = 0;
  for (int i = 0; i < ioSize; i++)
    {
      Process* currentIO = ioBound->getItem(i);
      totalIO = totalIO + currentIO->getCPUTime();
      totalIOWait = totalIOWait + currentIO->getWaitTime(i);
    }
  avgIO = totalCPU / cpuSize;
  avgIOWait = totalIOWait / ioSize;
  //return to the second spot in the array
  retArr[3] = avgIO;
  retArr[4] = avgIOWait;
  //done #4 & #5

  for (int k = 0; k < numCPUBound; k++){ delete cpuBound->getItem(k); }
  for (int l = 0; l < numIOBound; l++){ delete ioBound->getItem(l); }

  return retArr;
}