#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "ArrayList.hpp"
#include <string>
#include <iostream>

using namespace std;

TEST_CASE("Testing ArrayList Template"){

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
        REQUIRE(a.getCapacity() == 4);
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
        REQUIRE(a.getSize() == 3);

        a.popBack();
        REQUIRE(a.getBack() == 7);
        REQUIRE(a.getCapacity() == 10);
        REQUIRE(a.getSize() == 2);
        REQUIRE(a.isEmpty() == false);
        a.popBack();
        a.popBack();
        REQUIRE(a.isEmpty() == true);
        REQUIRE(a.getSize() == 0);
    }


    SECTION("pushFront"){
        ArrayList<int> myArr2(1);
        myArr2.pushFront(5);
        REQUIRE(myArr2.getFront() == 5);
        myArr2.pushFront(25);
        REQUIRE(myArr2.getFront() == 25);
        myArr2.pushFront(2);
        REQUIRE(myArr2.getFront() == 2);
    }

    SECTION("popFront"){
        ArrayList<int> a;
        for(int i = 2; i < 20; i += 3){
            a.pushBack(i);
        }
        REQUIRE(a.getFront() == 2);
        a.popFront();
        REQUIRE(a.getFront() == 5);
        a.popFront();
        REQUIRE(a.getFront() == 8);

    }

    SECTION("getItem & setItem"){
        ArrayList<double> a;
        a.pushFront(56);
        a.pushBack(45);
        a.pushFront(8);

        REQUIRE(a.getItem(0) == 8);
        REQUIRE(a.getItem(1) == 56);
        REQUIRE(a.getItem(2) == 45);

        a.setItem(2, 489);
        a.setItem(1, 5);
        REQUIRE(a.getItem(1) == 5);
        REQUIRE(a.getItem(2) == 489);
    }

    SECTION("insert"){
        ArrayList<int> myArr3(4);
        myArr3.pushFront(5);
        myArr3.pushFront(25);
        myArr3.insert(0, 45);
        REQUIRE(myArr3.getFront() == 45);
        myArr3.insert(0, 33);
        REQUIRE(myArr3.getFront() == 33);
        myArr3.pushFront(10);
        myArr3.pushFront(26);
        myArr3.pushFront(66);
        myArr3.insert(55, 77);
        REQUIRE(myArr3.getBack() == 77);
        myArr3.insert(0, 32);
        REQUIRE(myArr3.getFront() == 32);
        myArr3.insert(5, 49);
        REQUIRE(myArr3.getItem(5) == 49);
    }

    SECTION("remove"){
        ArrayList<int> a;
        a.pushFront(56);
        a.pushBack(45);
        a.pushFront(8);
        a.pushFront(56);
        a.pushBack(23);
        a.pushBack(487);
        REQUIRE(a.getSize() == 6);
        a.remove(4);
        REQUIRE(a.getSize() == 5);
        REQUIRE(a.getItem(4) == 487);
    }

}
