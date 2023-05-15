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

    for (int i = 0; i < 120; i++) {
        std::vector<int> base(i, i);
        double workingTime;

        clockExperiment({ std::vector<std::vector<int>> subsets = getSubsets(base); }, workingTime);

        std::cout << i << " " << workingTime << std::endl;
    }
}