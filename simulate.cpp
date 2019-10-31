#include <chrono>
#include "simulate.hpp"
#include "ArrayList.hpp"
#include "Process.hpp"
#include <iostream>

using namespace std;

double* simulate(Scheduler* sched, int numCPUBound, int numIOBound, int numCycles)
{
  ArrayList<CPUBoundProcess*>* cpuBound = new ArrayList<CPUBoundProcess*>;
  for (int i = 0; i < numCPUBound; i++)
    {
      CPUBoundProcess* newCPU = new CPUBoundProcess(i);
      cpuBound->pushBack(newCPU);
      //sched->addProcess(cpuBound->getItem(i));
      sched->addProcess(cpuBound->getItem(i));
      delete newCPU;
    }
  //destructor
  //newCPU->~CPUBoundProcess();

  ArrayList<IOBoundProcess*>* ioBound = new ArrayList<IOBoundProcess*>;
  for (int i = 0; i < numIOBound; i++)
    {
      IOBoundProcess* newIO = new IOBoundProcess(i);
      ioBound->pushBack(newIO);
      //sched->addProcess(ioBound->getItem(i));
      sched->addProcess(ioBound->getItem(i));
      delete newIO;
    }
  //destructor
  //newIO->~IOBoundProcess();

  Process* next;
  int simCycles = 0;
  double accSched = 0;
  int cyclesConsumed;

  //start the timer
  auto start = std::chrono::system_clock::now();
  while (simCycles < numCycles)
    {
      cout << "simCycle#: " << simCycles << endl;
      cout << "numCycles#: " << numCycles << endl;
      cout << "in while" << endl;
      //Process* xyz;
      
      
      //Get the next process from the schedule
      next = sched->popNext(simCycles);
      bool myB = false;
      if (next == 0)
	{
	  myB = true;
	}
      cout << "is next = null??" << myB << endl;
      cout << "heeeere" << endl;
      //If the scheduler returns a null pointer
      if (next == 0)
	{
	  //just increment the cycle number by 10
	  simCycles += 10;
	}
      else{
	//Call the process' useCPU method with the current cycle number
	//and slice size of 10
	cyclesConsumed = next->useCPU(simCycles, 10);
	//The useCPU method returns the number of cycles used by the process
	//(which may not bethe entire slice).
	//Add that to the number of simulated cycles so far
	simCycles = simCycles + cyclesConsumed;
	//Add the process back into the scheduler
	sched->addProcess(next);
      }
      
      
    }
  //end the timer
  auto end = std::chrono::system_clock::now();
  //get the duration
  auto dur = start - end;
  //get the nanosecond
  auto  durNS = chrono::duration_cast<chrono::nanoseconds>(dur);
  //double doubleDurNS = 
  //get the number of ticks
  int elapsed = durNS.count();
  //When the simulation is over, allocate and fill a 5 element array
  
  double* retArr = new double[5];

  //The number of actual nanoseconds the simulation took divided by the number
  //of times you used the scheduler. This gives a sense of how much overhead
  //the scheduler causes on each insertion/removal of a process from the
  //data structure
  double schedOverhead = elapsed / accSched;
  //double schedOverhead =std::chrono::duration_cast<std::chrono::double>(durNS / accSched)
  //chrono::schedOverhead<double> 
  //insert into first spot in array
  retArr[0] = schedOverhead;
  //done #1

  
  //The average CPU time of all CPU-bound processes
  //(using the getCPUTime method)
  int cpuSize = cpuBound->getSize();
  double avgCPU = 0;
  double totalCPU = 0;
  for (int i = 0; i < cpuSize; i++)
    {
      Process* currentCPU = cpuBound->getItem(i);
      totalCPU = totalCPU + currentCPU->getCPUTime();
    }
  avgCPU = totalCPU / cpuSize;
  //return to the second spot in the array
  retArr[1] = avgCPU;
  //done #2
  
  
  //The average wait time of all CPU-bound processes
  //(using the getWaitTime method)
  
  double totalCPUWait = 0;
  for (int i = 0; i < cpuSize; i++)
    {
      CPUBoundProcess* curCPU = cpuBound->getItem(i);
      double toatalCPUWait = totalCPUWait + curCPU->getWaitTime(i);
    }
  double avgCPUWait = totalCPUWait / cpuSize;
  //return to the third spot in the array
  retArr[2] = avgCPUWait;
  //done #3


  //The average CPU time of all I/O-bound processes
  int ioSize = ioBound->getSize();
  double avgIO = 0;
  double totalIO = 0;
  for (int i = 0; i < ioSize; i++)
    {
      Process* currentIO = ioBound->getItem(i);
      totalIO = totalIO + currentIO->getCPUTime();
    }
  avgIO = totalCPU / cpuSize;
  //return to the second spot in the array
  retArr[3] = avgIO;
  //done #4


  //The average wait time of all I/O-bound processes
  double totalIOWait = 0;
  for (int i = 0; i < ioSize; i++)
    {
      IOBoundProcess* curIO = ioBound->getItem(i);
      double toatalIOWait = totalIOWait + curIO->getWaitTime(i);
    }
  double avgIOWait = totalIOWait / ioSize;
  //return to the third spot in the array
  retArr[4] = avgIOWait;
  //done #5
  
  cpuBound->~ArrayList();
  ioBound->~ArrayList();


  return retArr;
  
  
}
