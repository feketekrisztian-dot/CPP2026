//
// Created by fkris on 11/23/2026.
//

#include "Settlement.h"

Settlement::Settlement(const std::string& name, const std::string& county, int population): name(name),
    county(county),
    population(population)
{
}

std::string Settlement::getName() const
{
    return name;
}

std::string Settlement::getCounty() const
{
    return county;
}

int Settlement::getPopulation() const
{
    return population;
}

void Settlement::set_name(const std::string& name)
{
    this->name = name;
}

void Settlement::set_county(const std::string& county)
{
    this->county = county;
}

void Settlement::set_population(int population)
{
    this->population = population;
}

std::ostream& operator<<(std::ostream& os, const Settlement& obj)
{
    return os
        << "name: " << obj.name
        << " county: " << obj.county
        << " population: " << obj.population;
}
