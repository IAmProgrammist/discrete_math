#include "../alg.h"

void uniteRepeatingElementsArrays(const int *const arrayA, const size_t arrayASize,
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