CC = g++
CFLAGS = -Wall
COVERAGE = --coverage


all: ArrayList_TEST

Arraylist_TEST: ArrayList_TEST.cpp ArrayList.hpp
	$(CC) -o ArrayList ArrayList_TEST.cpp

clean: rm ArrayList
