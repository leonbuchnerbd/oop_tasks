//
// Created by Leon Buchner on 02.12.25.
//

#include "Task8.h"

#include <cassert>
#include <iostream>

#include "ArrayList.h"
#include "Team.h"

namespace task8 {

    void arrayTest() {
        ArrayList numbers(2);
        numbers.add(4);
        numbers.add(7);
        numbers.add(1);
        assert(numbers.get(0)==4);
        assert(numbers.get(1)==7);
        assert(numbers.get(2)==1);
        std::cout << "solved arraylist test" << std::endl;
    }

    template<typename T>
    void swap(T &a, T &b) noexcept {
        const T temp = a;
        a = b;
        b = temp;
    }

    template<typename T>
    void sort(T *array, const int size) {
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
        std::cout << "start task8 ...." << std::endl;
        arrayTest();
        testSort();
        swapTestTeam();
        // unique pointer bricht es direkt ab
        std::cout << "finished task8" << std::endl;
    }
}
