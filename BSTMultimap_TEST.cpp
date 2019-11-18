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
    
	BSTForwardIterator<int, int> itt = m.findFirst(9);
	cout << "val: " << itt.isPastEnd() << endl;
	
	//REQUIRE(itt.getKey() == 0);
	REQUIRE(itt.isPastEnd() == true);
	//cout << "he" << endl;
	}


     SECTION("TESTING EMPTY FINDLAST"){
    BSTMultimap<int, int> m = BSTMultimap<int, int>();
    
	BSTForwardIterator<int, int> itt = m.findLast(9);
	cout << "val: " << itt.isPastEnd() << endl;
	
	//REQUIRE(itt.getKey() == 0);
	REQUIRE(itt.isPastEnd() == true);
	//cout << "he" << endl;
	}


     SECTION("TESTING FULL FINDFIRST"){
    BSTMultimap<int, int> m = BSTMultimap<int, int>();
    //REQUIRE(m.isEmpty() == true);
    //REQUIRE(m.getSize() == 0);

    m.insert(5, 50);
        m.insert(2, 20);
	m.insert(7, 60);
	m.insert(7, 50);
	m.insert(7, 70);
        m.insert(9, 90);
	m.insert(4, 40);
	m.insert(6, 60);
	cout << m.toString() << endl;
	BSTForwardIterator<int, int> itt = m.findFirst(7);
	REQUIRE(itt.getKey() == 7);
	cout << "ittVal: " << itt.getValue() << endl;
	REQUIRE(itt.getValue() == 60);
	
	BSTForwardIterator<int, int> itt2 = m.findFirst(100);
	REQUIRE(itt2.isPastEnd() == true);

	BSTForwardIterator<int, int> itt3 = m.findFirst(5);
	REQUIRE(itt3.getValue() == 50);

	BSTForwardIterator<int, int> itt4 = m.findFirst(2);
	REQUIRE(itt4.getValue() == 20);
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



        
	BSTForwardIterator<int, int> itt = m.findLast(9);
	REQUIRE(itt.getKey() == 9);

	BSTForwardIterator<int, int> itt2 = m.findLast(100);
	REQUIRE(itt2.isPastEnd() == true);

	BSTForwardIterator<int, int> itt3 = m.findLast(5);
	REQUIRE(itt3.getValue() == 50);

	BSTForwardIterator<int, int> itt4 = m.findLast(2);
	REQUIRE(itt4.getValue() == 20);
	//cout << "he" << endl;
	}

     SECTION("TESTING FINDLAST"){
    BSTMultimap<int, int> m = BSTMultimap<int, int>();
        m.insert(50, 50);
	m.insert(30, 30);
        //REQUIRE(m.getSize() == 2);
        //REQUIRE(m.toString() == "(5, 50)-(2, 20)-");
        m.insert(70, 70);
	m.insert(90, 90);
        m.insert(70, 71);
        m.insert(30, 31);
	
	m.insert(20, 20);
	m.insert(50, 51);



        
	BSTForwardIterator<int, int> itt = m.findLast(30);
	REQUIRE(itt.getValue() == 31);

	BSTForwardIterator<int, int> itt2 = m.findLast(70);
	REQUIRE(itt2.getValue() == 71);

	BSTForwardIterator<int, int> itt3 = m.findLast(50);
	REQUIRE(itt3.getValue() == 51);

	BSTForwardIterator<int, int> itt4 = m.findLast(90);
	REQUIRE(itt4.getValue() == 90);
	
	}


     SECTION("TESTING REMOVE"){
       cout << "STARTING REG REMOVE OF THE ROOT METHOD" << endl;
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
	cout << "copy.getValue(): " << copy.getValue() << endl;
	BSTForwardIterator<int, int> copySucc = m.remove(copy);
	REQUIRE(copySucc.getValue() == 70);
	cout << "copySucc: " << copySucc.getValue() << endl;
	//BSTForwardIterator<int, int> minSucc = m.remove(min);

	//REQUIRE(minSucc.getValue() == 40);
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
	cout << "size of multimap BEFORE remove: " << m.getSize() << endl;
	BSTForwardIterator<int, int> succ = m.remove(first);
	cout << "size of multimap AFTER remove: " << m.getSize() << endl;

	cout << "succ val: " << succ.getValue() << endl;
	cout << "succ key: " << succ.getKey() << endl;
	cout << "is succ a sent? " << succ.isPastEnd() << endl;
	REQUIRE(succ.getValue() == 750);
	REQUIRE(succ.getKey() == 75);
	std::cout << "AFTER REQUIRE" << std::endl;
	}

	 SECTION("TESTING REMOVE"){
       cout << "STARTING REG REMOVE OF THE ROOT METHOD" << endl;
       BSTMultimap<int, int> m = BSTMultimap<int, int>();
        m.insert(6, 60);
        m.insert(2, 20);
        m.insert(8, 80);
        m.insert(8, 81);
        m.insert(7, 70);
        
	BSTForwardIterator<int, int> sixty = m.findFirst(6);
	//BSTForwardIterator<int, int> copy = min;
	//copy.next();
	//copy.next();
	m.remove(sixty);
	cout << m.toString() << endl;
	//REQUIRE(copy.getValue() == 50);
	//cout << "copy.getValue(): " << copy.getValue() << endl;
	//BSTForwardIterator<int, int> copySucc = m.remove(copy);
	//REQUIRE(copySucc.getValue() == 70);
	//cout << "copySucc: " << copySucc.getValue() << endl;

	 }


	/**SECTION("TESTING INSERT NEWNODE"){
    BSTMultimap<int, int> m = BSTMultimap<int, int>();
    //REQUIRE(m.isEmpty() == true);
    //REQUIRE(m.getSize() == 0);

    m.insert(5, 50);
        m.insert(2, 20);
	m.insert(7, 60);
	m.insert(7, 50);
	m.insert(7, 70);
        m.insert(9, 90);
	m.insert(4, 40);
	BSTNode<int, int>* newNode = new BSTNode<int, int>(6, 60);
	m.insertNode(newNode);
	
	cout << m.toString() << endl;
	cout << "DONE" << endl;
	
	REQUIRE(m.contains(6));

	BSTForwardIterator<int, int> itt = m.findFirst(6);
	REQUIRE(itt.getValue() == 60);
	
	//delete newNode;
	}**/

	
}

     
