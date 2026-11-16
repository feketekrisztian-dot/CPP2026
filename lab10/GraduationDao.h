//
// Created by fkris on 11/16/2026.
//

#ifndef CPP_2026_GRADUATIONDAO_H
#define CPP_2026_GRADUATIONDAO_H
#include "Student.h"


class GraduationDao {
    int year{2023};
    map<int, Student> students{};
public:
    explicit GraduationDao(int year);
    void enrollStudents(const string &filename);
    void readGradesSubject(const string &subject, const string &filename);
    void computeAverage();
    int numEnrolled() const;
    int numPassed() const;
    Student findById(int id) const; //throws out_of_range exception for nonexistent id
    double getAverageBySubject(const string &subject) const;
};

#endif //CPP_2026_GRADUATIONDAO_H
