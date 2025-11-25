//
// Created by Leon Buchner on 18.11.25.
//

#include "Tournament.h"
#include <iostream>
#include <cassert>

namespace task7 {

    std::ostream& operator<<(std::ostream& os, const Team& t) {
        os << t.get_name() << ": " << t.get_goals();
        return os;
    }

    std::ostream& operator<<(std::ostream& os, const Tournament& t) {
        os << t.get_title() << std::endl;

        for (int i = 0; i < t.get_size(); i++) {
            os << t.get_team(i);
            if (i != t.get_size() - 1) {
                os << ", ";
            }
        }
        os << std::endl;

        return os;
    }

    void task1A() {
        Team mordor("mordor", 23);
        Team gondor("gondor");
        gondor = mordor;
        assert(gondor==mordor);
    }

    void task1B() {
        Team mordor("mordor", 23);
        Team gondor("gondor");
        Team teams[] = {mordor, gondor};
        Tournament fifa("FIFA Middleearth", teams, 2);
        Tournament copy("Nothing", nullptr, 0);
        copy = fifa;
        assert(copy == fifa);
        fifa.remove(0);
        assert(copy.get_team(0) == mordor);

    }

    void main() {
        std::cout << "start task6 ...." << std::endl;
        task1A();
        std::cout << "finished task6" << std::endl;
    }

}