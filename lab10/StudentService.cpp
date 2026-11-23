//
// Created by fkris on 11/16/2026.
//

#include "StudentService.h"
#include "GraduationDao.h"
#include <stdexcept>

StudentServiceImpl::StudentServiceImpl(GraduationDao *dao) : dao(dao) {}

bool StudentServiceImpl::isEnrolled(int id) const {
    try {
        dao->findById(id);
        return true;
    } catch (const std::out_of_range&) {
        return false;
    }
}

std::vector<std::string> StudentServiceImpl::getSubjects(int id) const {
    Student student = dao->findById(id);
    std::vector<std::string> subjects;
    for (const auto& pair : student.getGrades()) {
        subjects.push_back(pair.first);
    }
    return subjects;
}

double StudentServiceImpl::getResultBySubject(int id, const std::string& subject) const {
    Student student = dao->findById(id);
    return student.getGrade(subject);
}

double StudentServiceImpl::getAverage(int id) const {
    Student student = dao->findById(id);
    return student.getAverage();
}

bool StudentServiceImpl::isPassed(int id) const {
    try {
        Student student = dao->findById(id);
        const auto& grades = student.getGrades();
        if (grades.empty()) {
            return false;
        }
        for (const auto& pair : grades) {
            if (pair.second < 5.0) {
                return false;
            }
        }
        return student.getAverage() >= 6.0;
    } catch (const std::out_of_range&) {
        return false;
    }
}
