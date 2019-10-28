CC = g++
CFLAGS = -Wall
COVERAGE = --coverage


all: ArrayList_TEST

Arraylist_TEST: ArrayList_TEST.cpp ArrayList.hpp
	$(CC) -o ArrayList ArrayList_TEST.cpp

coverage: ArrayList_TEST.cpp ArrayList.hpp
	$(CC) $(CFLAGS) $(COVERAGE) ArrayList_TEST.cpp ArrayList.hpp

clean: rm ArrayList
