#include "../algc.h"

void uniteArrays(const int *const arrayA, const size_t arrayASize,
                 const int *const arrayB, const size_t arrayBSize,
                 int *arrayC, size_t *arrayCSize) {
    // Индексы в массиве A и B
    size_t i = 0, j = 0;

    // Пока индексы не указывают на конец массива выполняем цикл
    while (i < arrayASize || j < arrayBSize) {
        // Первый случай. Копируем значение из A если индекс B указывает на конец массива или
        // элемент из A меньше элемента из B
        if (j == arrayBSize || (i < arrayASize && arrayA[i] < arrayB[j]))
            arrayC[(*arrayCSize)++] = arrayA[i++];
        // Второй случай. Копируем значение из B если индекс A указывает на конец массива или
        // элемент из B меньше элемента из A
        else if (i == arrayASize || arrayA[i] > arrayB[j])
            arrayC[(*arrayCSize)++] = arrayB[j++];
        // Третий случай. Элементы равны, в этом случае нужно сдвинуть любой из индексов, здесь мог быть как i, так и j
        else
            i++;
    }
}