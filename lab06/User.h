//
// Created by fkris on 10/19/2026.
//

#ifndef CPP_2026_USER_H
#define CPP_2026_USER_H
#include <map>
#include <string>

inline int userCounter=0;

class User {
    int id;
    std::string name;
    std::map<int,double> result;

public:
    explicit User(const std::string &name);

    [[nodiscard]] int getId() const;

    [[nodiscard]] std::string getName() const;

    [[nodiscard]] double getResult(int key) const;
    void setResult(int key, double ertek);
};


#endif //CPP_2026_USER_H