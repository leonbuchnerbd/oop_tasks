//
// Created by Leon Buchner on 18.11.25.
//

#include "Task4.h"
#include <iostream>
#include <cassert>

namespace task4 {
    int gcd(int v, int w){
        if (v==0 && w==0)
            throw std::invalid_argument("arguments must not be equal zero");
        while(w!=0){
            int old_w=w;
            w=v%w;
            v=old_w;
        }
        return abs(v);
    }

    void test_gcd() {
        assert(gcd(2,3)==1);
        assert(gcd(3,12)==3);
        bool threw = false;
        try {
            gcd(0,0);
        } catch (const std::invalid_argument& e) {
            std::cout << e.what() << " - gcd(0,0)" << std::endl;
            threw = true;
        }
        assert(threw && "Expected std::invalid_argument to be thrown");
    }

    // Variante 1: für int*-Arrays (normale Zahlen)
    int** copy(const int* numbers, int size) {
        int** result = new int*[size];
        for (int i = 0; i < size; ++i)
            result[i] = new int(numbers[i]);
        return result;
    }

    // Variante 2: für int**-Arrays (Pointer auf Pointer)
    int** copy(const int* const* numbers, int size) {
        int** result = new int*[size];
        for (int i = 0; i < size; ++i)
            result[i] = new int(*numbers[i]);
        return result;
    }

    void test_copy_error() {
        /*
         * error,
         * da eine referenz auf eine referenz
         * ist und der zeiger nur auf den anfang geht
         * und nicht auf das element
         *
         */
        /*
         int size=4;
        int numbers[]{4, 7, 1, 1};
        int** numbers_copy= copy(numbers, size);
        numbers_copy[1]=new int(23);
        numbers_copy=copy(*numbers_copy,size);
        for (int i = 0; i < size; ++i) {
            if (i!=1)
                assert(*numbers_copy[i]== numbers[i]);
            else
                assert(*numbers_copy[i]== 23);
        }*/
    }

    void should_success() {
        int size=4;
        int numbers[]{4, 7, 1, 1};
        int** numbers_copy= copy(numbers, size);
        numbers_copy[1]=new int(23);
        numbers_copy=copy(numbers_copy,size); //different from c.
        for (int i = 0; i < size; ++i) {
            if (i!=1)
                assert(*numbers_copy[i]== numbers[i]);
            else
                assert(*numbers_copy[i]== 23); // stern muss dazu
        }
    }

    void test_last() {
        int size=4;
        int numbers[]{4, 7, 1, 1};
        int** numbers_copy= copy(numbers, size);
        numbers_copy=copy(numbers_copy,size);
        for (int i = 0; i < size; ++i) {
            assert(*numbers_copy[i]== numbers[i]);
        }
    }

    void test_copy() {
       // test_copy_success();
        should_success();
        //test_copy_error();
        test_last();
    }

    void main() {
        std::cout << "start task4 ...." << std::endl;
        test_gcd();
        test_copy();
        std::cout << "finished task4." << std::endl;
    }

}