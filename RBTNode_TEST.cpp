#define CATCH_CONFIG_MAIN
#include "catch.hpp"
//#include "BSTNode.hpp"
#include "RBTNode.hpp"
#include <iostream>

using namespace std;

TEST_CASE("Testing RBTNode"){
    SECTION("Constructor"){
      RBTNode<char, int> a = RBTNode<char, int>('a', 1, true);
      RBTNode<double, double> b = RBTNode<double, double>(63, 2, true);
      RBTNode<int, char> c = RBTNode<int, char> (2, 'c', true);
    }
}
