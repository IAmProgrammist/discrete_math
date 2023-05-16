#pragma once

// Перестановка
template<typename T>
std::vector<std::vector<T>> getPermutations(std::vector<T> baseSet, std::vector<T> currentSet) {
    std::vector<std::vector<T>> resultPerms;

    // Если элементов в изначальном множестве не осталось, получено искомое множество
    if (baseSet.size() == 0) return {currentSet};

    for (size_t i = 0; i < baseSet.size(); i++) {
        // Удаляем из исходного массива x
        std::vector<T> newBaseSet(baseSet);
        newBaseSet.erase(std::begin(newBaseSet) + i);

        // Добавляем в текущее множество новый элемент
        std::vector<T> newCurrentSet(currentSet);
        newCurrentSet.push_back(baseSet[i]);

        // Выполняем следующий шаг итерации, сохраняем в итоговый массив множеств
        auto permutations = getPermutations(newBaseSet, newCurrentSet);
        resultPerms.insert(std::begin(resultPerms), std::begin(permutations), std::end(permutations));
    }

    return resultPerms;
}

template<typename T>
std::vector<std::vector<T>> getPermutations(std::vector<T> &baseSet) {
    return getPermutations(baseSet, {});
}