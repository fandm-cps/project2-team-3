CC = g++
CFLAGS = -Wall
COVERAGE = --coverage
C11 = -std=c++11

all: ArrayList_TEST LinkedList_TEST RoundRobin_TEST

ArrayList_TEST: ArrayList_TEST.cpp ArrayList.hpp
	$(CC) -o ArrayList ArrayList_TEST.cpp

LinkedList_TEST: LinkedList_TEST.cpp LinkedList.hpp
	$(CC) -o LinkedList LinkedList_TEST.cpp

Scheduler.o: Scheduler.hpp Scheduler.cpp
	$(CC) $(COVERAGE) -c Scheduler.cpp

RoundRobin_TEST: RoundRobin_TEST.cpp Scheduler.hpp Scheduler.o
	$(CC) $(COVERAGE) -o RoundRobin RoundRobin_TEST.cpp Scheduler.o Process.cpp

coverage: ArrayList_TEST.cpp ArrayList.hpp
	$(CC) $(CFLAGE) $(COVERAGE) ArrayList_TEST.cpp ArrayList.hpp

coverage1: RoundRobin_TEST.cpp Scheduler.hpp Scheduler.o
	$(CC) $(CFLAGE) $(COVERAGE) RoundRobin_TEST.cpp Scheduler.o Process.cpp 

coverage2: LinkedList_TEST.cpp LinkedList.hpp
	$(CC) $(CFLAGE) $(COVERAGE) LinkedList_TEST.cpp LinkedList.hpp

clean: rm ArrayList; rm RoundRobin
