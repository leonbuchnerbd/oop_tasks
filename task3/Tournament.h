//
// Created by Leon Buchner on 18.11.25.
//

#ifndef TASK1_TOURNAMENT_H
#define TASK1_TOURNAMENT_H
#include <iostream>
#include "Team.h"
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

#endif //TASK1_TOURNAMENT_H