#include <iostream>
#include <vector>
#include <string>
#include <map>

#include "Quiz.h"
#include "QuizGame.h"
#include "User.h"

int main() {
    // Magyar ékezetek helyes megjelenítése konzolon
    std::setlocale(LC_ALL, "Hungarian");

    std::cout << "--- TESZT PROGRAM INDULÁSA ---\n\n";

    // 1. Kvíz és kérdések létrehozása
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

    mathQuiz.addItems(q1); // Helyes válasz: 15 (1-es indexű, azaz a 2. opció)

    QuizItem q2("Mennyi 10 * 2?");
    q2.addAnsweres("15");
    q2.addAnsweres("20");
    q2.addAnsweres("3");
    q2.addAnsweres("56");
    q2.setCorrectAnswer(2);


    // Kvíz lezárása a finalize metódussal
    mathQuiz.finalize();

    // 3. Felhasználó létrehozása
    User player("Kiss Péter");

    // 4. Játék indítása a QuizGame osztállyal (laza tartalmazás)
    QuizGame game(player, mathQuiz);
    game.Start(player,mathQuiz);

    // 5. Felhasználó eredményeinek lekérdezése és kiíratása (map tesztelése)


    std::cout << "\n--- TESZT PROGRAM VÉGE ---\n";
    return 0;
}
