#include <assert.h>
#include <iostream>
#include "Team.h"
#include "Tournament.h"

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

namespace task3 {
    Team::Team(std::string team_name) : team_name(team_name), goal(0) {}
    Team::Team(std::string team_name, int goal) : team_name(team_name), goal(goal) {}

    void Team::set(const std::string &team_name, const int goal) {
        this->team_name = team_name;
        this->goal = goal;
    }

    int Team::get_goals() const {
        return goal;
    }

    const std::string &Team::get_name() const {
        return team_name;
    }

    void test_team(){
        Team mordor("mordor", 23);
        assert(mordor.get_goals()==23);
        assert(mordor.get_name()=="mordor");
        Team gondor("gondor");
        assert(gondor.get_goals()==0);
        assert(gondor.get_name()=="gondor");
    }

    // da wir hier eine Klasse mit team_namen haben, würde es keinen Sinn machen ein leeres Team zu erstellen

    Tournament::Tournament(std::string title, Team *source_teams, int size)
    : title(title), size(size),teams(copy(source_teams,size))
    {}
    Team** Tournament::copy(Team* source_teams, int size) {
        Team** result = new Team*[size];
        for (int i = 0; i < size; ++i) {
            result[i] = new Team(source_teams[i]);
        }
        return result;
    }

    int Tournament::get_size() const {
        return size;
    }
    Team Tournament::get_team(int index) const {
        if (index < 0 || index >= get_size()) {
            throw std::out_of_range("Tournament index out of range");
        }
        return *teams[index];
    }
    std::string Tournament::get_title() const {
        return title;
    }

    void Tournament::set_team(int index, const Team *team) {
        if (index < 0 || index >= get_size()) {
            throw std::out_of_range("Tournament index out of range");
        }
        teams[index] = new Team(*team);
    }


    void test_tournament() {
        Team mordor("mordor", 23);
        Team gondor("gondor");
        Team shire("shire");
        Team teams[]={mordor, gondor, shire};
        Tournament fifa("FIFA Middleearth", teams, 3);
        assert(fifa.get_team(0).get_name()=="mordor");
        assert(fifa.get_size()==3);
        assert(fifa.get_title()=="FIFA Middleearth");
        teams[0] = Team("rohan", 4711);
        assert(fifa.get_team(0).get_name()=="mordor");

        // new test
        bool threw = false;
        try {
            std::cout << fifa.get_team(15).get_name() << std::endl;
        }catch (const std::out_of_range e) {
            std::cout << e.what() << " - get_team()"<< std::endl;
            threw = true;
        }
        assert(threw && "std::out_of_range Tournament index out of range");

        Team test("test");
        fifa.set_team(0, &test);
        assert(fifa.get_team(0).get_name()=="test");

        Team test2("test2");
        bool threw2 = false;
        try {
            fifa.set_team(15, &test2);
        }catch (const std::out_of_range e) {
            std::cout << e.what() << " - set_team()" << std::endl;
            threw2 = true;
        }
        assert(threw2 && "std::out_of_range Tournament index out of range - set_team");
    }

    void main() {
        std::cout << "start task3 ...." << std::endl;
        test_team();
        test_tournament();
        std::cout << "finished task3." << std::endl;
    }
}

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

namespace task5 {

    Team::Team(std::string team_name) : team_name(team_name), goal(0) {}
    Team::Team(std::string team_name, int goal) : team_name(team_name), goal(goal) {}

    void Team::set(const std::string &team_name, const int goal) {
        this->team_name = team_name;
        this->goal = goal;
    }

    int Team::get_goals() const {
        return goal;
    }

    const std::string &Team::get_name() const {
        return team_name;
    }

    void test_team(){
        Team mordor("mordor", 23);
        assert(mordor.get_goals()==23);
        assert(mordor.get_name()=="mordor");
        Team gondor("gondor");
        assert(gondor.get_goals()==0);
        assert(gondor.get_name()=="gondor");
    }

    // da wir hier eine Klasse mit team_namen haben, würde es keinen Sinn machen ein leeres Team zu erstellen

    Tournament::Tournament(std::string title, Team *source_teams, int size)
    : title(title), size(size),teams(copy_from_array(source_teams,size))
    {}
    Tournament::Tournament(const Tournament& other)
    : title(other.title), size(other.size), teams(copy_from_pointers(other.teams, other.size)) {}

    Team** Tournament::copy(Team* source_teams, int size) {
        Team** result = new Team*[size];
        for (int i = 0; i < size; ++i) {
            result[i] = new Team(source_teams[i]);
        }
        return result;
    }
    Team** Tournament::copy_from_array(const Team* source, int size) {
        Team** result = new Team*[size];
        for (int i = 0; i < size; ++i)
            result[i] = new Team(source[i]);
        return result;
    }

    Team** Tournament::copy_from_pointers(Team* const* source, int size) {
        Team** result = new Team*[size];
        for (int i = 0; i < size; ++i)
            result[i] = new Team(*source[i]);
        return result;
    }
    Tournament::~Tournament() {
        for (int i = 0; i < size; ++i) {
            delete teams[i];
        }
        delete [] teams;
    }

    int Tournament::get_size() const {
        return size;
    }
    Team Tournament::get_team(int index) const {
        if (index < 0 || index >= get_size()) {
            throw std::out_of_range("Tournament index out of range");
        }
        return *teams[index];
    }
    std::string Tournament::get_title() const {
        return title;
    }

    void Tournament::set_team(int index, const Team *team) {
        if (index < 0 || index >= get_size()) {
            throw std::out_of_range("Tournament index out of range");
        }
        delete teams[index];
        teams[index] = new Team(*team);
    }

    void Tournament::remove(int index) {
        if (index < 0 || index >= get_size()) {
            throw std::out_of_range("Tournament index out of range");
        }
        delete teams[index];
        Team** newTeams = new Team*[size - 1];
        for (int i = 0, j = 0; i < size; ++i) {
            if (i == index) continue;
            newTeams[j++] = teams[i];
        }
        delete[] teams;
        teams = newTeams;
        size -= 1;
    }


    void test() {
        Team mordor("mordor", 23);
        Team gondor("gondor");
        Team shire("shire");
        Team teams[] = {mordor, gondor};
        {
            Tournament fifa("FIFA Middleearth", teams, 2);
            auto copy=fifa;
            fifa.set_team(1,&shire);
            assert(fifa.get_team(1).get_name()=="shire");
            //std::cout << "Teamname: " << copy.get_team(1).get_name() << std::endl;
            assert(copy.get_team(1).get_name()=="gondor");
        }
        {
            Tournament fifa("FIFA Middleearth", teams, 2);
            fifa.set_team(1,&shire);
            auto copy = fifa;
            assert(fifa.get_team(1).get_name()=="shire");
            //std::cout << "Teamname: " << copy.get_team(1).get_name() << std::endl;
            assert(copy.get_team(1).get_name()=="shire");
        }
    }
    void test_remove() {
        Team mordor("mordor", 23);
        Team gondor("gondor");
        Team shire("shire");
        Team teams[] = {mordor, gondor, shire};
        Tournament fifa("FIFA Middleearth", teams, 3);
        std::cout << "BeforeFifaName: " << fifa.get_team(0).get_name() << std::endl;
        std::cout << "BeforeFifaName: " << fifa.get_team(1).get_name() << std::endl;
        std::cout << "BeforeFifaName: " << fifa.get_team(2).get_name() << std::endl;
        fifa.remove(1);
        std::cout << "FifaName: " << fifa.get_team(0).get_name() << std::endl;
        std::cout << "FifaName: " << fifa.get_team(1).get_name() << std::endl;
        assert(fifa.get_team(1).get_name()=="shire");
        assert(fifa.get_size()==2);
    }
    void main() {
        std::cout << "start task5 ...." << std::endl;
        test();
        test_remove();
        std::cout << "finished task5." << std::endl;
    }
}

namespace task6 {

    std::ostream& operator<<(std::ostream& os, const task5::Team& t) {
        os << t.get_name() << ": " << t.get_goals();
        return os;
    }

    std::ostream& operator<<(std::ostream& os, const task5::Tournament& t) {
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
        task5::Team mordor("mordor", 23);
        task5::Team gondor("gondor");
        task5::Team shire("shire");
        task5::Team teams[] = {mordor, gondor, shire};
        task5::Tournament fifa("FIFA Middleearth", teams, 3);
        std::cout << fifa << std::endl;
    }

    void test_contains() {
        task5::Team mordor("mordor", 23);
        task5::Team gondor("gondor");
        task5::Team another_gondor("gondor");
        task5::Team another_mordor("mordor");
        task5::Team teams[] = {mordor, gondor};
        task5::Tournament fifa("FIFA Middleearth", teams, 2);
        assert(fifa.contains(another_gondor));
        assert(!fifa.contains(another_mordor));
    }

    void main() {
        std::cout << "start task6 ...." << std::endl;
        test();
        std::cout << "finished task6" << std::endl;
    }

}

int main() {
    std::cout << "start testing ...." << std::endl;
    /*task1::main();
    task2::main();
    task3::main();
    task4::main();
    task4::main();
    task5::main();*/
    task6::main();
    std::cout << "All done." << std::endl;
    return 0;
}