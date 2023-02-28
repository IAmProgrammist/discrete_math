#include "../alg.h"

void uniteUnordered(const int *const arrayA, const size_t arrayASize,
                                 const int *const arrayB, const size_t arrayBSize,
                                 int *arrayC, size_t *const arrayCSize) {
    // Создаём указатель на первый элемент массива С
    int *cBegin = arrayC;

    // Копируем все элементы массива A в C, сдвигаем указатель на последний элемент.
    for (size_t i = 0; i < arrayASize; i++) {
        *(arrayC++) = arrayA[i];
    }

    // Аналогично копируем элементы из массива B в C, кроме того проверяем,
    // что копируемый элемент не встречается в массиве A
    for (size_t i = 0; i < arrayBSize; ++i) {

        // Проверяем, что элемента нет в массиве A
        int j = 0;
        while (j < arrayASize && arrayA[j] != arrayB[i])
            j++;

        // Если его нет, добавляем в массив C новый элемент
        if (j == arrayASize)
            *(arrayC++) = arrayB[i];
    }

    // Длина итогового массива - разница указателя на последний и первый элемент
    *arrayCSize = arrayC - cBegin;
}

void intersectUnordered(const int *const arrayA, const size_t arrayASize,
                                  const int *const arrayB, const size_t arrayBSize,
                                  int *arrayC, size_t *const arrayCSize) {
    // Создаём указатель на первый элемент массива С
    int *cBegin = arrayC;

    // Копируем элементы из массива B в C, кроме того проверяем,
    // что копируемый элемент встречается в массиве A
    for (size_t i = 0; i < arrayBSize; ++i) {

        // Проверяем, что элемента есть в массиве A
        int j = 0;
        while (j < arrayASize && arrayA[j] != arrayB[i])
            j++;

        // Если он есть, добавляем в массив новый элемент
        if (j != arrayASize)
            *(arrayC++) = arrayB[i];
    }

    // Длина итогового массива - разница указателя на последний и первый элемент
    *arrayCSize = arrayC - cBegin;
}

void differenceUnordered(const int *const arrayA, const size_t arrayASize,
                                            const int *const arrayB, const size_t arrayBSize,
                                            int *arrayC, size_t *const arrayCSize) {
    // Создаём указатель на первый элемент массива С
    int *cBegin = arrayC;

    // Копируем элементы из массива A в C, кроме того проверяем,
    // что копируемый элемент не встречается в массиве B
    for (size_t i = 0; i < arrayASize; ++i) {

        // Проверяем, что элемента нет в массиве B
        int j = 0;
        while (j < arrayBSize && arrayA[i] != arrayB[j])
            j++;

        // Если его нет, добавляем в массив C новый элемент
        if (j == arrayBSize)
            *(arrayC++) = arrayA[i];
    }

    // Длина итогового массива - разница указателя на последний и первый элемент
    *arrayCSize = arrayC - cBegin;
}

void symmetricDifferenceUnordered(const int *const arrayA, const size_t arrayASize,
                                  const int *const arrayB, const size_t arrayBSize,
                                  int *arrayC, size_t *const arrayCSize) {
    // Создаём указатель на первый элемент массива С
    int *cBegin = arrayC;

    // Копируем элементы из массива A в C, кроме того проверяем,
    // что копируемый элемент не встречается в массиве B
    for (size_t i = 0; i < arrayASize; ++i) {

        // Проверяем, что элемента нет в массиве B
        int j = 0;
        while (j < arrayBSize && arrayA[i] != arrayB[j])
            j++;

        // Если его нет, добавляем в массив C новый элемент
        if (j == arrayBSize)
            *(arrayC++) = arrayA[i];
    }

    // Аналогичным образом копируем элементы из B
    for (size_t i = 0; i < arrayBSize; ++i) {

        int j = 0;
        while (j < arrayASize && arrayB[i] != arrayA[j])
            j++;

        if (j == arrayASize)
            *(arrayC++) = arrayB[i];
    }

    // Длина итогового массива - разница указателя на последний и первый элемент
    *arrayCSize = arrayC - cBegin;
}

bool includesUnordered(const int *const arrayA, const size_t arrayASize,
                                const int *const arrayB, const size_t arrayBSize) {
    // Предположим, что B действительно содержит каждый элемент массива A
    bool result = true;

    // Проверим, что каждый элемент A находится в B, если обнаружится что это не так, то result будет false,
    // и смысла продолжать перебор далее не будет
    for (size_t i = 0; i < arrayASize && result; i++) {
        // Просто перебор
        size_t j = 0;
        while (j < arrayBSize && arrayA[i] != arrayB[j])
            j++;

        // Присваиваем result результат перебора, если что-то нашлось, result остаётся без изменений
        // Иначе - становится false.
        result = j != arrayBSize;
    }

    return result;
}

bool equalUnordered(const int *const arrayA, const size_t arrayASize,
                                    const int *const arrayB, const size_t arrayBSize) {
    // Если массивы состоят из неповторяющихся одинаковых элементов, то логично предположить, что их
    // размеры равны.
    bool result = arrayASize == arrayBSize;

    // Проверим, что каждый элемент A находится в B, если обнаружится что это не так, то result будет false,
    // и смысла продолжать перебор далее не будет
    for (size_t i = 0; i < arrayASize && result; i++) {
        // Просто перебор
        size_t j = 0;
        while (j < arrayBSize && arrayA[i] != arrayB[j])
            j++;

        // Присваиваем result результат перебора, если что-то нашлось, result остаётся без изменений
        // Иначе - становится false.
        result = j != arrayBSize;
    }

    // Смысла проверять B нет, так как размеры массивов равны и каждому элементу A найден равный элемент из B

    return result;
}

void fillUniversumUnordered(const int *const arrayA, const size_t arrayASize,
                         const int *const universum, const size_t universumSize,
                         int *arrayC, size_t *const arrayCSize) {
    // Создаём указатель на первый элемент массива С
    int *cBegin = arrayC;

    // Здесь проверим, что universum действительно универсум
    for (size_t i = 0; i < arrayASize; ++i) {

        // Проверяем, что элемента из A нет в универсуме
        int j = 0;
        while (j < universumSize && arrayA[i] != universum[j])
            j++;

        // Если его нет в универсуме, падаем
        assert(j < universumSize);
    }

    // После проверки можем приступать к копированию из универсума в C
    for (size_t i = 0; i < universumSize; ++i) {

        // Находим элемент из универсума в A
        int j = 0;
        while (j < arrayASize && arrayA[j] != universum[i])
            j++;

        // Элемент из универсума не найден, поэтому копируем его в C
        if (j == arrayASize)
            *(arrayC++) = universum[i];
    }

    // Длина итогового массива - разница указателя на последний и первый элемент
    *arrayCSize = arrayC - cBegin;
}

bool includesStrictUnordered(const int *const arrayA, const size_t arrayASize,
                             const int *const arrayB, const size_t arrayBSize) {
    // Если массивы равны, то их размеры равны, а значит A не включен строго в B
    // Если массивы не равны, но их размеры равны, значит в A встречаются элементы, которых нет в B,
    // проверять дальше тоже нет смысла.
    bool result = arrayASize != arrayBSize;

    // Проверим, что каждый элемент A находится в B, если обнаружится что это не так, то result будет false,
    // и смысла продолжать перебор далее не будет
    for (size_t i = 0; i < arrayASize && result; i++) {
        // Просто перебор
        size_t j = 0;
        while (j < arrayBSize && arrayA[i] != arrayB[j])
            j++;

        // Присваиваем result результат перебора, если что-то нашлось, result остаётся без изменений
        // Иначе - становится false.
        result = j != arrayBSize;
    }

    return result;
}