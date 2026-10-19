//
// Created by fkris on 10/19/2026.
//

#ifndef CPP_2026_QUIZ_H
#define CPP_2026_QUIZ_H
#include <string>
#include <vector>

#include "QuizItem.h"

inline int quizeCounter=0;

class QuizItem;

class Quiz {
    int  id;
    std::string name;
    std::vector<QuizItem> items;
    bool isReady;

public:
    explicit Quiz(const std::string &name);

    void addItems(const QuizItem &items);

    [[nodiscard]] int getId() const;

    [[nodiscard]] std::string getName() const;

    [[nodiscard]] std::vector<QuizItem> getItems() const;

    void finalize();
};


#endif //CPP_2026_QUIZ_H