//
// Created by fkris on 10/19/2026.
//

#ifndef CPP_2026_QUIZITEM_H
#define CPP_2026_QUIZITEM_H
#include <string>
#include <vector>

inline int counter=0;

class QuizItem {
    int id;
    std::string question;
    std::vector<std::string> answers;
    int correctAnswer;

public:
    explicit QuizItem(const std::string &question);

    [[nodiscard]] int getId() const;

    [[nodiscard]] std::string getQuestion() const;

    [[nodiscard]] std::vector<std::string> getAnswers() const;

    [[nodiscard]] int get_correctAnswer() const;

    void addAnsweres(std::string answer);

    void setCorrectAnswer(int correctAnswer);
};


#endif //CPP_2026_QUIZITEM_H