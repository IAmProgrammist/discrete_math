#pragma once

// Подмножества
template <typename T>
std::vector<std::vector<T>> getSubsets(std::vector<T>& baseSet, std::vector<T> currentSet,
                                       size_t count) {
    // Если мы достигли конца исходного множества, возвращаем текущее множество
    if (count == baseSet.size())
        return {currentSet};

    // Добавляем в массив подмножеств шаг, если мы не добавляем на текущем шаге новый элемент
    std::vector<std::vector<T>> resultSubsets = getSubsets(baseSet, currentSet, count + 1);

    // Добавляем в текущее подмножество элемент массива
    currentSet.push_back(baseSet[count]);

    // Добавляем в массив подмножеств шаг, если мы добавляем на текущем шаге новый элемент
    std::vector<std::vector<T>> branch = getSubsets(baseSet, currentSet, count + 1);
    resultSubsets.insert(std::end(resultSubsets), std::begin(branch), std::end(branch));

    return resultSubsets;
}

// Функция-обёртка для рекуррентной функции
template <typename T>
std::vector<std::vector<T>> getSubsets(std::vector<T>& baseSet) {
    return getSubsets(baseSet, {}, 0);
}