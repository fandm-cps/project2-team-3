#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "BSTMultimap.hpp"
#include <iostream>

using namespace std;

TEST_CASE("Testing BSTMultimap"){

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

    SECTION("getMin"){
        BSTMultimap<int, int> m = BSTMultimap<int, int>();
        
        REQUIRE(m.getMin().getKey() == 0);
        m.insert(8, 80);
        m.insert(3, 30);
        
        m.getMin().setValue(300);
        REQUIRE(m.getMin().getValue() == 300);
        m.getMin().setValue(30);

        m.insert(10, 100);
        m.insert(1, 10);

        REQUIRE(m.getMin().getKey() == 1);
        REQUIRE(m.getMin().getValue() == 10);

        m.insert(6, 60);
        m.insert(14, 140);
        m.insert(4, 40);
        m.insert(7, 70);
        m.insert(13, 130);
        BSTForwardIterator<int, int> i = m.getMin();
        i.next();
        REQUIRE(i.getKey() == 3);
        i.next();
        REQUIRE(i.getKey() == 4);
        REQUIRE(i.isPastEnd() == false);
        i.next();
        i.next();
        i.next();
        i.next();
        i.next();
        i.next();
        i.next();
        REQUIRE(i.isPastEnd() == true);
        
        REQUIRE(m.toString() == "(8, 80)-(3, 30)-(10, 100)-(1, 10)-(6, 60)-(14, 140)-(4, 40)-(7, 70)-(13, 130)-");

    }
}