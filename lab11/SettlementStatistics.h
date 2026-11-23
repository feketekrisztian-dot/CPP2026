//
// Created by fkris on 11/23/2026.
//

#ifndef CPP_2026_SETTLEMENTSTATISTICS_H
#define CPP_2026_SETTLEMENTSTATISTICS_H
#include <vector>


struct SettlementStatistics {
    virtual int numSettlements() const = 0;
    virtual int numCounties() const = 0;
    virtual int numSettlementsByCounty(const std::string& county) const = 0;
    virtual std::vector<Settlement> findSettlementsByCounty(
    const std::string& county) const = 0;
    virtual Settlement findSettlementsByNameAndCounty(
    const std::string& name, const std::string& county) const = 0;
    virtual Settlement maxPopulationBySettlement() const = 0;
    virtual Settlement minPopulationBySettlement() const = 0;
    virtual std::vector<Settlement> findSettlementsByName(
    const std::string& name) = 0;
};


#endif //CPP_2026_SETTLEMENTSTATISTICS_H
