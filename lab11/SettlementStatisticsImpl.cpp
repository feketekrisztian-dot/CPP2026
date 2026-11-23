//
// Created by fkris on 11/23/2026.
//

#include "SettlementStatisticsImpl.h"
#include <fstream>
#include <sstream>


SettlementStatisticsImpl::SettlementStatisticsImpl(string filename)
{
    ifstream ifs(filename);
    if (!ifs)throw std::invalid_argument("Cannot open file");

    string line;
    getline(ifs, line);
    while (getline(ifs, line)){
        stringstream ss(line);
        string name,country;
        int population;
        getline(ss,name,',');
        getline(ss,country,',');
        ss >> population;
        settlements.emplace(country,Settlement(name,country,population));
    }

}

int SettlementStatisticsImpl::numSettlements() const
{
    return settlements.size();
}

int SettlementStatisticsImpl::numCounties() const
{
    int numCountries = 0;
    for (auto it = settlements.begin(); it != settlements.end(); it = settlements.upper_bound(it->first)){
        numCountries++;
    }

    return numCountries;
}

int SettlementStatisticsImpl::numSettlementsByCounty(const std::string& county) const
{
    int numSettlements = 0;
    for (auto it = settlements.lower_bound(county); it != settlements.upper_bound(county); ++it)
    {
        numSettlements++;
    }
    return numSettlements;
}

std::vector<Settlement> SettlementStatisticsImpl::findSettlementsByCounty(const std::string& county) const
{
    vector <Settlement> temp;
    for (auto it = settlements.lower_bound(county); it != settlements.upper_bound(county); ++it)
    {
        temp.push_back(it->second);
    }
    return temp;
}

Settlement SettlementStatisticsImpl::findSettlementsByNameAndCounty(const std::string& name,const std::string& county) const
{
    for (auto it = settlements.lower_bound(county); it != settlements.upper_bound(county); ++it)
    {
        if (it->second.getName() == name)
            return it->second;
    }
    cout<<"Nincs ilyen";
    return Settlement("0","0",0);
}

Settlement SettlementStatisticsImpl::maxPopulationBySettlement() const
{
    auto maxIt = settlements.begin();

    for (auto it = settlements.begin(); it != settlements.end(); ++it) {
        if (it->second.getPopulation() > maxIt->second.getPopulation()) {
            maxIt = it;
        }
    }

    return maxIt->second;
}

Settlement SettlementStatisticsImpl::minPopulationBySettlement() const
{
    {
        auto minIt = settlements.begin();

        for (auto it = settlements.begin(); it != settlements.end(); ++it) {
            if (it->second.getPopulation() < minIt->second.getPopulation()) {
                minIt = it;
            }
        }

        return minIt->second;
    }
}

std::vector<Settlement> SettlementStatisticsImpl::findSettlementsByName(const std::string& name)
{
    vector <Settlement> temp;
    for (auto it = settlements.begin(); it != settlements.end(); ++it) {
        if (it->second.getName() == name) {
            temp.push_back(it->second);
        }
    }
    return temp;
}

