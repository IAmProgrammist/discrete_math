#include "../algc.h"

bool isArraysConsistsOfDifferentElements(const int *const arrayA, const size_t arrayASize,
                                         const int *const arrayB, const size_t arrayBSize) {
    // Предположим, что массивы состоят из разных элементов
    bool result = true;

    // Проверим, что каждый элемент A не содержится в B, если обнаружится что это не так, то result будет false,
    // и смысла продолжать перебор далее не будет
    for (size_t i = 0; i < arrayASize && result; i++) {
        // Просто перебор
        size_t j = 0;
        while (j < arrayBSize && arrayA[i] != arrayB[j])
            j++;

        // Присваиваем result результат перебора, если что-то нашлось, result остаётся без изменений
        // Иначе - становится false.
        result = j == arrayBSize;
    }

    return result;
}