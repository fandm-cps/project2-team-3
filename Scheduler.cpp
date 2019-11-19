#include "Scheduler.hpp"
//#include <iostream>
//#include <cstdlib>

using namespace std;

//initializes procQueue as an empty ArrayList.
RoundRobin::RoundRobin(){
    procQueue = new ArrayList<Process*>(10);
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
        if(procQueue->getFront()->isBlocked(curCycle)){
            procQueue->pushBack(procQueue->getItem(0));
            procQueue->popFront();
        }
        else{
            Process* result = procQueue->getItem(0);
            procQueue->popFront();
            
            return result;
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
  procQueue = new LinkedList<Process*>();
}

CompletelyFair::CompletelyFair(){
    procTree = new BSTMultimap<int, Process*>();
}

CompletelyFair::~CompletelyFair(){
    delete procTree;
}

void CompletelyFair::addProcess(Process* proc){
    procTree->insert(proc->getCPUTime(), proc);
}

/*First obtain an iterator pointing to the process
with the minimum CPU time. Then use the iterator to 
traverse the tree until you find a process
that is not blocked. Remove and return that process.
*/

Process* CompletelyFair::popNext(int curCycle){
    BSTForwardIterator<int, Process*> i = procTree->getMin();
    BSTForwardIterator<int, Process*> j = i;

    while(!i.isPastEnd() && i.getValue()->isBlocked(curCycle)){
        i.next();
        if(!i.getValue()->isBlocked(curCycle)){
            break;
        }
    }

    procTree->remove(i);

    return i.getValue();
}