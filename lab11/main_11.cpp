#include <iostream>
#include <vector>
#include <stdexcept>
#include "SettlementStatisticsImpl.h"

using namespace std;

int main() {
    try {
        // Adatok beolvasása és polimorf hivatkozás az interfészre
        SettlementStatisticsImpl impl("telepulesek.csv");
        SettlementStatistics& stats = impl;

        // 1. Összes település száma
        cout << "1. Osszes telepules szama: " << impl.numSettlements() << endl;

        // 2. Megyék száma
        cout << "2. Megyek szama: " << stats.numCounties() << endl;

        // 3. Települések száma egy adott megyében
        string testCounty = "CJ";
        cout << "3. Telepulesek szama (" << testCounty << "): "
             << stats.numSettlementsByCounty(testCounty) << endl;

        // 4. Adott megye településeinek lekérdezése (első 5 kiírása)
        cout << "\n4. " << testCounty << " megye elso 5 telepulese:" << endl;
        vector<Settlement> countySettlements = stats.findSettlementsByCounty(testCounty);
        for (size_t i = 0; i < countySettlements.size() && i < 5; ++i) {
            cout << "   - " << countySettlements[i] << endl;
        }

        // 5. Keresés név és megye alapján (létező és nem létező településre)
        cout << "\n5. Kereses nev es megye alapjan:" << endl;
        Settlement found = stats.findSettlementsByNameAndCounty("Cluj-Napoca", "CJ");
        cout << "   Talalat: " << found << endl;

        cout << "   Nem letezo telepules keresese: ";
        Settlement notFound = stats.findSettlementsByNameAndCounty("NincsIlyenVaros", "CJ");
        cout << " -> " << notFound << endl;

        // 6. Legnagyobb lakosságú település
        cout << "\n6. Legnagyobb lakossagu telepules: "
             << stats.maxPopulationBySettlement() << endl;

        // 7. Legkisebb lakosságú település
        cout << "7. Legkisebb lakossagu telepules: "
             << stats.minPopulationBySettlement() << endl;

        // 8. Azonos nevű települések keresése az összes megyében
        string searchName = "Satu Nou";
        vector<Settlement> sameNameSettlements = stats.findSettlementsByName(searchName);
        cout << "\n8. '" << searchName << "' nevu telepulesek szama orszagosan: "
             << sameNameSettlements.size() << endl;
        for (const auto& s : sameNameSettlements) {
            cout << "   - " << s << endl;
        }

    } catch (const exception& e) {
        cerr << "Hiba tortent: " << e.what() << endl;
        return 1;
    }

    return 0;
}