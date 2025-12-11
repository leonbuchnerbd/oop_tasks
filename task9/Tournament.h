//
// Created by Leon Buchner on 18.11.25.
//

#ifndef TASK1_TOURNAMENT_H
#define TASK1_TOURNAMENT_H
#include <iostream>
#include "Team.h"
#include "Tournament.h"

namespace task9 {
    class Tournament {
        std::vector<Team> teams;
        std::string title;
        int size{};
        //static Team** copy(Team* source_teams, int size); // fällt weg
        static std::vector<Team> copy_from_array(const Team *source, int size);
        //static Team** copy_from_pointers(Team* const* source, int size); // fällt weg
    public:
        Tournament(std::string title, Team* teams,int size);
        Tournament(const Tournament& other);
        Tournament& operator=(const Tournament& other);
        //~Tournament(); // fällt weg
        void set_team(int index, const Team *team);
        std::string get_title() const;
        Team get_team(int index) const;
        int get_size() const;
        void remove(int index);
        bool contains(const Team &other) const;
        bool containsNot(const Team &other) const;
        bool operator==(const Tournament &) const;
    };

    std::ostream operator<<(const std::ostream & lhs, const Tournament & rhs);
    std::ostream& operator<<(std::ostream& os, const Tournament& t);

}

#endif //TASK1_TOURNAMENT_H