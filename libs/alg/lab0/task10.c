#include "../algc.h"

void getUniqueElementsOfA(const int *const arrayA, const size_t arrayASize,
                                  const int *const arrayB, const size_t arrayBSize,
                                  int *arrayC, size_t *arrayCSize) {
    // Индексы в массиве A и B
    size_t i = 0, j = 0;

    // Пока индексы не указывают на конец массива выполняем цикл
    while (i < arrayASize || j < arrayBSize) {
        // Первый случай. Элемент из A оказался меньше элемента из B или индекс j указывает на конец B
        // Если A[i] < B[j], то в B больше никогда не встретится A[i], так как все последующие элементы
        // будут больше B[j], поэтому можем добавлять элемент в C.
        // Также добавляем элемент если мы достигли конца B - больше элементов не будет, и следующие элементы A
        // в нём не встретятся
        if (j == arrayBSize || (i < arrayASize && arrayA[i] < arrayB[j]))
            arrayC[(*arrayCSize)++] = arrayA[i++];
        // Второй случай. B[j] < A[i]. Здесь пока ничего не ясно, сдвигаем j индекс
        else if (j < arrayBSize && arrayA[i] > arrayB[j])
            j++;
        // Третий случай. Элементы равны, поэтому переходим к следующему элементу A увеличивая i
        else
            i++;
    }
}