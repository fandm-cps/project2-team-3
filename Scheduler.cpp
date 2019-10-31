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
  cout << "hey hererere" << endl;
    for(int i = 0; i < procQueue->getSize(); i++){
      cout << "anything" << endl;
      cout << "this is the process files id" << procQueue->getFront()->getID() << endl;
      cout << "this better work" << procQueue->getSize() << endl;
      cout << "in for loop" << endl;
      cout << "anything" << endl;
      cout << "this better work" << procQueue << endl;
      
      if(procQueue->getFront()->isBlocked(curCycle)){
	  cout << "in if statement" << endl;
            procQueue->pushBack(procQueue->getItem(i));
            procQueue->popFront();
        }
        else{
	  cout << "in else statement" << endl; 
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
