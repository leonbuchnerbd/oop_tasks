//
// Created by Leon Buchner on 28.10.25.
//

#ifndef TASK1_TOURNAMENT_H
#define TASK1_TOURNAMENT_H
#include "Team.h"
#include <string>

namespace task3 {

    class Tournament {
        int size = 0;
        Team** teams;
        std::string title;
        static Team** copy(Team* source_teams, int size);
    public:
        //Team * copy(const Team * team, int size);
        Tournament(std::string title, Team* teams,int size);
        void set_team(int index, const Team *team);
        std::string get_title() const;
        int get_size() const;
        Team get_team(int index) const;

    };
}

namespace task5 {

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

    };
}

namespace task6 {
    std::ostream operator<<(const std::ostream & lhs, const task5::Tournament & rhs);

}
#endif //TASK1_TOURNAMENT_H