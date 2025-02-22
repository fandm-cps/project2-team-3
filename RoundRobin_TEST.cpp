#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "Scheduler.hpp"
#include "Process.hpp"
#include <iostream>

using namespace std;

TEST_CASE("Testing RoundRobin Scheduler"){

    SECTION("CPU Processes"){
        RoundRobin a;
        CPUBoundProcess p1(1);

        a.addProcess(&p1);
        REQUIRE(a.popNext(0)->getID() == 1);

        FastRoundRobin b;
	    b.addProcess(&p1);
	    REQUIRE(b.popNext(0)->getID() == 1);
    }

    SECTION("I/O Processes"){
        RoundRobin a;
        IOBoundProcess p1(1);

        p1.useCPU(0, 20);

        a.addProcess(&p1);
        REQUIRE(p1.isBlocked(0) == true);
        REQUIRE(a.popNext(20) == 0);

        FastRoundRobin b;
	    b.addProcess(&p1);
	    REQUIRE(p1.isBlocked(0) == true);
        REQUIRE(b.popNext(20) == 0);
    }
}