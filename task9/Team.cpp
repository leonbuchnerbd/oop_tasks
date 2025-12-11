//
// Created by Leon Buchner on 18.11.25.
//

#include "Team.h"

namespace task9 {
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

    bool Team::operator==(const Team &other) const {
        return team_name == other.team_name && goal == other.goal;
    }
    bool Team::operator!=(const Team &other) const {
        return team_name != other.team_name || goal != other.goal;
    }
    bool Team::operator<(const Team &other) const {
        return other.goal < goal;
    }
}