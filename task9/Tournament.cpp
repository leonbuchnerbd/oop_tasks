//
// Created by Leon Buchner on 18.11.25.
//
#include "Tournament.h"
#include <iostream>

namespace task9 {
    Tournament::Tournament(std::string title, Team* source_teams, int size)
        : title(title), teams(copy_from_array(source_teams, size)), size(size) {}

    Tournament::Tournament(const Tournament& other)
        : title(other.title), teams(other.teams), size(other.size) {}

    Tournament& Tournament::operator=(const Tournament& other) {
        if (this == &other) {
            return *this;
        }

        title = other.title;
        size = other.size;
        teams = other.teams;

        return *this;
    }

    int Tournament::get_size() const {
        return size;
    }


    std::vector<Team> Tournament::copy_from_array(const Team *source, int size) {
        return std::vector<Team>(source, source + size);
    }

    Team Tournament::get_team(int index) const {
        /*if (index < 0 || index >= teams.size())
            throw std::out_of_range("Tournament index out of range");
        */
        return teams[index];
    }

    std::string Tournament::get_title() const {
        return title;
    }

    void Tournament::set_team(int index, const Team *team) {
        if (index < 0 || index >= size)
            throw std::out_of_range("Tournament index out of range - set");
        teams[index] = Team(*team);
    }

    void Tournament::remove(int index) {
        if (index < 0 || index >= size)
            throw std::out_of_range("Tournament index out of range - remove");

        teams.erase(teams.begin() + index);
        size--;
    }

    bool Tournament::contains(const Team& other) const {
        for (int i = 0; i < teams.size(); ++i) {
            if (get_team(i) == other) {
                return true;
            }
        }
        return false;
    }

    bool Tournament::containsNot(const Team& other) const {
        return !contains(other);
    }

    bool Tournament::operator==(const Tournament &other) const {
        if (teams.size() != other.teams.size()) {
            return false;
        }
        if (title != other.title) {
            return false;
        }
        for (int i = 0; i < teams.size(); ++i) {
            if (get_team(i) != other.get_team(i)) {
                return false;
            }
        }
        return true;
    }

}