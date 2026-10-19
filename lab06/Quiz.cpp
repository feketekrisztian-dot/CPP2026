//
// Created by fkris on 10/19/2026.
//

#include "Quiz.h"

#include <iostream>


Quiz::Quiz(const std::string &name)
: id(++quizeCounter)
, name(name)
, isReady(false) {
}

void Quiz::addItems(const QuizItem &items) {
    if (isReady) {
        std::cout<<"A feltoltes lezarult mar";
        return;
    }
    this->items.push_back(items);
}

int Quiz::getId() const {
    return id;
}

std::string Quiz::getName() const {
    return name;
}

std::vector<QuizItem> Quiz::getItems() const {
    return items;
}

void Quiz::finalize() {
    isReady = true;
}
