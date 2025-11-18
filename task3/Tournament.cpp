//
// Created by Leon Buchner on 18.11.25.
//
#include "Tournament.h"
#include "Team.h"
#include <stdexcept>

namespace task3 {

    Tournament::Tournament(std::string title, Team* source_teams, int size)
        : title(title), size(size), teams(copy(source_teams, size)) {}

    Team** Tournament::copy(Team* source_teams, int size) {
        Team** result = new Team*[size];
        for (int i = 0; i < size; ++i)
            result[i] = new Team(source_teams[i]);
        return result;
    }

    int Tournament::get_size() const {
        return size;
    }

    Team Tournament::get_team(int index) const {
        if (index < 0 || index >= size)
            throw std::out_of_range("Tournament index out of range");
        return *teams[index];
    }

    std::string Tournament::get_title() const {
        return title;
    }

    void Tournament::set_team(int index, const Team *team) {
        if (index < 0 || index >= size)
            throw std::out_of_range("Tournament index out of range");

        delete teams[index];
        teams[index] = new Team(*team);
    }

}