#ifndef SCHEDULER_H
#define SCHEDULER_H

#include "Process.hpp"
#include "List.hpp"
#include "ArrayList.hpp"
#include "LinkedList.hpp"

class Scheduler
{
    public:  
        //An empty virtual destructor for the sake of inheritance
        virtual ~Scheduler() { }

        //adds the given process to the processes to be scheduled
        virtual void addProcess(Process* proc) = 0;
        //removes and returns the next process in the schedule.
        //(Returns 0 if there is no available process)
        virtual Process* popNext(int curCycle) = 0;

};

class RoundRobin : public Scheduler
{
    protected:
        List<Process*> *procQueue;

    public:
        //initializes procQueue as an empty ArrayList.
        RoundRobin();
        //deletes procQueue (not its contents!)
        virtual ~RoundRobin();

        //adds the given process to the back of procQueue.
        virtual void addProcess(Process* proc);
        //returns the first un-blocked process in the queue
        //(moving any blocked processes to the back of the 
        //queue) or 0 if all processes are blocked.
        virtual Process* popNext(int curCycle);

};

class FastRoundRobin : public RoundRobin
{
public: 
  FastRoundRobin();
};

/*
#include "BSTMultimap.hpp"
class CompletelyFair : public Scheduler
{
    protected:
        BSTMultimap<int, Process*>* procTree;

    public:
        CompletelyFair();
        virtual ~CompletelyFair();
        virtual void addProcess(Process* proc);
        virtual Process* popNext(int curCycle);
};
*/

#endif