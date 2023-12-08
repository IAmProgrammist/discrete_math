#include "task1.h"

#include <thread>
#include <future>
#include <unistd.h>

struct Report {
    int n;
    int edgesCount;
    int hamilthonCount;
    int eulerCount;
    int totalCount;
};

#define LOWER_N 8
#define UPPER_N 10
#define ELEMENTS_FOR_N 10

#define CORES_AMOUNT 10
std::atomic<int> takenCores;

int main() {
    std::vector<std::pair<std::chrono::_V2::system_clock::time_point, std::future<Report>>> pool;
    for (int n = LOWER_N; n <= UPPER_N; n++) {
        for (int i = 0; i < ELEMENTS_FOR_N; i++) {
            while (takenCores >= CORES_AMOUNT) {
                sleep(1);
                std::cout << "Working on it..." << "\n";
            }

            int e = n;
            if (i != 0)
                e += (i * ((((n * (n - 1)) / 2 - n))))  / (ELEMENTS_FOR_N - 1);

            takenCores++;
            pool.push_back({std::chrono::system_clock::now(), std::async(std::launch::async, [n, e] {
                int totalGraphsGenerated = 0;
                int hamilthonGraphs = 0;
                int eulerGraphs = 0;
                auto start = std::chrono::system_clock::now();
                while (std::chrono::system_clock::now() - start < std::chrono::seconds(10)) {
                    auto graph = generateRandomGraph(n, e);
                    totalGraphsGenerated++;

                    if (graph->isHamiltonian()) hamilthonGraphs++;
                    if (graph->isEuler()) eulerGraphs++;

                    delete graph;
                }

                takenCores--;

                return (Report){n, e, hamilthonGraphs, eulerGraphs, totalGraphsGenerated};
            })});
        }
    }



    std::cout << "Waiting for results...\n\n";
    for (auto& future : pool) {
        if (future.second.wait_until(future.first + std::chrono::seconds(60)) != std::future_status::ready) {
            std::cout << "====================\n";
            std::cout << "Thread is not responing, consider no result is present.\n";

            continue;
        }

        auto t = future.second.get();

        std::cout << "====================\n";
        std::cout << "n = " << t.n << "\n";
        std::cout << "edges = " << t.edgesCount << "\n";
        std::cout << "hamilthon = " << t.hamilthonCount << "\n";
        std::cout << "euler = " << t.eulerCount << "\n";
        std::cout << "total = " << t.totalCount << "\n\n";
    }

    getchar();

    return 0;
}