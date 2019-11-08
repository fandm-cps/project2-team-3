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

        m.insert(5, 50);
        m.insert(2, 20);
        REQUIRE(m.getSize() == 2);
        REQUIRE(m.toString() == "(5, 50)-(2, 20)-");
        m.insert(7, 70);
        m.insert(9, 90);
        m.insert(4, 40);
        REQUIRE(m.getSize() == 5);
        REQUIRE(m.toString() == "(5, 50)-(2, 20)-(7, 70)-(4, 40)-(9, 90)-");
	BSTForwardIterator<int, int> itt = m.getMin();
	REQUIRE(itt.getValue() == 20);
	itt.next();
	REQUIRE(itt.getValue() == 40);
	itt.next();
	REQUIRE(itt.getValue() == 50);
	itt.next();
	REQUIRE(itt.getValue() == 70);
	itt.next();
	REQUIRE(itt.getValue() == 90);
	
    }

     SECTION("TESTING GETMAX"){
    BSTMultimap<int, int> m = BSTMultimap<int, int>();
    //REQUIRE(m.isEmpty() == true);
    //REQUIRE(m.getSize() == 0);

        m.insert(5, 50);
	BSTForwardIterator<int, int> itt1 = m.getMax();
	REQUIRE(itt1.getValue() == 50);
        m.insert(2, 20);
        //REQUIRE(m.getSize() == 2);
        //REQUIRE(m.toString() == "(5, 50)-(2, 20)-");
        m.insert(7, 70);
        m.insert(9, 90);
        m.insert(4, 40);
        REQUIRE(m.getSize() == 5);
        REQUIRE(m.toString() == "(5, 50)-(2, 20)-(7, 70)-(4, 40)-(9, 90)-");
	BSTForwardIterator<int, int> itt = m.getMax();
	REQUIRE(itt.getValue() == 90);
     }

     SECTION("TESTING FINDFIRST"){
    BSTMultimap<int, int> m = BSTMultimap<int, int>();
    //REQUIRE(m.isEmpty() == true);
    //REQUIRE(m.getSize() == 0);

        m.insert(5, 50);
	//BSTForwardIterator<int, int> itt1 = m.getMax();
	//REQUIRE(itt1.getValue() == 50);
        m.insert(2, 20);
        //REQUIRE(m.getSize() == 2);
        //REQUIRE(m.toString() == "(5, 50)-(2, 20)-");
        m.insert(7, 70);
	m.insert(9, 50);
        //m.insert(9, 90);
        //m.insert(4, 40);
	
	//m.insert(9, 2);
	//m.insert(9, 100);



        //REQUIRE(m.getSize() == 5);
        //REQUIRE(m.toString() == "(5, 50)-(2, 20)-(7, 70)-(4, 40)-(9, 90)-");
	cout << "here" << endl;
	BSTForwardIterator<int, int> itt = m.findFirst(9);
	cout << "val: " << itt.getValue() << endl;
	REQUIRE(itt.getKey() == 9);
	cout << "he" << endl;
     }


     /**SECTION("TESTING FINDLAST"){
    BSTMultimap<int, int> m = BSTMultimap<int, int>();
    //REQUIRE(m.isEmpty() == true);
    //REQUIRE(m.getSize() == 0);

        m.insert(5, 50);
	//BSTForwardIterator<int, int> itt1 = m.getMax();
	//REQUIRE(itt1.getValue() == 50);
        m.insert(2, 20);
        //REQUIRE(m.getSize() == 2);
        //REQUIRE(m.toString() == "(5, 50)-(2, 20)-");
        m.insert(7, 70);
	m.insert(9, 50);
        m.insert(9, 90);
        m.insert(4, 40);
	
	m.insert(9, 2);
	m.insert(9, 100);



        //REQUIRE(m.getSize() == 5);
        //REQUIRE(m.toString() == "(5, 50)-(2, 20)-(7, 70)-(4, 40)-(9, 90)-");
	//cout << "here" << endl;
	BSTForwardIterator<int, int> itt = m.findLast(9);
	cout << "val: " << itt.getValue() << endl;
	REQUIRE(itt.getKey() == 9);
	//cout << "he" << endl;
	}**/
}

     
