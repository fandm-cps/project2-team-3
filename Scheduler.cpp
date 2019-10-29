#include "Scheduler.hpp"
#include <iostream>
#include <cstdlib>

using namespace std;

//initializes procQueue as an empty ArrayList.
RoundRobin::RoundRobin(){
    procQueue = new ArrayList<Process*>;
}

//deletes procQueue (not its contents!)
RoundRobin::~RoundRobin(){
    delete procQueue;
}

//adds the given process to the back of procQueue.
void RoundRobin::addProcess(Process* proc){
    procQueue.pushBack(proc);
}

//returns the first un-blocked process in the queue
//(moving any blocked processes to the back of the 
//queue) or 0 if all processes are blocked.
Process RoundRobin::popNext(int curCycle){
    for(int i = 0; i < procQueue.size; i++){
        if(procQueue[i].isBlocked()){
            procQueue.pushBack(procQueue.popFront());
        }
        else{
            return procQueue[i];
        }
    }

    return 0;
}

/*
Implement this class in Scheduler.cpp. You should implement 
RoundRobin_TEST.cpp to test your class to be sure it does what 
you think it does. You'll notice that Process objects have an 
ID. It has no functional purpose, but you can use it in testing 
to see if processes come out of the scheduler in the order you 
expect. Note that, though IOBoundProcess objects behave randomly, 
you can obtain a blocked process to test with by repeatedly called 
useCPU until it becomes blocked.
*/