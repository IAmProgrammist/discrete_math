#include <chrono>

#include "../../libs/alg/alg.h"

#define SECONDS_IN_MILLISECONDS 1000.0

#define clockExperiment(runningCode, workingTime) \
{                                          \
uint64_t start =                                  \
duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();               \
runningCode                               \
workingTime = (duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count() - start) / SECONDS_IN_MILLISECONDS; \
}

int main() {
    for (auto &sizes : {5, 7, 9, 11, 12, 13}) {
        std::cout << sizes << std::endl;
        std::vector<int> base(sizes, 42);

        for (size_t k = 0; k <= sizes; k++) {
            auto combinations = getCombinations(base, k);

            std::cout << k << " " << combinations.size() << std::endl;
        }
        std::cout << std::endl << std::endl;
    }

    std::vector<int> her = {1,2,3,4,5};
    auto j = getCombinations(her, 3);

    std::cout << j.size() << " " << getPlacements(her, 3).size();

    return 0;
}