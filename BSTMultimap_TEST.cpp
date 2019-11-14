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

     SECTION("TESTING EMPTY FINDFIRST"){
    BSTMultimap<int, int> m = BSTMultimap<int, int>();
    //REQUIRE(m.isEmpty() == true);
    //REQUIRE(m.getSize() == 0);

    //m.insert(5, 50);
	//BSTForwardIterator<int, int> itt1 = m.getMax();
	//REQUIRE(itt1.getValue() == 50);
    //m.insert(2, 20);
        //REQUIRE(m.getSize() == 2);
        //REQUIRE(m.toString() == "(5, 50)-(2, 20)-");
    //m.insert(7, 70);
    //m.insert(9, 50);
    //m.insert(9, 90);
    //m.insert(4, 40);
	
	//m.insert(9, 2);
	//m.insert(9, 100);



        //REQUIRE(m.getSize() == 5);
        //REQUIRE(m.toString() == "(5, 50)-(2, 20)-(7, 70)-(4, 40)-(9, 90)-");
	//cout << "here" << endl;
	BSTForwardIterator<int, int> itt = m.findFirst(9);
	//cout << "val: " << itt.isPastEnd() << endl;
	REQUIRE(itt.isPastEnd() == true);
	//cout << "he" << endl;
	}


     SECTION("TESTING FULL FINDFIRST"){
    BSTMultimap<int, int> m = BSTMultimap<int, int>();
    //REQUIRE(m.isEmpty() == true);
    //REQUIRE(m.getSize() == 0);

    m.insert(5, 50);
        m.insert(2, 20);
	m.insert(7, 70);
        m.insert(9, 90);
	m.insert(4, 40);
	m.insert(6, 60);

	BSTForwardIterator<int, int> itt = m.findFirst(5);
	REQUIRE(itt.getKey() == 5);
	//cout << "ittVal: " << itt.getValue() << endl;

	BSTForwardIterator<int, int> itt2 = m.findFirst(9);
	REQUIRE(itt2.getKey() == 9);
	//cout << "itt2Val: " << itt2.getValue() << endl;
    

     }


     SECTION("TESTING FINDLAST"){
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
	//cout << "val: " << itt.getValue() << endl;
	REQUIRE(itt.getKey() == 9);
	//cout << "he" << endl;
	}

     /**SECTION("TESTING REMOVE"){

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
	
	}**/

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
	  //REQUIRE(1 == 1);
       BSTMultimap<int, int> m = BSTMultimap<int, int>();
       //REQUIRE(m.contains(50) == false);
        m.insert(50, 500);
        m.insert(20, 200);
	m.insert(70, 700);
        m.insert(90, 900);
	m.insert(40, 400);
	m.insert(60, 600);
	m.insert(10, 100);
	m.insert(80, 800);
	m.insert(75, 750);
	m.insert(85, 850);
	//m.insert(10, 100);
	//m.insert(11, 110);
	//m.insert(12, 120);
	//m.insert(13, 130);
	//m.insert(14, 140);
	//m.insert(15, 150);
	//m.insert(16, 160);
	//m.insert(17, 170);
	BSTForwardIterator<int, int> first = m.findLast(70);
	
	cout << "toString: " << m.toString() << endl;
	cout << "val: " << first.getValue() << endl;
	BSTForwardIterator<int, int> succ = m.remove(first);
	cout << "succ val: " << succ.getValue() << endl;
	REQUIRE(succ.getValue() == 750);
	std::cout << "AFTER REQUIRE" << std::endl;
	}
}

     
