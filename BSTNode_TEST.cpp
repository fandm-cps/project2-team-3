#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "BSTNode.hpp"
#include <string>
#include <iostream>

using namespace std;

TEST_CASE("TESTING BSTNODE TEMPLATE")
{

  SECTION("TESTING CONSTRUCTOR")
    {
      BSTNode<char, int> myNode('a', 5);
    }
}
