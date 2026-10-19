//
// Created by fkris on 10/19/2026.
//

#include "QuizItem.h"

QuizItem::QuizItem(const std::string &question)
: id(++counter),
question(question),
correctAnswer(0) {
}

int QuizItem::getId() const {
    return id;
}

std::string QuizItem::getQuestion() const {
    return question;
}

std::vector<std::string> QuizItem::getAnswers() const {
    return answers;
}

int QuizItem::get_correctAnswer() const {
    return correctAnswer;
}

void QuizItem::addAnsweres(std::string answer) {
    this->answers.push_back(answer);
}

void QuizItem::setCorrectAnswer(int correctAnswer) {
    this->correctAnswer = correctAnswer;
}
