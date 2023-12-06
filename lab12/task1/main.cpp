#include "task1.h"

#include <thread>
#include <future>
#include <unistd.h>

struct Report {
    int n;
    double h;
    int edgesCount;
    int hamilthonCount;
    int eulerCount;
    int totalCount;
};

#define LOWER_N 8
#define UPPER_N 10
#define ELEMENTS_FOR_N 20

#define CORES_AMOUNT 10
std::atomic<int> takenCores;

int main() {
    std::vector<std::pair<std::chrono::_V2::system_clock::time_point, std::future<Report>>> pool;
    for (int n = LOWER_N; n <= UPPER_N; n++) {
        double h = ((n * (n - 1)) / 2 - 1.0 * n) / (ELEMENTS_FOR_N);
        
        for (double e = n; e <= ((n * (n - 1)) / 2); e += h) {
            while (takenCores >= CORES_AMOUNT) {
                sleep(1);
                std::cout << "Working on it..." << "\n";
            }

            takenCores++;
            pool.push_back({std::chrono::system_clock::now(), std::async(std::launch::async, [n, h, e] {
                int totalGraphsGenerated = 0;
                int hamilthonGraphs = 0;
                int eulerGraphs = 0;
                auto start = std::chrono::system_clock::now();
                while (std::chrono::system_clock::now() - start < std::chrono::seconds(10)) {
                    auto graph = generateRandomGraph(n, static_cast<int>(e));
                    totalGraphsGenerated++;

                    if (graph->isHamiltonian()) hamilthonGraphs++;
                    if (graph->isEuler()) eulerGraphs++;

                    delete graph;
                }

                takenCores--;

                return (Report){n, h, static_cast<int>(e), hamilthonGraphs, eulerGraphs, totalGraphsGenerated};
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
        std::cout << "h = " << t.h << "\n";
        std::cout << "edges = " << t.edgesCount << "\n";
        std::cout << "hamilthon = " << t.hamilthonCount << "\n";
        std::cout << "euler = " << t.eulerCount << "\n";
        std::cout << "total = " << t.totalCount << "\n\n";
    }

    getchar();

    return 0;
}