#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "ArrayList.hpp"
#include <string>
#include <iostream>

using namespace std;

TEST_CASE("Testing ArrayList template"){

    SECTION("Default Constructor"){
        ArrayList<int> a;
        ArrayList<double> b;
        ArrayList<string*> c;
    }

    SECTION("Capacity Constructor"){
        ArrayList<int> a(3);
        ArrayList<double> b(15);
        ArrayList<string*> c(500);
    }

    SECTION("pushBack"){
        ArrayList<int> a(1);
        a.pushBack(536);
        REQUIRE(a.getBack() == 536);

        a.pushBack(7);
        REQUIRE(a.getCapacity() == 2);
        REQUIRE(a.getBack() == 7);

        a.pushBack(84);
        REQUIRE(a.getCapacity() == 4);
        REQUIRE(a.getBack() == 84);

    }

    SECTION("popBack"){
        ArrayList<int> a(10);
        a.pushBack(536);
        a.pushBack(7);
        a.pushBack(84);
        REQUIRE(a.getBack() == 84);

        a.popBack();
        REQUIRE(a.getBack() == 7);
        REQUIRE(a.getCapacity() == 10);
    }

    SECTION("getBack"){

    }

    SECTION("pushFront"){

    }

    SECTION("popFront"){
        
    }

    SECTION("getFront"){
        
    }

}