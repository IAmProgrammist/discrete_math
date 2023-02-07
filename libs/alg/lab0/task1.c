#include "../alg.h"

void uniteArraysWithoutRepeating(const int *const arrayA, const size_t arrayASize,
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