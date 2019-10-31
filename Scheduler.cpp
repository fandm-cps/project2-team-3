#include "Scheduler.hpp"
#include <iostream>
#include <cstdlib>

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

    //cout<<"a"<<endl;
    for(int i = 0; i < procQueue->getSize(); i++){
        //cout<<i<<endl;
        if(procQueue->getFront()->isBlocked(curCycle)){
            //cout<<"b"<<endl;
            procQueue->pushBack(procQueue->getItem(i));
            procQueue->popFront();
        }
        else{
            //cout<<"c"<<endl;
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