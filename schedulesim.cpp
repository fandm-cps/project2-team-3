#include "Process.hpp"
#include "Scheduler.hpp"
#include "ArrayList.hpp"
#include "simulate.hpp"
#include <iostream>

using namespace std;

int main(int argc, char* argv[])
{
    double numCPU = stoi(argv[1]);
    double numIO = stoi(argv[2]);
    double numCycles = stoi(argv[3]);

    RoundRobin myRob;
    //FastRoundRobin fastRob;

    ArrayList<Scheduler*> arr;
    arr.pushBack(&myRob);
    //arr.pushBack(&fastRob);
    string strArr [2] = {"RoundRobin", "FastRR"};

    cout << "Results: " << endl;
    double* results;
    for(int i = 0; i < 1; i++){
        results = simulate(arr.getItem(i), numCPU, numIO, numCycles);
        cout << strArr[i] << ": " << results << endl; 
    }

    //Simulate newSim;
    //double* regResults = simulate(&myRob, numCPU, numIO, numCycles);
    //double* fastResults = simulate(&fastRob, numCPU, numIO, numCycles);

    //make sure we deallocate the results arrayt when done
    return 0;
}