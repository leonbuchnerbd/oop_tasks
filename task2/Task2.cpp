//
// Created by Leon Buchner on 18.11.25.
//
#include <cassert>
#include <iostream>

namespace task2 {

    void to_lower(std::string& str) {
        for (char &c : str) {
            if (c >= 'A' && c <= 'Z') {
                // Convert uppercase to lowercase
                // by adding 32
                c += 32;
            }
        }
    }

    int count_vowels(std::string str) {
        int count = 0;
        // A, E, I, O, U, Y
        for (char &c : str) {
            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'y')
                count++;
            if (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U' || c == 'Y')
                count++;
        }
        return count;
    }

    class Team {
        int goal = 0;
        std::string team_name;
    public:
        int get_goal() {
            return goal;
        }
        const std::string& get_name() const {
            return team_name;
        }
        void set(const std::string &teamName, const int goal) {
            this->team_name = teamName;
            this->goal = goal;
        }
    };

    void test_to_lower() {
        std::string text="HFU";
        to_lower(text);
        assert(text=="hfu");
        to_lower(text);
        assert(text=="hfu");
        text="";
        to_lower(text);
        assert(text=="");
    }

    void test_count_vowels() {
        assert(count_vowels("") == 0);
        assert(count_vowels("supercalifragilisticexpialidocious") == 16);
        assert(count_vowels("HFU")==1);
    }

    void test_team(){
        Team mordor;
        mordor.set("mordor", 23);
        assert(mordor.get_goal()==23);
        assert(mordor.get_name()=="mordor");
    }

    void main() {
        std::cout << "start task2 ...." << std::endl;
        test_to_lower();
        test_count_vowels();
        test_team();
        std::cout << "finished task2." << std::endl;
    }
}