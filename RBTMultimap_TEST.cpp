#define CATCH_CONFIG_MAIN
#include "catch.hpp"
//#include "BSTNode.hpp"
#include "RBTMultimap.hpp"
#include <iostream>

using namespace std;

TEST_CASE("Testing RBTNode"){
    SECTION("Constructor"){
      RBTMultimap<char, int> a = RBTMultimap<char, int>();
      //RBTMultimap<double, double> b = RBTMultimap<double, double>();
      //RBTMultimap<int, char> c = RBTMultimap<int, char> ();
    }
}
