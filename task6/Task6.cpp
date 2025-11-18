//
// Created by Leon Buchner on 18.11.25.
//

#include "Tournament.h"
#include <iostream>
#include <cassert>

namespace task6 {

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

    void test() {
        Team mordor("mordor", 23);
        Team gondor("gondor");
        Team shire("shire");
        Team teams[] = {mordor, gondor, shire};
        Tournament fifa("FIFA Middleearth", teams, 3);
        std::cout << fifa << std::endl;
    }

    void test_contains() {
        Team mordor("mordor", 23);
        Team gondor("gondor");
        Team another_gondor("gondor");
        Team another_mordor("mordor");
        Team teams[] = {mordor, gondor};
        Tournament fifa("FIFA Middleearth", teams, 2);
        assert(fifa.contains(another_gondor));
        assert(!fifa.contains(another_mordor));
    }

    void test_contains_not() {
        Team mordor("mordor", 23);
        Team gondor("gondor");
        Team another_gondor("gondor");
        Team another_mordor("mordor");
        Team teams[] = {mordor, gondor};
        Tournament fifa("FIFA Middleearth", teams, 2);
        assert(!fifa.containsNot(another_gondor));
        assert(fifa.containsNot(another_mordor));
    }

    void main() {
        std::cout << "start task6 ...." << std::endl;
        test();
        test_contains();
        std::cout << "finished task6" << std::endl;
    }

}