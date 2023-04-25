#include "../algc.h"

void uniteRepeatingElementsInSets(const int *const arrayA, const size_t arrayASize,
                                  const int *const arrayB, const size_t arrayBSize,
                                  int *arrayC, size_t *arrayCSize) {
    // Индексы в массиве A и B
    size_t i = 0, j = 0;

    // Пока индексы не указывают на конец массива выполняем цикл
    while (i < arrayASize && j < arrayBSize) {
        // Первый случай. A меньше элемента из B
        if (i < arrayASize && arrayA[i] < arrayB[j])
            i++;
        // Второй случай. A больше элемента из B
        else if (j < arrayBSize && arrayA[i] > arrayB[j])
            j++;
        // Третий случай. A равен элементу из B. В третьем случае копируем элемент и сдвигаем индекс массива A
        else
            arrayC[(*arrayCSize)++] = arrayA[i++];
    }
}