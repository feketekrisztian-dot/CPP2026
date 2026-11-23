//
// Created by fkris on 11/23/2026.
//

#ifndef CPP_2026_SETTLEMENT_H
#define CPP_2026_SETTLEMENT_H
#include <iostream>
#include <ostream>
#include <string>

class Settlement {
    std::string name = "";
    std::string county = "";
    int population = 0;

public:
    Settlement(const std::string& name, const std::string& county, int population);

    [[nodiscard]] std::string getName() const;

    [[nodiscard]] std::string getCounty() const;

    [[nodiscard]] int getPopulation() const;

    void set_name(const std::string& name);

    void set_county(const std::string& county);

    void set_population(int population);

    friend std::ostream& operator<<(std::ostream& os, const Settlement& obj);

    // constructor, getters, setters, inserter operator
};



#endif //CPP_2026_SETTLEMENT_H
