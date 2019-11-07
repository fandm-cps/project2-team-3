#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "BSTMultimap.hpp"
#include <iostream>

using namespace std;

TEST_CASE("Testing BSTNode"){

    SECTION("Constructor"){
        BSTMultimap<char, int> a = BSTMultimap<char, int>();
        BSTMultimap<double, double> b = BSTMultimap<double, double>();
        BSTMultimap<int, char> c = BSTMultimap<int, char>();
    }

    SECTION("getSize, isEmpty, insert"){
        BSTMultimap<int, int> m = BSTMultimap<int, int>();
        REQUIRE(m.isEmpty() == true);
        REQUIRE(m.getSize() == 0);

        m.insert(1, 10);
        m.insert(2, 20);
        REQUIRE(m.getSize() == 2);
        REQUIRE(m.toString() == "(1, 10)-(2, 20)-");
        m.insert(3, 30);
        m.insert(4, 40);
        REQUIRE(m.getSize() == 4);
        REQUIRE(m.toString() == "(1, 10)-(2, 20)-(3, 30)-(4, 40)-");
    }
}