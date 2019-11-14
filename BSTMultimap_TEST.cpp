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
        m.insert(2, 20);
        m.insert(5, 50);
        REQUIRE(m.toString() == "(5, 50)-(2, 20)-(7, 70)-(4, 40)-(5, 50)-(9, 90)-(2, 20)-");
    }

    SECTION("getMin, isPastEnd"){
        BSTMultimap<int, int> m = BSTMultimap<int, int>();
        BSTForwardIterator<int, int> i = m.getMin();
        m.insert(8, 80);
        m.insert(3, 30);
        
        REQUIRE(m.getMax().getValue() == 80);
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
        REQUIRE(m.getMax().getValue() == 140);
        m.insert(7, 70);
        m.insert(13, 130);
        i = m.getMin();
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

    SECTION("getMax"){
        BSTMultimap<int, int> m = BSTMultimap<int, int>();

        BSTForwardIterator<int, int> itt0 = m.getMax();

        m.insert(5, 50);
        BSTForwardIterator<int, int> itt1 = m.getMax();
        REQUIRE(itt1.getValue() == 50);
        m.insert(2, 20);
        REQUIRE(m.getMax().getValue() == 50);
        m.insert(7, 70);
        m.insert(9, 90);
        m.insert(4, 40);
        REQUIRE(m.getMax().getKey() == 9);
        
        BSTForwardIterator<int, int> itt = m.getMax();
        REQUIRE(itt.getValue() == 90);
     }

    SECTION("findFirst"){
        BSTMultimap<int, int> m = BSTMultimap<int, int>();
	BSTForwardIterator<int, int> i = m.findFirst(9);

        m.insert(5, 50);
        m.insert(3, 30);
        m.insert(2, 20);
        m.insert(3, 31);
        m.insert(7, 70);
        m.insert(7, 71);
        m.insert(9, 90);
        
        i = m.findFirst(3);
        REQUIRE(i.getValue() == 30);
        i = m.findFirst(7);
        REQUIRE(i.getValue() == 70);
        i = m.findFirst(9);
        REQUIRE(i.getValue() == 90);
    }
/*
     SECTION("TESTING FINDLAST"){
        BSTMultimap<int, int> m = BSTMultimap<int, int>();
	BSTForwardIterator<int, int> i = m.findLast(9);

        m.insert(5, 50);
        m.insert(3, 30);
        m.insert(2, 20);
        m.insert(3, 31);
        m.insert(7, 70);
        m.insert(7, 71);
        m.insert(9, 90);
        m.insert(5, 51);
        
        i = m.findLast(3);
        //REQUIRE(i.getValue() == 31);
        i = m.findLast(7);
        REQUIRE(i.getValue() == 71);
        i = m.findLast(5);
        REQUIRE(i.getValue() == 51);
        i = m.findLast(9);
        REQUIRE(i.getValue() == 90);
	}

/*
     SECTION("TESTING REMOVE"){

       BSTMultimap<int, int> m = BSTMultimap<int, int>();
        m.insert(5, 50);
        m.insert(2, 20);
        m.insert(7, 70);
        m.insert(9, 90);
        m.insert(4, 40);
        
	BSTForwardIterator<int, int> min = m.getMin();
	BSTForwardIterator<int, int> copy = min;
	copy.next();
	copy.next();
	REQUIRE(copy.getValue() == 50);
	//cout << "copy.getValue(): " << copy.getValue() << endl;
	BSTForwardIterator<int, int> copySucc = m.remove(copy);
	REQUIRE(copySucc.getValue() == 70);
	//cout << "copySucc: " << copySucc.getValue() << endl;
	BSTForwardIterator<int, int> minSucc = m.remove(min);

	REQUIRE(minSucc.getValue() == 40);
	//cout << "minSucc Val: " << (minSucc.getValue()) << endl;

							   //BSTForwardIterator<int, int> max = m.getMax();
							   //BSTForwardIterator<int, int> maxSucc = m.remove(max);
							   //REQUIRE(maxSucc.getValue() == 70);
        //cout << "maxSucc Val: " << (maxSucc.getValue()) << endl;
	
     }

        SECTION("TESTING PASTEND, GETKEY, & SETVALUE"){

       BSTMultimap<int, int> m = BSTMultimap<int, int>();
        m.insert(5, 50);
        m.insert(2, 20);
        m.insert(7, 70);
        m.insert(9, 90);
        m.insert(4, 40);
	BSTForwardIterator<int, int> min = m.getMin();
	min.next();
	REQUIRE(min.getKey() == 4);
	//cout << "getKey: " << min.getKey() << endl;
	min.setValue(44);
	REQUIRE(min.getValue() == 44);
	//cout << "here" << endl;
	REQUIRE(min.isPastEnd() == false);
	//cout << "here2" << endl;
	//cout << "is it: " << min.isPastEnd() << endl;
	min.next();
	min.next();
	min.next();
	min.next();
	//min.next();
	REQUIRE(min.isPastEnd() == true);
	//cout << "is it: " << min.isPastEnd() << endl;

     }

	SECTION("TESTING REMOVAL OF A PARENT W TWO CHILDREN"){

       BSTMultimap<int, int> m = BSTMultimap<int, int>();
       //REQUIRE(m.contains(50) == false);
        m.insert(5, 50);
        m.insert(2, 20);
	m.insert(7, 70);
        m.insert(9, 90);
	m.insert(4, 40);
	m.insert(6, 60);
	BSTForwardIterator<int, int> first = m.findLast(7);
	//first.next();
	//first.next();
	//cout << "toString: " << m.toString() << endl;
	//cout << "val: " << first.getValue() << endl;
	BSTForwardIterator<int, int> succ = m.remove(first);
	//cout << "succ val: " << succ.getValue() << endl;
	}*/
        
}