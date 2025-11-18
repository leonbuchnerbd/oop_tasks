//
// Created by Leon Buchner on 18.11.25.
//

#ifndef TASK1_TOURNAMENT_H
#define TASK1_TOURNAMENT_H
#include <iostream>
#include "Team.h"
#include "Tournament.h"

namespace task6 {
    class Tournament {
        int size = 0;
        Team** teams;
        std::string title;
        static Team** copy(Team* source_teams, int size);
        static Team** copy_from_array(const Team* source, int size);
        static Team** copy_from_pointers(Team* const* source, int size);
    public:
        Tournament(std::string title, Team* teams,int size);
        Tournament(const Tournament& other);
        ~Tournament();
        void set_team(int index, const Team *team);
        std::string get_title() const;
        int get_size() const;
        Team get_team(int index) const;
        void remove(int index);
        bool contains(const Team &other) const;
        bool containsNot(const Team &other) const;
    };

    std::ostream operator<<(const std::ostream & lhs, const Tournament & rhs);
    std::ostream& operator<<(std::ostream& os, const Tournament& t);

}

#endif //TASK1_TOURNAMENT_H