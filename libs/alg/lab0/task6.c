#include "../algc.h"

bool isArraysConsistsOfSameElements(const int *const arrayA, const size_t arrayASize,
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