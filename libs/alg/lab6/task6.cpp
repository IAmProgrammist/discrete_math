#include "../alg.h"

#define DISTANCE(a, b) \
        (pow2(max(b.x, a.x) - min(b.x, a.x)) +\
        pow2(max(b.y, a.y) - min(b.y, a.y)))

typedef std::vector<Point> Path;
typedef std::vector<unsigned long long> Functional;

static unsigned long long max(unsigned long long a, unsigned long long b) {
    return a > b ? a : b;
}

static unsigned long long min(unsigned long long a, unsigned long long b) {
    return a < b ? a : b;
}

static unsigned long long pow2(unsigned long long a) {
    return a * a;
}

// Генерация траекторий задачи
static std::vector<Path> getPaths(size_t n, size_t k) {
    // Массив точек решётки
    std::vector<Point> points;

    // Заполняем его всеми точками решётки.
    for (long long x = 0; x < n; x++)
        for (long long y = 0; y < n; y++)
            points.push_back({x, y});

    // Такие сочетания получить невозможно - возвращаем пустой массив траекторий
    if (points.size() < k || k == 0) return {};

    return getCombinations(points, k);
}

// Генерация функционалов задачи
static std::vector<std::pair<Functional, Path>> getFunctionals(std::vector<Path> paths, Point a) {
    std::vector<std::pair<Functional, Path>> answer;

    // Каждой траектории задачи поставим в соответствие функционал
    // Функционал - массив расстояний от точек в траектории до исходной точки a
    for (auto &path: paths) {
        Functional distances;

        // Определяем расстояние от каждой точки в траектории до точки a
        for (auto &point : path)
            distances.push_back(DISTANCE(a, point));

        // Сохраняем полученный функционал
        answer.push_back({distances, path});
    }

    return answer;
}

// Определяем траектории
size_t getDecision(size_t n, Point a, size_t k) {
    // Генерация траекторий
    auto paths = getPaths(n, k);

    // Генерация функционала
    auto functionals = getFunctionals(paths, a);

     size_t decisions = 0;
    // Если все расстояния в функционале одинаковы, решение найдено
    for (auto &pair : functionals) {
        auto distances = pair.first;
        bool areEqual = true;

        for (auto &dist : distances)
            areEqual &= dist == distances[0];

        decisions += areEqual;
    }

    return decisions;
}