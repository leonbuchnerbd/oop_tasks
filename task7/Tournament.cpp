//
// Created by Leon Buchner on 18.11.25.
//
#include "Tournament.h"
#include <iostream>

namespace task7 {
    Tournament::Tournament(std::string title, Team* source_teams, int size)
        : title(title), size(size), teams(copy_from_array(source_teams, size)) {}

    Tournament::Tournament(const Tournament& other)
        : title(other.title), size(other.size),
          teams(copy_from_pointers(other.teams, other.size)) {}

    Tournament& Tournament::operator=(const Tournament& other) {
        if (this == &other) {
            return *this;
        }
        delete[] teams;

        title = other.title;
        size = other.size;

        teams = copy_from_pointers(other.teams, other.size);

        return *this;
    }

    Tournament::~Tournament() {
        for (int i = 0; i < size; ++i)
            delete teams[i];
        delete[] teams;
    }

    Team** Tournament::copy(Team* source_teams, int size) {
        Team** result = new Team*[size];
        for (int i = 0; i < size; ++i)
            result[i] = new Team(source_teams[i]);
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

    void Tournament::remove(int index) {
        if (index < 0 || index >= size)
            throw std::out_of_range("Tournament index out of range");

        delete teams[index];

        Team** newTeams = new Team*[size - 1];

        for (int i = 0, j = 0; i < size; ++i) {
            if (i == index) continue;
            newTeams[j++] = teams[i];
        }

        delete[] teams;
        teams = newTeams;
        size--;
    }

    bool Tournament::contains(const Team& other) const {
        for (int i = 0; i < size; ++i) {
            if (get_team(i) == other) {
                return true;
            }
        }
        return false;
    }

    bool Tournament::containsNot(const Team& other) const {
        for (int i = 0; i < size; ++i) {
            if (get_team(i) != other) {

            } else {
                return false;
            }
        }
        return true;
    }

    bool Tournament::operator==(const Tournament &other) const {
        if (size != other.size) {
            return false;
        }
        if (title != other.title) {
            return false;
        }
        for (int i = 0; i < size; ++i) {
            if (get_team(i) != other.get_team(i)) {
                return false;
            }
        }
        return true;
    }

}