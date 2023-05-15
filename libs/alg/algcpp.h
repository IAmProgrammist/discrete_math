#ifndef DISCRETE_MATH_ALGCPP_H
#define DISCRETE_MATH_ALGCPP_H

#include <vector>
#include <iostream>

template <class T>
class Sett {
public:
    std::vector<T> elements;

    Sett<T>(std::vector<T> elms) {
        elements = elms;
        std::qsort(elements.begin(), elements.end());
    }

    ~Sett() {

    }

    Sett<T> operator*(Sett<T> anotherSet) {
        std::vector<T> arrayC(0, 0);
        int arrayASize = elements.size();
        int arrayBSize = anotherSet.elements.size();
        size_t i = 0, j = 0;

        while (i < arrayASize && j < arrayBSize)
            if (elements[i] < anotherSet.elements[j])
                i++;
            else if (elements[i] > anotherSet.elements[j])
                j++;
            else {
                arrayC.push_back(elements[i]);
                i++;
                j++;
            }

        return Sett<T>(arrayC);
    }

    Sett<T> operator-(Sett<T> anotherSet) {
        std::vector<T> arrayC(0, 0);
        int arrayASize = elements.size();
        int arrayBSize = anotherSet.elements.size();
        size_t i = 0, j = 0;

        while (i < arrayASize && j < arrayBSize)
            if (elements[i] < anotherSet.elements[j])
                arrayC.push_back(elements[i++]);
            else if (elements[i] > anotherSet.elements[j])
                j++;
            else {
                i++;
                j++;
            }

        while (i < arrayASize)
            arrayC.push_back(elements[i++]);

        return Sett<T>(arrayC);
    }

    Sett<T> operator+(Sett<T> anotherSet) {
        std::vector<int> arrayC(0, 0);
        int arrayASize = elements.size();
        int arrayBSize = anotherSet.elements.size();
        size_t i = 0, j = 0;

        while (i < arrayASize && j < arrayBSize)
            if (elements[i] < anotherSet.elements[j])
                arrayC.push_back(elements[i++]);
            else if (elements[i] > anotherSet.elements[j])
                arrayC.push_back(anotherSet.elements[j++]);
            else {
                arrayC.push_back(elements[i]);
                i++;
                j++;
            }

        while (i < arrayASize)
            arrayC.push_back(elements[i++]);

        while (j < arrayBSize)
            arrayC.push_back(anotherSet.elements[j++]);

        return Sett<T>(arrayC);
    }

    Sett<T> non(Sett<T> universum) {
        std::vector<T> arrayC(0, 0);
        int arraySize = elements.size();
        int universumSize = universum.elements.size();
        size_t i = 0, j = 0;
        // Проверяем, что универсум действительно универсум
        assert(arraySize == 0 || elements[arraySize - 1] <= universum.elements[universumSize - 1]);

        while (i < universumSize && j < arraySize) {
            if (universum.elements[i] < elements[j])
                arrayC.push_back(universum.elements[i++]);
            else if (universum.elements[i] == elements[j]) {
                i++;
                j++;
                // вторым его отличием будет то, что если элемент есть в A и его нет в universum, программа будет падать
            } else
                assert(elements[j] >= universum.elements[i]);
        }

        while (i < universumSize)
            arrayC.push_back(universum.elements[i++]);

        return Sett<T>(arrayC);
    }

    Sett<T> operator^(Sett<T> anotherSet) {
        std::vector<T> arrayC(0, 0);
        int arrayASize = elements.size();
        int arrayBSize = anotherSet.elements.size();
        size_t i = 0, j = 0;

        while (i < arrayASize && j < arrayBSize)
            if (elements[i] < anotherSet.elements[j])
                arrayC.push_back(elements[i++]);
            else if (elements[i] > anotherSet.elements[j])
                arrayC.push_back(anotherSet.elements[j++]);
            else {
                j++;
                i++;
            }

        while (i < arrayASize)
            arrayC.push_back(elements[i++]);

        while (j < arrayBSize)
            arrayC.push_back(anotherSet.elements[j++]);

        return Sett<T>(arrayC);
    }

    bool operator==(Sett<T> other) {
        return elements == other.elements;
    }

    bool operator!=(Sett<T> other) {
        return !(*this == other);
    }

    void print() {
        for (int i = 0; i < elements.size(); i++) {
            std::cout << elements[i] << " ";
        }

        std::cout << std::endl;
    }

    void print(std::ostream& out) {
        for (int i = 0; i < elements.size(); i++) {
            out << elements[i] << " ";
        }

        out << std::endl;
    }
};

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
        currentSet.push_back(baseSet[i]);

        // Выполняем следующий шаг итерации, сохраняем в итоговый массив множеств
        auto permutations = getPermutations(newBaseSet, currentSet);
        resultPerms.insert(std::begin(resultPerms), std::begin(permutations), std::end(permutations));
    }

    return resultPerms;
}

template<typename T>
std::vector<std::vector<T>> getPermutations(std::vector<T> &baseSet) {
    return getPermutations(baseSet, {});
}

#endif //DISCRETE_MATH_ALGCPP_H
