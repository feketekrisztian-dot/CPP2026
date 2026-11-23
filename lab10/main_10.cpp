#include <fstream>
#include <iostream>
#include <iomanip>

#include "GraduationDao.h"
#include "Student.h"
#include "StudentService.h"

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

        // Labor tesszt pelda
    StudentService* service = new StudentServiceImpl(&dao);
    cout << "Individual results: " << endl;
    int id = 0;
    while (id != -1) {
        cout << "Enter ID (-1 for EXIT): ";
        cin >> id;
        if (id == -1) {
            break;
        }
        if (!service->isEnrolled(id)) {
            cout << "Student id=" << id << " not found" << endl;
            continue;
        }
        cout << "Student id=" << id << " results: " << endl;
        bool passed = service->isPassed(id);
        cout << "\tpassed: " << (passed ? "yes" : "no") << endl;
        if (!passed) {
            continue;
        }
        vector<string> subjects = service->getSubjects(id);
        for (int i = 0; i < subjects.size(); ++i) {
            cout << "\t" << subjects[i] << ": " <<
            service->getResultBySubject(id, subjects[i]) << endl;
        }
        cout << "\taverage: " << service->getAverage(id) << endl;
    }
    delete service;
}

