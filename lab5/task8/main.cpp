#include <chrono>

#include "../../libs/alg/alg.h"

#define SECONDS_IN_MILLISECONDS 1000.0

#define clockExperiment(runningCode, workingTime) \
{                                          \
uint64_t start =                                  \
std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();               \
runningCode                               \
workingTime = (std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count() - start) / SECONDS_IN_MILLISECONDS; \
}

int main() {
    std::vector<int> gay = {1, 2, 3, 4};

    auto superGay = getPermutations(gay);

    for (auto &ultragay : superGay) {
        for (auto &megagay : ultragay)
            std::cout << megagay << " ";

        std::cout << std::endl;
    }

    for (int i = 0; i < 120; i++) {
        std::vector<int> base(i, i);
        double workingTime;

        clockExperiment({ std::vector<std::vector<int>> subsets = getPermutations(base); }, workingTime);

        std::cout << i << "; " << workingTime << std::endl;
    }
}