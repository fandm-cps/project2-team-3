#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "BSTNode.hpp"
#include <iostream>

using namespace std;

TEST_CASE("Testing BSTNode"){
    SECTION("Constructor"){
        BSTNode<char, int> a = BSTNode<char, int>( 'a', 1);
        BSTNode<double, double> b = BSTNode<double, double>(63, 2);
        BSTNode<int, char> c = BSTNode<int, char> (2, 'c');
    }

    SECTION("setKey/Value & getKey/Value"){
        BSTNode<char, int> a = BSTNode<char, int>('a', 1);

        REQUIRE(a.getKey() == 'a');
        REQUIRE(a.getValue() == 1);

        a.setKey('r');
        a.setValue(22);

        REQUIRE(a.getKey() == 'r');
        REQUIRE(a.getValue() == 22);
    }

    SECTION("parent and child getters/setters"){
        BSTNode<char, int>* a = new BSTNode<char, int>('a', 1);
        BSTNode<char, int>* b = new BSTNode<char, int>('b', 2);
        BSTNode<char, int>* c = new BSTNode<char, int>('c', 3);
        BSTNode<char, int>* d = new BSTNode<char, int>('d', 4);

        a->setLeftChild(b);
        a->setRightChild(c);

        REQUIRE(a->getLeftChild()->getKey() == 'b');
        REQUIRE(a->getRightChild()->getValue() == 3);

        a->setParent(d);
        REQUIRE(a->getParent()->getKey() == 'd');

        delete a;
        delete b;
        delete c;
        delete d;
    }
}