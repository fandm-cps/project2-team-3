CC = g++ -g -std=c++11
CFLAGS = -Wall
COVERAGE = --coverage
C11 = -std=c++11

all: ArrayList_TEST LinkedList_TEST RoundRobin_TEST schedulesim BSTNode_TEST BSTMultimap_TEST CompletelyFair_TEST RBTNode_TEST RBTMultimap_TEST

ArrayList_TEST: ArrayList_TEST.cpp ArrayList.hpp
	$(CC) -o ArrayList ArrayList_TEST.cpp

LinkedList_TEST: LinkedList_TEST.cpp LinkedList.hpp
	$(CC) -o LinkedList LinkedList_TEST.cpp

Scheduler.o: Scheduler.hpp Scheduler.cpp 
	$(CC) $(COVERAGE) -c Scheduler.cpp

RoundRobin_TEST: RoundRobin_TEST.cpp Scheduler.o
	$(CC) $(COVERAGE) -o RoundRobin RoundRobin_TEST.cpp Scheduler.o Process.cpp

simulate.o: simulate.cpp simulate.hpp ArrayList.hpp Process.hpp Process.cpp
	$(CC) $(COVERAGE) -c simulate.cpp Scheduler.cpp Scheduler.hpp Process.cpp Process.hpp

schedulesim: schedulesim.cpp simulate.o Scheduler.o
	$(CC) $(CFLAGE) $(COVERAGE) -o schedulesim schedulesim.cpp simulate.o Scheduler.o Process.cpp

BSTNode_TEST: BSTNode_TEST.cpp BSTNode.hpp
	$(CC) -o BSTNode BSTNode_TEST.cpp

BSTMultimap_TEST: BSTMultimap_TEST.cpp BSTMultimap.hpp
	$(CC) -o BSTMultimap BSTMultimap_TEST.cpp

RBTMultimap_TEST: RBTMultimap_TEST.cpp RBTMultimap.hpp BSTMultimap.hpp RBTNode.hpp
	$(CC) -o RBTMultimap RBTMultimap_TEST.cpp 

CompletelyFair_TEST: CompletelyFair_TEST.cpp Scheduler.o
	$(CC) $(COVERAGE) -o CompletelyFair CompletelyFair_TEST.cpp Scheduler.o Process.cpp

RBTNode_TEST: RBTNode_TEST.cpp RBTNode.hpp
	$(CC) -o RBTNode RBTNode_TEST.cpp

coverage: ArrayList_TEST.cpp ArrayList.hpp
	$(CC) $(CFLAGE) $(COVERAGE) ArrayList_TEST.cpp ArrayList.hpp

coverage1: RoundRobin_TEST.cpp Scheduler.hpp Scheduler.o
	$(CC) $(CFLAGE) $(COVERAGE) RoundRobin_TEST.cpp Scheduler.o Process.cpp 

coverage2: LinkedList_TEST.cpp LinkedList.hpp
	$(CC) $(CFLAGE) $(COVERAGE) LinkedList_TEST.cpp LinkedList.hpp

coverage3: BSTNode_TEST.cpp BSTNode.hpp
	$(CC) $(CFLAGE) $(COVERAGE) BSTNode_TEST.cpp BSTNode.hpp

coverage4: BSTMultimap_TEST.cpp BSTMultimap.hpp
	$(CC) $(CFLAGE) $(COVERAGE) BSTMultimap_TEST.cpp BSTMultimap.hpp

coverage5: CompletelyFair_TEST.cpp Scheduler.hpp Scheduler.o
	$(CC) $(CFLAGE) $(COVERAGE) CompletelyFair_TEST.cpp Scheduler.o Process.cpp

coverage6: RBTMultimap_TEST.cpp RBTMultimap.hpp BSTMultimap.hpp RBTNode.hpp
	$(CC) $(CFLAGE) $(COVERAGE) RBTMultimap_TEST.cpp RBTMultimap.hpp

clean:
	rm ArrayList; rm RoundRobin; rm LinkedList; rm schedulesim; rm BSTNode; rm BSTMultimap; rm CompletelyFair; rm RBTNode; rm RBTMultimap; rm *.o; rm *.hpp.gch;
