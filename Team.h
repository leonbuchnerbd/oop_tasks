//
// Created by Leon Buchner on 28.10.25.
//

#ifndef TASK1_TEAM_H
#define TASK1_TEAM_H
#include <string>

namespace task3 {

    class Team {
        int goal = 0;
        std::string team_name;
    public:
        Team(std::string team_name, int goal);
        Team(std::string team_name);
        int get_goals() const;
        const std::string& get_name() const;
        void set(const std::string &team_name, const int goal);
    };
}

namespace task5 {

    class Team {
        int goal = 0;
        std::string team_name;
    public:
        Team(std::string team_name, int goal);
        Team(std::string team_name);
        int get_goals() const;
        const std::string& get_name() const;
        void set(const std::string &team_name, const int goal);
    };
}

#endif //TASK1_TEAM_H