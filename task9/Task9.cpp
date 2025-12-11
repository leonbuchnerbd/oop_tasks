//
// Created by Leon Buchner on 11.12.25.
//

#include "Task9.h"

#include <vector>
#include <cassert>
#include <iostream>
#include <algorithm>

#include "Team.h"
#include "Tournament.h"

namespace task9 {

    void task1A() {
        int numbers[] = {4,7,1,1};
        std::vector<int> numbersVector(numbers, numbers+4);
        assert(numbersVector.size()==4);
        numbers[3]=23;
        assert(numbersVector[3]==1);
        std::cout << "task1A done." << std::endl;
    }

    void task1B() {
        std::vector<int> numbers {4,7,1,1};
        bool is_contained=find(numbers.begin(), numbers.end(), 7)!=numbers.end();
        assert(is_contained);
        std::cout << "task1B done." << std::endl;
    }

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

    void task2_team() {
        Team mordor("mordor", 23);
        Team gondor("gondor");
        gondor = mordor;
        assert(gondor==mordor);
        std::cout << "task2_team done." << std::endl;
    }

    void task2_tournament() {
        Team mordor("mordor", 23);
        Team gondor("gondor");
        Team teams[] = {mordor, gondor};
        Tournament fifa("FIFA Middleearth", teams, 2);
        Tournament copy("Nothing", nullptr, 0);
        copy = fifa;
        assert(copy == fifa);
        fifa.remove(0);
        assert(copy.get_team(0) == mordor);
        std::cout << "task2_tournament done." << std::endl;

    }

    bool is_shaken(const std::string& a, const std::string& b) {
        if (a.size() != b.size())
            return false; // direkt falsch

        std::vector<int> count(256, 0); // einfache Zähltabelle für ASCII

        for (char c : a)
            count[(unsigned char)c]++; // buchstaben hochzählen

        for (char c : b)
            count[(unsigned char)c]--; // buchstaben löschen

        for (int x : count)
            if (x != 0) // wenn nicht alles 0 ist, dann sind die Buchstaben nicht gleich
                return false;

        return true;
    }

    void shaken_test() {
        assert(is_shaken("erbgut","betrug"));
        assert(is_shaken("erbgut","geburt"));
        assert(!is_shaken("betrux","geburt"));
        std::cout << "shaken_test done." << std::endl;
    }

    void main() {
        std::cout << "start task8 ...." << std::endl;
        task1A();
        task1B();
        task2_team();
        task2_tournament();
        shaken_test();
        std::cout << "finished task8" << std::endl;
    }
}
