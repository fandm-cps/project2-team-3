CC = g++
CFLAGS = -Wall
COVERAGE = --coverage

all: ArrayList_TEST RoundRobin_TEST

ArrayList_TEST: ArrayList_TEST.cpp ArrayList.hpp
	$(CC) -o ArrayList ArrayList_TEST.cpp

RoundRobin_TEST: RoundRobin_TEST.cpp Scheduler.hpp
	$(CC) -o RoundRobin RoundRobin_TEST.cpp 

coverage: ArrayList_TEST.cpp ArrayList.hpp
	$(CC) $(CFLAGE) $(COVERAGE) ArrayList_TEST.cpp ArrayList.hpp

clean: rm ArrayList; rm RoundRobin
