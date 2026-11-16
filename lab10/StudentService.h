//
// Created by fkris on 11/16/2026.
//

#ifndef CPP_2026_STUDENTSERVICE_H
#define CPP_2026_STUDENTSERVICE_H
#include <string>
#include <vector>


class GraduationDao;

class StudentService {
public:
    virtual bool isEnrolled(int id) const = 0;
    virtual double getResultBySubject(int id, const std::string& subject) const = 0;
    virtual std::vector<std::string> getSubjects(int id) const = 0;
    virtual double getAverage(int id) const = 0;
    virtual bool isPassed(int id) const = 0;
};

class StudentServiceImpl : public StudentService{
    GraduationDao *dao;
public:
    StudentServiceImpl(GraduationDao *dao);
    virtual bool isEnrolled(int id) const override;
    virtual std::vector<std::string> getSubjects(int id) const override;
    virtual double getResultBySubject(int id, const std::string& subject) const override;
    virtual double getAverage(int id) const override;
    virtual bool isPassed(int id) const override;
};



#endif //CPP_2026_STUDENTSERVICE_H
