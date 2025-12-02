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
        std::cout << "----Vergleich-----" << std::endl;
        std::cout << "Copy:" << std::endl;
        std::cout << copy << std::endl;
        std::cout << "Fifa:" << std::endl;
        std::cout << fifa << std::endl;
        std::cout << "-------------" << std::endl;
        assert(copy == fifa);
        fifa.remove(0);
        std::cout << "----Vergleich-----" << std::endl;
        std::cout << "Copy:" << std::endl;
        std::cout << copy << std::endl;
        std::cout << "fifa:" << std::endl;
        std::cout << fifa << std::endl;
        std::cout << "-------------" << std::endl;
        std::cout << copy.get_team(0) << std::endl;
        assert(copy.get_team(0) == mordor);
        std::cout << "solved task1B" << std::endl;

    }

    void swap(int &a, int &b) noexcept {
        const int temp = a;
        a = b;
        b = temp;
    }

    void sort(int *array, const int size) {
        for (int i = 0; i < size - 1; i++) {
            int min_idx = i;
            for (int j = i + 1; j < size; j++) {
                if (array[j] < array[min_idx])
                    min_idx = j;
            }
            swap(array[min_idx], array[i]);
        }
    }

    void testSort() {
        int data[] = {20, 12, 10, 15, 2};
        int data_sorted[] = {2, 10, 12, 15, 20};
        int size = sizeof(data) / sizeof(data[0]);
        sort(data, size);
        for (int i = 0; i < size; i++) {
            assert(data[i] == data_sorted[i]);
        }
        std::cout << "solved testSort" << std::endl;
    }

    void swap(Team &a, Team &b) noexcept {
        const Team temp = a;
        a = b;
        b = temp;
    }

    void sort(Team *array, int size) {
        for (int i = 0; i < size - 1; i++) {
            int min_idx = i;
            for (int j = i + 1; j < size; j++) {
                if (array[j] < array[min_idx])
                    min_idx = j;
            }
            swap(array[min_idx], array[i]);
        }
    }

    void swapTestTeam() {
        Team mordor1("mordor", 42);
        Team mordor2("mordor", 23);
        Team gondor("gondor",4711);
        int size=3;
        Team teams[] = {mordor1, mordor2, gondor};
        //                   4711,      42,            23
        Team expected[] = {gondor, mordor1, mordor2}; // morder 1 und 2 verwechselt
        sort(teams, size);
        for (int i = 0; i < size; i++) {
            //std::cout << "Platz " << i+1 << std::endl;
            //std::cout << "current: " << teams[i].get_name() << " Goals: " << teams[i].get_goals()<< std::endl;
            //std::cout << "expected: " << expected[i].get_name() << " Goals: " << expected[i].get_goals() << std::endl;
            assert(teams[i] == expected[i]);
        }
        std::cout << "solved swapTestTeam" << std::endl;
    }

    void main() {
        std::cout << "start task7 ...." << std::endl;
        task1A();
        task1B();
        testSort();
        swapTestTeam();
        std::cout << "finished task7" << std::endl;
    }

}