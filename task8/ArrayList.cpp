//
// Created by Leon Buchner on 02.12.25.
//

#include "ArrayList.h"

namespace task8 {

    ArrayList::ArrayList(int initialCapacity):
        data(new int[initialCapacity]),
        capacity(initialCapacity),
        size(0)
    {}

    void ArrayList::add(const int value) {
        if (size == capacity) {
            int newCapacity = capacity * 2;
            std::unique_ptr<int[]> newData(new int[newCapacity]);
            for (int i = 0; i < size; i++) {
                newData[i] = data[i];
            }
            data = std::move(newData);
            capacity = newCapacity;
        }
        data[size] = value;
        size++;
    }
    int ArrayList::get(int index) const {
        return data[index];
    }

}