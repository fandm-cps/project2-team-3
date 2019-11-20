#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "Scheduler.hpp"
#include "Process.hpp"
#include <iostream>

using namespace std;

TEST_CASE("Testing CompletelyFair Scheduler"){
    
    SECTION("CPU Processes"){
        CompletelyFair a;
        CPUBoundProcess p1(1);

        a.addProcess(&p1);
        REQUIRE(a.popNext(0)->getID() == 1);
    }

    SECTION("I/O Processes"){
        CompletelyFair b;
        CPUBoundProcess p1(1);

	    b.addProcess(&p1);
	    REQUIRE(p1.isBlocked(0) == false);
        REQUIRE(b.popNext(20)->getID() == 1);
    }

    SECTION("CPU Processes"){
        FastCompletelyFair a;
        CPUBoundProcess p1(1);

        a.addProcess(&p1);
        REQUIRE(a.popNext(0)->getID() == 1);
   }
}
