#define CATCH_CONFIG_MAIN //makes main funct
#include "catch.hpp"
#include <iostream>
using namespace std;

//what we are testing
#include "ArrayList.hpp"
//#include "ArrayList.tpp"

TEST_CASE("TESTING ArrayList Template")
{


  SECTION("CAPACITY CONSTRUCTOR")
{
  cout << "this" << endl;
  ArrayList<int> myArr(10);
  cout << "that" << endl;
  //ArrayList<long long> myArrL(10);
  cout << "these" << endl;
  //myArr.pushFront(5);
  
  REQUIRE(myArr.getCapacity() == 10);
  REQUIRE_FALSE(myArr.getCapacity() != 10);

  //REQUIRE(myArrL.capacity == 10);
  //REQUIRE_FALSE(myArrL.capacity != 10);

  //myArr.~ArrayList();
  //myArr.~ArrayList();
  //myArrL.~ArrayList();
  //REQUIRE(myArr.getCapacity() == 10);
  //REQUIRE_FALSE(myArr.getCapacity() != 10);
  cout << "done" << endl;
}


  SECTION("TESTING PUSHFRONT")
{
  cout << "this" << endl;
  ArrayList<int> myArr2(10);
  //cout << "that" << endl;
  // ArrayList<long long> myArrL(10);
  cout << "these" << endl;
  //myArr2.insert(0, 5);
  cout << "themth" << endl;
  //myArr2.getCapacity();
  myArr2.pushFront(5);
  
  //myArr.popBack();
  //myArrL.popBack();
  
  REQUIRE(myArr2.getFront() == 5);
  REQUIRE_FALSE(myArr2.getFront() != 5);

  //REQUIRE(myArrL.capacity == 9);
  //REQUIRE_FALSE(myArrL.capacity != 9);

  myArr2.pushFront(25);

  REQUIRE(myArr2.getFront() == 25);
  REQUIRE_FALSE(myArr2.getFront() != 25);
  
  
  }

   SECTION("TESTING INSERT")
{
  ArrayList<int> myArr3(10);
  myArr3.pushFront(5);
  myArr3.pushFront(25);
  myArr3.insert(0, 45);
  REQUIRE(myArr3.getFront() == 45);
  REQUIRE_FALSE(myArr3.getFront() != 45);
  myArr3.insert(0, 33);
  REQUIRE(myArr3.getFront() == 33);
  REQUIRE_FALSE(myArr3.getFront() != 33);
  myArr3.pushFront(10);
  myArr3.pushFront(26);
  myArr3.pushFront(66);
  myArr3.insert(55, 77);
  REQUIRE(myArr3.getBack() == 77);
  REQUIRE_FALSE(myArr3.getBack() != 77);
  
  
  
  
  
  }




}


