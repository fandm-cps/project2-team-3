Files included on this project:

List.hpp
ArrayList.hpp/tpp
LinkedListNode.hpp/tpp
LinkedList.hpp/tpp
BSTNode.hpp/tpp
BSTMultimap.hpp/tpp
BSTForwardIterator.hpp/tpp
RBTNode.hpp/tpp
RBTMultimap.hpp/tpp
Process.hpp/cpp
Scheduler.hpp/cpp
simulate.hpp/cpp
schedulesim.cpp
ArrayList_TEST.cpp
LinkedList_TEST.cpp
BSTNode_TEST.cpp
BSTMultimap_TEST.cpp
RBTNode_TEST.cpp
RBTMultimap_TEST.cpp
RoundRobin_TEST.cpp
CompletelyFair_TEST.cpp
catch.hpp
Makefile
timing.pdf
cputimes.pd
readme.txt

Below is a list of the commands that should be written to the terminal in order to run unit testing.

ArrayList: ./ArrayList
LinkedList: ./LinkedList
RoundRobin: ./RoundRobin
BSTNode: ./BSTNode
BSTMultimap: ./BSTMultimap
CompletelyFair: ./CompletelyFair
RBTNode: ./RBTNode
RBTMultimap: ./RBTMultimap

To run schedulesim: In the terminal type "./schedulesim <number of CPU-buond processes> <number of IO-bound processes> <number of cycles>", replacing the three parameters in <> by their corresponding numbers.
Project Description:

This project compares different advanced data structures, featuring ArrayLists, LinkedLists, Binary Search Trees, and RedBlack Trees. 

We used RoundRobin and FastRoundRobin schedulers to tests the efficiency for each of our ArrayList and LinkedList data structures. Our RoundRobin is backed by the ArrayList data structure and the FastRoundRobin is backed by the LinkedList data structure. As one could assume by the name the RoundRobin is outperformed in terms of time efficiency by the FastRoundRobin. RoundRobin’s average overhead over 1000, 2000, 3000, 4000, 5000, 6000, 7000, 8000, 9000, and 10000 cycles is 11,821.38. FastRoundRobin’s average overhead over 1000, 2000, 3000, 4000, 5000, 6000, 7000, 8000, 9000, and 10000 cycles is a staggering 59.81. This proves that a LinkedList backed data structure is extremely efficient compared to an ArrayList.

We move on to use CompletelyFairScheduler and a FastCompletelyFairScheduler to test the efficiency of our BinarySearchTree and RedBlackTree data structures. Our CompletelyFairScheduler is backed by the BinarySearchTree data structure and the FastCompletelyFairScheduler is backed by the RedBlackTree data structure. Once again the CompletelyFairScheduler is outperformed by the FastCompletelyFairScheduler. CompletelyFairScheduler’s average overhead over 1000, 2000, 3000, 4000, 5000, 6000, 7000, 8000, 9000, and 10000 cycles is 50,016.22. FastCompletelyFairScheduler’s overhead over 1000, 2000, 3000, 4000, 5000, 6000, 7000, 8000, 9000, and 10000 cycles is 1,336.82. This proves that a RedBlackTree backed data structure is extremely efficient compared to a BinarySearchTree.

Although visually seeing the efficiency differences in data structures was the main objective of project2, we also learned valuable lessons about inheritance in C++. Each data structure we created ended up building upon a previously made data structure, therefore using inheritance. For example, LinkedList inherited List, FastRoundRobin inherited RoundRobin, FastCompletelyFairScheduler inherited CompletelyFairScheduler, and RedBlackTree inherited BinarySearchTree. These instances of inheritance helped us avoid code duplication, saving us a lot of time coding and making our code more neat and efficient. Another important lesson learned from inheritance was dynamic casting which allows the compiler to access a specific function or member of a child class. In our case, it helped the compiler differentiate between a BSTNode and an RBTNode ultimately letting us access and change the color of a specific node.

As always we ran into countless unique errors dealing with C++ and this lead us to be very careful with the use of our pointers and allocation of memory. When we slipped up with pointer usage we parsed through Valgrind to help locate the source of the error, a skill that will definitely prove useful in future C++ projects! 

NOTES:

Where our project currently stands, our LinkedList has 6 block leak errors, RoundRobin has 2 block leaks, BSTMultimap has 2 block leaks, RBTMultimap has 9 block leaks, and CompletelyFair has 4 block leaks. All our other tests were free of memory leaks.


