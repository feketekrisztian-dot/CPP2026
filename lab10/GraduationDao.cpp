//
// Created by fkris on 11/16/2026.
//

#include "GraduationDao.h"
#include <fstream>
#include <stdexcept>

GraduationDao::GraduationDao(int year): year(year)
{}

void GraduationDao::enrollStudents(const string& filename)
{
    std::ifstream file(filename);
    if (!file.is_open()) {
        throw std::runtime_error("Nem sikerult megnyitni a fajlt: " + filename);
    }

    int id;
    std::string firstName, lastName;

    while (file >> id >> firstName >> lastName) {
        students.emplace(id, Student(id, firstName, lastName));
    }
}

void GraduationDao::readGradesSubject(const string& subject, const string& filename)
{
    std::ifstream file(filename);
    if (!file.is_open()) {
        throw std::runtime_error("Nem sikerult megnyitni a fajlt: " + filename);
    }
    int id,grade;
    while (file >> id >> grade) {
        auto it = students.find(id);
        if ( it != students.end() )
        {
            it->second.addGrade(subject, grade);

        }
    }
}

void GraduationDao::computeAverage()
{
    for (auto& [id, student] : students) {
        student.computeAverage();
    }
}

int GraduationDao::numEnrolled() const
{
    return students.size();
}

int GraduationDao::numPassed() const
{
    int passed = 0;
    for ( auto& [id, student] : students )
    {
        if ( student.getAverage() >= 6)
            {
                map<string, double> temp = student.getGrades();
                bool ok = true;
                for (auto& [string, jegy] : temp)
                    if ( jegy < 5 ) { ok=false; break;}
                if (ok)
                    passed++;
            }
    }
    return passed;
}

Student GraduationDao::findById(int id) const
{
        // A map::at() automatikusan std::out_of_range kivételt dob, ha nincs ilyen kulcs
        return students.at(id);
}
double GraduationDao::getAverageBySubject(const std::string& subject) const {
    double sum = 0.0;
    int count = 0;

    for (const auto& [id, student] : students) {
        try {
            sum += student.getGrade(subject);
            ++count;
        } catch (const std::out_of_range&) {
            // Ha az adott diák nem vizsgázott ebből a tantárgyból, kihagyjuk
        }
    }

    return (count > 0) ? (sum / count) : 0.0;
}
