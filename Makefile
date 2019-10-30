CC = g++ -std=c++11
CFLAGS = -Wall
COVERAGE = --coverage

all: ArrayList_TEST RoundRobin_TEST schedulesim

ArrayList_TEST: ArrayList_TEST.cpp ArrayList.hpp
	$(CC) -o ArrayList ArrayList_TEST.cpp

Scheduler.o: Scheduler.hpp Scheduler.cpp
	$(CC) $(COVERAGE) -c Scheduler.cpp

RoundRobin_TEST: RoundRobin_TEST.cpp Scheduler.hpp Scheduler.o
	$(CC) $(COVERAGE) -o RoundRobin RoundRobin_TEST.cpp Scheduler.o Process.cpp

simulate.o: simulate.cpp simulate.hpp ArrayList.hpp Scheduler.hpp Scheduler.cpp Process.hpp Process.cpp
	$(CC) $(COVERAGE) -c simulate.cpp Scheduler.cpp Scheduler.hpp Process.cpp Scheduler.o

schedulesim: schedulesim.cpp simulate.o
	$(CC) $(CFLAGS) $(COVERAGE) -o schedulesim schedulesim.cpp 

coverage: ArrayList_TEST.cpp ArrayList.hpp
	$(CC) $(CFLAGS) $(COVERAGE) ArrayList_TEST.cpp ArrayList.hpp

coverage1: RoundRobin_TEST.cpp Scheduler.hpp Scheduler.o
	$(CC) $(CFLAGS) $(COVERAGE) RoundRobin_TEST.cpp Scheduler.o Process.cpp 

clean: rm ArrayList; rm RoundRobin
