//
// Created by Leon Buchner on 18.11.25.
//
#include "Task5.h"
#include <iostream>
#include <cassert>
#include "Team.h"
#include "Tournament.h"

namespace task5 {

    void test_team(){
        Team mordor("mordor", 23);
        assert(mordor.get_goals()==23);
        assert(mordor.get_name()=="mordor");
        Team gondor("gondor");
        assert(gondor.get_goals()==0);
        assert(gondor.get_name()=="gondor");
    }


    void test() {
        Team mordor("mordor", 23);
        Team gondor("gondor");
        Team shire("shire");
        Team teams[] = {mordor, gondor};
        {
            Tournament fifa("FIFA Middleearth", teams, 2);
            auto copy=fifa;
            fifa.set_team(1,&shire);
            assert(fifa.get_team(1).get_name()=="shire");
            //std::cout << "Teamname: " << copy.get_team(1).get_name() << std::endl;
            assert(copy.get_team(1).get_name()=="gondor");
        }
        {
            Tournament fifa("FIFA Middleearth", teams, 2);
            fifa.set_team(1,&shire);
            auto copy = fifa;
            assert(fifa.get_team(1).get_name()=="shire");
            //std::cout << "Teamname: " << copy.get_team(1).get_name() << std::endl;
            assert(copy.get_team(1).get_name()=="shire");
        }
    }
    void test_remove() {
        Team mordor("mordor", 23);
        Team gondor("gondor");
        Team shire("shire");
        Team teams[] = {mordor, gondor, shire};
        Tournament fifa("FIFA Middleearth", teams, 3);
        std::cout << "BeforeFifaName: " << fifa.get_team(0).get_name() << std::endl;
        std::cout << "BeforeFifaName: " << fifa.get_team(1).get_name() << std::endl;
        std::cout << "BeforeFifaName: " << fifa.get_team(2).get_name() << std::endl;
        fifa.remove(1);
        std::cout << "FifaName: " << fifa.get_team(0).get_name() << std::endl;
        std::cout << "FifaName: " << fifa.get_team(1).get_name() << std::endl;
        assert(fifa.get_team(1).get_name()=="shire");
        assert(fifa.get_size()==2);
    }
    void main() {
        std::cout << "start task5 ...." << std::endl;
        test();
        test_remove();
        std::cout << "finished task5." << std::endl;
    }
}