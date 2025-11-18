//
// Created by Leon Buchner on 18.11.25.
//
#include <cassert>
#include <iostream>
#include "Task1.h"

namespace task1 {
    bool is_same(int *left, int *right, int size) {
        for (int i = 0; i < size; i++) {
            if (left[i] != right[i]) {
                return false; // error not same
            }
        }
        return true;
    }

    void test_is_same() {
        int left[]{4, 7, 1, 1};
        int right[]{4, 7, 1, 1};
        assert(is_same(left, right, 4));
        right[3] = 3;
        assert(!is_same(left, right, 4));
    }

    int digits(int number) {
        int count = 0;
        while (number != 0) {
            number /= 10;
            count++;
        }
        return count;
    }

    void test_digits() {
        assert(digits(4711) == 4);
        assert(digits(-4711) == 4);
        assert(digits(0) == 0);
    }

    int* to_array(int number, int &size) {
        size = digits(number);
        int* heap_array = new int[size];
        for (int i = 0; i < size; i++) {
            heap_array[i] = number % 10;
            number /= 10;
        }
        return heap_array;
    }

    void test_to_array() {
        int size = 0;
        int *parts = to_array(4711, size);
        assert(size == 4);
        int expected[]{1, 1, 7, 4};
        assert(is_same(parts,expected,4));
        delete[] parts;
    }

    bool is_palindrome(int number) {
        if (number < 0) {
            return false;
        }
        int size = 0;
        int* digits = to_array(number, size);

        for (int i = 0; i < size / 2; i++) {
            if (digits[i] != digits[size - 1 - i]) {
                delete[] digits;
                return false;
            }
        }

        delete[] digits;
        return true;
    }

    void test_is_palindrome() {
        assert(is_palindrome(0));
        assert(is_palindrome(121));
        assert(!is_palindrome(-121)); // number is negative
        assert(!is_palindrome(4711));
    }

    void main() {
        std::cout << "start task1 ...." << std::endl;
        test_is_same();
        test_digits();
        test_to_array();
        test_is_palindrome();
        std::cout << "finished task1." << std::endl;
    }
}