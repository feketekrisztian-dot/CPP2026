//
// Created by fkris on 10/19/2026.
//

#ifndef CPP_2026_QUIZGAME_H
#define CPP_2026_QUIZGAME_H


class Quiz;
class User;

class QuizGame {
    User &user;
    Quiz &quiz;

public:
    QuizGame(User &user, Quiz &quiz);

    void Start(User &u, Quiz &q);
};


#endif //CPP_2026_QUIZGAME_H