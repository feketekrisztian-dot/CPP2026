#include <fstream>
#include <iostream>
#include <iomanip>

#include "GraduationDao.h"
#include "Student.h"

int main() {/*
    // 1. Student objektum létrehozása (azonosító, keresztnév, vezetéknév)
    Student diak(101, "Gábor", "Kovács");

    // 2. Érettségi jegyek rögzítése
    diak.addGrade("Magyar nyelv és irodalom", 8.50);
    diak.addGrade("Matematika", 9.25);
    diak.addGrade("Történelem", 7.80);
    diak.addGrade("Informatika", 9.60);

    // 3. Átlag kiszámítása
    diak.computeAverage();

    // 4. Eredmény kiírása (két tizedesjegy pontossággal)
    std::cout << diak.getLastName() << " " << diak.getFirstName()
              << " érettségi átlaga: "
              << std::fixed << std::setprecision(2) << diak.getAverage()
              << std::endl;

    // Alternatív megoldás, ha az operator<< már meg van írva:
    // std::cout << diak << std::endl;

    return 0;*/

    string subjects[]{"maths", "romanian", "hungarian"};
    int numSubjects = sizeof(subjects) / sizeof(subjects[0]);
    GraduationDao dao(2023);
    dao.enrollStudents("names.txt");
    cout << "Number of enrolled students: " << dao.numEnrolled() << endl;
    for (int i = 0; i < numSubjects; ++i) {
        dao.readGradesSubject(subjects[i], subjects[i] + ".txt");
    }
    dao.computeAverage();
    cout <<"Number of passed students: " << dao.numPassed() << endl;
}
