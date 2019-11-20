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
    FastRoundRobin fastRob;
    CompletelyFair comp;
    FastCompletelyFair fastCF;

    ArrayList<Scheduler*> arr;
    arr.pushBack(&myRob);
    arr.pushBack(&fastRob);
    arr.pushBack(&comp);
    arr.pushBack(&fastCF);
    string strArr [4] = {"RoundRobin", "FastRR", "CompletelyFair", "FastCF"};

    double* results;
    for(int i = 0; i < 4; i++){
        results = simulate(arr.getItem(i), numCPU, numIO, numCycles);
        cout << strArr[i] << " Overhead: " << results[0] << endl;
        cout << strArr[i] << " Avg CPUtime (CPUBound): " << results[1] << endl;
        cout << strArr[i] << " Avg WAITtime (CPUBound): " << results[2] << endl;
        cout << strArr[i] << " Avg CPUtime (IOBound): " << results[3] << endl;
        cout << strArr[i] << " Avg WAITtime (IOBound): " << results[4] << endl;
    }

    return 0;
}