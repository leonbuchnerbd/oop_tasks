//
// Created by Leon Buchner on 18.11.25.
//

#ifndef TASK1_TEAM_H
#define TASK1_TEAM_H

#include <iostream>

namespace task9 {
    class Team {
        int goal = 0;
        std::string team_name;
    public:
        Team(std::string team_name, int goal);
        Team(std::string team_name);
        int get_goals() const;
        const std::string& get_name() const;
        void set(const std::string &team_name, const int goal);
        bool operator==(const Team &) const;
        bool operator!=(const Team &) const;
        bool operator<(const Team &) const;
    };
}

#endif //TASK1_TEAM_H