//
// Created by fkris on 11/23/2026.
//

#ifndef CPP_2026_SETTLEMENTSTATISTICSIMP_H
#define CPP_2026_SETTLEMENTSTATISTICSIMP_H

#include <map>
#include "Settlement.h"
#include "SettlementStatistics.h"

using namespace std;

class SettlementStatisticsImpl : public SettlementStatistics{
    multimap<string, Settlement> settlements;;
public:
    SettlementStatisticsImpl(string filename);
    int numSettlements() const override;
    int numCounties() const override;
    int numSettlementsByCounty(const std::string& county) const override;
    std::vector<Settlement> findSettlementsByCounty(const std::string& county) const override;
    Settlement findSettlementsByNameAndCounty(const std::string& name, const std::string& county) const override;
    Settlement maxPopulationBySettlement() const override;
    Settlement minPopulationBySettlement() const override;
    std::vector<Settlement> findSettlementsByName(const std::string& name) override;
};



#endif //CPP_2026_SETTLEMENTSTATISTICS_H
