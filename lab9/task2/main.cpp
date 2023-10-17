#include "../../libs/alg/alg.h"

#include <fstream>
#include <dir.h>
#include <filesystem>

std::ostream& operator<<(std::ostream& out, FactorSet& factorSet) {
    for (int i = 0; i < factorSet.size(); i++) {
        bool anyOutput = false;
        for (int j = 0; j < factorSet.size(); j++) {
            if (j < i && factorSet[i] == factorSet[j]) break;
            if (factorSet[i] == factorSet[j]) { 
                out << j + 1 << " "; 
                anyOutput = true;
            }
        }
        if (anyOutput) 
            out << "\b\n";
    }

    return out;
}

int main() {
    BoolMatrixRelation rel(10, [](int x, int y) {
        return (x % 3 == 0 && y % 3 == 0) || (x % 5 == 0 && y % 5 == 0) || x == y;
    });

    FactorSet set = rel.getPackedFactorSet();
    std::cout << set;
    
    return 0;
}