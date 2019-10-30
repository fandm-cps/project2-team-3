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
    procQueue->pushBack(proc);
}

//returns the first un-blocked process in the queue
//(moving any blocked processes to the back of the 
//queue) or 0 if all processes are blocked.
Process* RoundRobin::popNext(int curCycle){

    for(int i = 0; i < procQueue->getSize(); i++){
        if(procQueue->getItem(i)->isBlocked(curCycle)){
            procQueue->pushBack(procQueue->getItem(i));
            procQueue->popFront();
        }
        else{
            return procQueue->getItem(i);
        }
    }

    return 0;
}

FastRoundRobin::FastRoundRobin()
{
  //constructor, which should delete the list that RoundRobin created
  //(remember that the superclass' constructor is always invoked first)
  //procQueue->~RoundRobin();
  delete procQueue;
  //point procQueue to an empty LinkedList
  procQueue = new LinkedList<Process*>;
}
