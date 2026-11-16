//
// Created by fkris on 11/16/2026.
//

#include "Student.h"

#include <ostream>

Student::Student(int id, const string& firstName, const string& lastName): id(id), firstName(firstName), lastName(lastName)
{}

int Student::getId() const
{
    return id;
}

void Student::setId(int id)
{
    this->id = id;
}

const string& Student::getFirstName() const
{
    return firstName;
}

const string& Student::getLastName() const
{
    return lastName;
}

void Student::addGrade(const string& subject, double grade)
{
    //hozzaadas
    grades[subject] = grade;
}

double Student::getGrade(const string& subject) const
{
    return grades.at(subject);
}

const map<string, double>& Student::getGrades() const
{
    return grades;
}

void Student::computeAverage()
{
    double ossz = 0;
    for ( const auto& [subject, grade] : grades )
        ossz += grade;
    average = ossz / grades.size();
}

double Student::getAverage() const
{
    return average;
}


ostream& operator<<(ostream& os, const Student& student)
{
    os<<"ID: "<<student.getId()<<endl;
    os<<"First Name"<<student.getFirstName()<<" Last Name"<<student.getLastName()<<endl;
    os<<"Tantargy, jegy:"<<endl;
    for ( const auto& [subject, grade] : student.getGrades() )
        os<<subject<<","<<grade<<endl;
    return os;
}
