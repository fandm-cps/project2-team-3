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

    SECTION("functions"){
        BSTMultimap<int, int> m = BSTMultimap<int, int>();
        REQUIRE(m.isEmpty() == true);
        REQUIRE(m.getSize() == 0);

        REQUIRE(m.contains(4) == false);
        m.insert(5, 50);
        m.insert(2, 20);
        REQUIRE(m.getSize() == 2);
        REQUIRE(m.toString() == "(5, 50)-(2, 20)-");
        REQUIRE(m.contains(5) == true);
        REQUIRE(m.contains(7) == false);
        m.insert(7, 70);
        m.insert(9, 90);
        m.insert(4, 40);
        REQUIRE(m.contains(5) == true);
        REQUIRE(m.contains(7) == true);
        REQUIRE(m.getSize() == 5);
        REQUIRE(m.toString() == "(5, 50)-(2, 20)-(7, 70)-(4, 40)-(9, 90)-");
    }
}