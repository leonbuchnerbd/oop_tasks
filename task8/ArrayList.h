//
// Created by Leon Buchner on 02.12.25.
//

#ifndef TASK1_ARRAYLIST_H
#define TASK1_ARRAYLIST_H
#include <memory>

namespace task8 {
    class ArrayList {
    private:
        std::unique_ptr<int[]> data;
        int capacity;
        int size;

    public:
        ArrayList(int initialCapacity);
        void add(int value);
        int get(int index) const;
    };
}


#endif //TASK1_ARRAYLIST_H