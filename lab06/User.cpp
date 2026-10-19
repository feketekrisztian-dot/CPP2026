//
// Created by fkris on 10/19/2026.
//

#include "User.h"

#include <variant>

User::User(const std::string &name)
        : id(++userCounter), name(name) {
}

int User::getId() const {
        return id;
}

std::string User::getName() const {
        return name;
}

double User::getResult(int key) const {
        if (result.find(key)!=result.end())
                return result.find(key)->second;
        return -1;
}

void User::setResult(int key, double ertek) {
        this->result.emplace(key, ertek);
}
