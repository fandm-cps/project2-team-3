#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "LinkedList.hpp"
#include <string>
#include <iostream>

using namespace std;

TEST_CASE("Testing LinkedList Template"){

    SECTION("Default Constructor"){
        LinkedList<int> a;
        LinkedList<double> b;
        LinkedList<string*> c;
    }

    SECTION("pushBack, popBack, & getBack"){
        LinkedList<int> a;

        REQUIRE(a.isEmpty() == true);

        a.pushBack(3);
        REQUIRE(a.getBack() == 3);
        REQUIRE(a.getSize() == 1);
        REQUIRE(a.isEmpty() == false);

        a.pushBack(5);
        REQUIRE(a.getBack() == 5);
        REQUIRE(a.getSize() == 2);
        
        a.popBack();
        REQUIRE(a.getBack() == 3);
        REQUIRE(a.getSize() == 1);
        
        a.popBack();
        REQUIRE(a.getSize() == 0);
    }

    SECTION("pushFront, popFront, & getFront"){
        LinkedList<int> a;

        a.pushFront(5);
        REQUIRE(a.getFront() == 5);
        REQUIRE(a.getSize() == 1);

        a.pushFront(4);
        REQUIRE(a.getFront() == 4);
        REQUIRE(a.getSize() == 2);

        a.popFront();
        REQUIRE(a.getFront() == 5);
        REQUIRE(a.getSize() == 1);
        
        a.popFront();
        REQUIRE(a.getSize() == 0);
    }

    SECTION("getItem & setItem"){
        LinkedList<int> a;

        a.pushFront(1);
        a.pushFront(2);
        a.pushFront(3);
        a.pushFront(4);
        a.pushFront(5);
        a.pushFront(6);
        REQUIRE(a.getItem(3) == 3);
        
        a.setItem(3, 10);
        REQUIRE(a.getItem(3) == 10);
    }

    SECTION("insert & remove"){
        LinkedList<int> a;

        a.pushBack(1);
        a.pushBack(2);
        a.pushBack(3);
        a.pushBack(4);
        a.pushBack(5);
        a.pushBack(6);
        a.insert(0, 15);
        REQUIRE(a.getItem(0) == 15);
        REQUIRE(a.getSize() == 7);
        
        a.insert(7, 10);
        REQUIRE(a.getItem(7) == 10);
        REQUIRE(a.getSize() == 8);

        a.insert(3, 20);
        REQUIRE(a.getItem(3) == 20);
        REQUIRE(a.getSize() == 9);

        a.remove(0);
        REQUIRE(a.getItem(0) == 1);
        a.remove(7);
        REQUIRE(a.getItem(6) == 6);
        a.remove(4);
        REQUIRE(a.getItem(4) == 5);

    }

}
