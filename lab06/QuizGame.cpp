//
// Created by fkris on 10/19/2026.
//

#include "QuizGame.h"

#include <iostream>

#include "Quiz.h"
#include "User.h"

QuizGame::QuizGame(User &user, Quiz &quiz)
: user(user)
, quiz(quiz) {

}


void QuizGame::Start(User &u, Quiz &q) {
    std::cout<<u.getName()<<" a következő a quiz:/n"<<q.getName()<<std::endl;

    std::vector<QuizItem> tempItems = q.getItems();
    int helyes=0;
    for (int i = 0; i < tempItems.size(); i++) {
        std::cout<<i<<". kérdés";
        std::cout<<tempItems[i].getQuestion()<<std::endl;
        for (int j=0;j<tempItems[i].getAnswers().size();j++)
            std::cout<< tempItems[i].getAnswers()[j]<<std::endl;
        int valasz;
        std::cout<<"Valasz indexe: ";
        std::cin>>valasz;
        if (valasz==tempItems[i].get_correctAnswer()) {
            std::cout<<"Helyes"<<std::endl;
            helyes++;
        }
        else {
            std::cout<<"Helytelen"<<std::endl;
        }
    }
    double eredmeny=double(helyes)*100/double(tempItems.size());
    std::cout<<"Szazalekos eredmeny: "<<eredmeny<<std::endl;
    u.setResult(q.getId(),eredmeny);
}

