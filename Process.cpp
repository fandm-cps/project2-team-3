#include "Process.hpp"
#include <cstdlib>
#include <iostream>

using namespace std;

Process::Process(int id) : id(id)
{
   cpuTime = 0;
   waitTime = 0;
}

//Returns the process' ID number
int Process::getID() const
{
   return id;
}

//Returns the total CPU time the process has used
int Process::getCPUTime() const
{
   return cpuTime;
}

//Returns the total amount of time the process was
//ready to run (not blocked), but not running.
//curCycleNum is the number of simulated cycles so far.
int Process::getWaitTime(int curCycleNum) const
{
   int additionalWait = curCycleNum - lastTime;
   if(additionalWait < 0)
   {
      additionalWait = 0;
   }
   return waitTime + additionalWait;
}

CPUBoundProcess::CPUBoundProcess(int id) : Process(id)
{
   lastTime = 0;
}

//Returns true if the process is blocked
//curCycleNum is the number of simulated cycles so far.
bool CPUBoundProcess::isBlocked(int curCycleNum) const
{
   return false;
}

//Simulates giving the process sliceSize time on the CPU.
//curCycleNum is the number of simulated cycles so far (used to
//calculate wait time etc.) 
//Returns the number of CPU cycles the process actually consumes.
int CPUBoundProcess::useCPU(int curCycleNum, int sliceSize)
{
   //The process uses all CPU time given to it
   cpuTime += sliceSize;
   
   waitTime += curCycleNum - lastTime;
   //When the process next uses the CPU, it will have been
   //waiting since the end of this window.
   lastTime = curCycleNum + sliceSize;

   return sliceSize;
}

IOBoundProcess::IOBoundProcess(int id) : Process(id), minBurst(5), maxBurst(15), minIO(50), maxIO(200)
{
   lastTime = 0;
   blockedUntil = 0;
   remainingBurst = 0;
}

//Returns false...the process is never blocked
bool IOBoundProcess::isBlocked(int curCycleNum) const
{
   return curCycleNum < blockedUntil;
}

//Returns sliceSize...the process uses all the CPU time
int IOBoundProcess::useCPU(int curCycleNum, int sliceSize)
{
   //If the process was blocked, and is now unblocked,
   //choose a length for the next CPU burst
   if(curCycleNum >= blockedUntil && remainingBurst == 0)
   {
      remainingBurst = random()%(maxBurst - minBurst + 1) + minBurst;
   }

   int timeUsed = 0;
   if(remainingBurst > 0) //If the process is not blocked...
   {
      waitTime += curCycleNum - lastTime;

      if(remainingBurst > sliceSize) //If the whole window will be used...
      {
	 remainingBurst -= sliceSize;
	 timeUsed = sliceSize;

	 //When the process next uses the CPU, it will have been
	 //waiting since the end of this window.
	 lastTime = curCycleNum + sliceSize;
      }
      else //Otherwise the process will block without using the whole window
      {
	 timeUsed = remainingBurst;
	 remainingBurst = 0;

	 //Choose a time for the IO request to complete
	 blockedUntil = curCycleNum + timeUsed + random()%(maxIO - minIO + 1) + minIO;
	 //When the process next uses the CPU, it will have been
	 //waiting since it unblocked (not since the end of this window).
	 lastTime = blockedUntil;
      }
   }

   cpuTime += timeUsed;
   return timeUsed;
}
