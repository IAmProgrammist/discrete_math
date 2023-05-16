#pragma once

// Размещшения
template<typename T>
std::vector<std::vector<T>> getPlacements(std::vector<T> baseSet, std::vector<T> currentSet, size_t k) {
    // k не может быть больше размера исходного множества
    k = std::min(baseSet.size(), k);

    // Если k = 0, то количество перестановок закончилось или закончился исходный массив. В обоих случаях мы достигли
    // искомого множества, возвращаем его.
    if (k == 0) return {currentSet};

    std::vector<std::vector<T>> resultPerms;

    for (size_t i = 0; i < baseSet.size(); i++) {
        // Удаляем из исходного массива x
        std::vector<T> newBaseSet(baseSet);
        newBaseSet.erase(std::begin(newBaseSet) + i);

        // Добавляем в текущее множество новый элемент
        std::vector<T> newCurrentSet(currentSet);
        newCurrentSet.push_back(baseSet[i]);

        // Выполняем следующий шаг итерации, сохраняем в итоговый массив множеств
        auto permutations = getPlacements(newBaseSet, newCurrentSet, k - 1);
        resultPerms.insert(std::begin(resultPerms), std::begin(permutations), std::end(permutations));
    }

    return resultPerms;
}

template<typename T>
std::vector<std::vector<T>> getPlacements(std::vector<T> &baseSet, size_t k) {
    return getPlacements(baseSet, {}, std::min(baseSet.size(), k));
}