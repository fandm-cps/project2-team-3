#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "RBTMultimap.hpp"
#include <iostream>

using namespace std;

TEST_CASE("Testing RBTNode"){
  
  SECTION("Constructor"){
    RBTMultimap<char, int> a = RBTMultimap<char, int>();
    RBTMultimap<double, double> b = RBTMultimap<double, double>();
    RBTMultimap<int, char> c = RBTMultimap<int, char> ();
  }

  SECTION("insert/insertFixup"){
    RBTMultimap<int, int> m = RBTMultimap<int, int>();

    m.insert(5, 50);
    m.insert(3, 30);
    m.insert(11, 110);
    m.insert(2, 20);
    m.insert(8, 80);
    m.insert(14, 140);
    m.insert(9, 90);
    m.insert(7, 70);
    m.insert(6, 60);
    m.printDOT("rbtree.dot");

    RBTMultimap<int, int> m1 = RBTMultimap<int, int>();

    m1.insert(23, 230);
    m1.insert(12, 120);
    m1.insert(31, 310);
    m1.insert(4, 40);
    m1.insert(15, 150);
    m1.insert(25, 250);
    m1.insert(38, 380);
    m1.insert(2, 20);
    m1.insert(13, 130);
    m1.insert(20, 200);
    m1.insert(18, 180);
    m1.printDOT("rbtree1.dot");

  }

}