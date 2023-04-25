#include "../algc.h"

void getArrayOfNotRepeatingValues(const int *const arrayA, const size_t arrayASize,
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