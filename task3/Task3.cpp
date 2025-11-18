//
// Created by Leon Buchner on 18.11.25.
//
#include <cassert>
#include <iostream>
#include "Team.h"
#include "Tournament.h"
#include "Task3.h"

namespace task3 {

    void test_team(){
        Team mordor("mordor", 23);
        assert(mordor.get_goals()==23);
        assert(mordor.get_name()=="mordor");
        Team gondor("gondor");
        assert(gondor.get_goals()==0);
        assert(gondor.get_name()=="gondor");
    }


    void test_tournament() {
        Team mordor("mordor", 23);
        Team gondor("gondor");
        Team shire("shire");
        Team teams[]={mordor, gondor, shire};
        Tournament fifa("FIFA Middleearth", teams, 3);
        assert(fifa.get_team(0).get_name()=="mordor");
        assert(fifa.get_size()==3);
        assert(fifa.get_title()=="FIFA Middleearth");
        teams[0] = Team("rohan", 4711);
        assert(fifa.get_team(0).get_name()=="mordor");

        // new test
        bool threw = false;
        try {
            std::cout << fifa.get_team(15).get_name() << std::endl;
        }catch (const std::out_of_range e) {
            std::cout << e.what() << " - get_team()"<< std::endl;
            threw = true;
        }
        assert(threw && "std::out_of_range Tournament index out of range");

        Team test("test");
        fifa.set_team(0, &test);
        assert(fifa.get_team(0).get_name()=="test");

        Team test2("test2");
        bool threw2 = false;
        try {
            fifa.set_team(15, &test2);
        }catch (const std::out_of_range e) {
            std::cout << e.what() << " - set_team()" << std::endl;
            threw2 = true;
        }
        assert(threw2 && "std::out_of_range Tournament index out of range - set_team");
    }

    void main() {
        std::cout << "start task3 ...." << std::endl;
        test_team();
        test_tournament();
        std::cout << "finished task3." << std::endl;
    }
}