#pragma once

// Сочетания
template<typename T>
std::vector<std::vector<T>> getCombinations(std::vector<T> &baseSet, std::vector<T> currentSet, size_t minIndex, size_t k, size_t count) {
    std::vector<std::vector<T>> resultCombs;

    // Если количество перестановок равно необходимому, мы достигли искомого множества, возвращаем его
    if (count >= k)
        return {currentSet};

    for (size_t i = minIndex; i <= baseSet.size() - k + count; i++) {
        // Добавляем в текущее множество новый элемент, Ci = x
        std::vector<T> newCurrentSet(currentSet);
        newCurrentSet.push_back(baseSet[i]);

        // Вызываем следующий шаг итерации, сохраняем его результат в общий массив множеств
        std::vector<std::vector<T>> combinations = getCombinations(baseSet, newCurrentSet, i + 1, k, count + 1);
        resultCombs.insert(std::begin(resultCombs), std::begin(combinations), std::end(combinations));
    }

    // Возвращаем массив множеств
    return resultCombs;
}

// Функция-обёртка для рекуррентной функции
template<typename T> std::vector<std::vector<T>> getCombinations(std::vector<T> &baseSet, size_t k) {
    return getCombinations(baseSet, {}, 0, k, 0);
}