#include <iostream>
#include <vector>
#include <string>
#include <map>

#include "Quiz.h"
#include "QuizGame.h"
#include "User.h"

int main() {

    std::cout << "--- TESZT PROGRAM INDULÁSA ---\n\n";

    Quiz mathQuiz("Alapvető Matematika");

    QuizItem q1("Mennyi 5 + 5 * 2?");
    q1.addAnsweres("15");
    q1.addAnsweres("10");
    q1.addAnsweres("30");
    q1.addAnsweres("3");
    q1.addAnsweres("4");
    q1.addAnsweres("61");
    q1.addAnsweres("12");
    q1.addAnsweres("65");
    q1.addAnsweres("14");
    q1.setCorrectAnswer(2);

    mathQuiz.addItems(q1);

    QuizItem q2("Mennyi 10 * 2?");
    q2.addAnsweres("15");
    q2.addAnsweres("20");
    q2.addAnsweres("3");
    q2.addAnsweres("56");
    q2.setCorrectAnswer(2);

    mathQuiz.addItems(q2);

    QuizItem q3("Mennyi 11413410 * 2?");
    q3.addAnsweres("123r5");
    q3.addAnsweres("2r230");
    q3.addAnsweres("rr233");
    q3.addAnsweres("5t4236");
    q3.setCorrectAnswer(3);

    mathQuiz.addItems(q3);
    mathQuiz.finalize();


    User player("Kiss Péter");

    QuizGame game(player, mathQuiz);
    game.Start(player,mathQuiz);1


    std::cout << "\n\n--- TESZT PROGRAM VÉGE ---\n";
    return 0;
}
