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

    ArrayList<Scheduler*> arr;
    arr.pushBack(&myRob);
    //arr.pushBack(&fastRob);
    string strArr [2] = {"RoundRobin", "FastRR"};

    //cout << "Results: " << endl;
    double* results;
    
    results = simulate(&myRob, numCPU, numIO, numCycles);
    cout << "REG RR Overhead: " << results[0] << endl;
    cout << "REG RR CPUtime (CPUBound): " << results[1] << endl;
    cout << "REG RR WAITtime (CPUBound): " << results[2] << endl;
    cout << "REG RR CPUtime (IOBound): " << results[3] << endl;
    cout << "REG RR WAITtime (IOBound): " << results[4] << endl;
    /**for(int i = 0; i < 5; i++){
      cout << "i = " << i << endl;
        
      //cout << "lets find out what index 1 is: " << results[1] << endl;
        cout << "Round Robin: " << results[i] << endl; 
	}**/

    double* fastResults;

    fastResults = simulate(&fastRob, numCPU, numIO, numCycles);

    //for(int i = 0; i < 5; i++){
    //cout << "i = " << i << endl;
        
      //cout << "lets find out what index 1 is: " << results[1] << endl;
        cout << "FAST RR Overhead: " << fastResults[0] << endl;
	cout << "FAST RR CPUtime (CPUBound): " << fastResults[1] << endl;
	cout << "FAST RR WAITtime (CPUBound): " << fastResults[2] << endl;
	cout << "FAST RR CPUtime (IOBound): " << fastResults[3] << endl;
	cout << "FAST RR WAITtime (IOBound): " << fastResults[4] << endl;
	
	//}
    

    //Simulate newSim;
    //double* regResults = simulate(&myRob, numCPU, numIO, numCycles);
    //double* fastResults = simulate(&fastRob, numCPU, numIO, numCycles);

    //make sure we deallocate the results arrayt when done
    return 0;
}
