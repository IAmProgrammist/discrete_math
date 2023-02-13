#include "../alg.h"

void uniteOrdered(const int *const arrayA, const size_t arrayASize,
                                 const int *const arrayB, const size_t arrayBSize,
                                 int *arrayC, size_t *const arrayCSize) {
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

void intersectOrdered(const int *const arrayA, const size_t arrayASize,
                                  const int *const arrayB, const size_t arrayBSize,
                                  int *arrayC, size_t *const arrayCSize) {
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

void differenceOrdered(const int *const arrayA, const size_t arrayASize,
                                            const int *const arrayB, const size_t arrayBSize,
                                            int *arrayC, size_t *const arrayCSize) {
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

void symmetricDifferenceOrdered(const int *const arrayA, const size_t arrayASize,
                                  const int *const arrayB, const size_t arrayBSize,
                                  int *arrayC, size_t *const arrayCSize) {
    size_t i = 0, j = 0;

    while (i < arrayASize || j < arrayBSize) {
        // Первый случай. Копируем значение из A если индекс B указывает на конец массива или
        // элемент из A меньше элемента из B
        if (j == arrayBSize || (i < arrayASize && arrayA[i] < arrayB[j]))
            arrayC[(*arrayCSize)++] = arrayA[i++];
            // Второй случай. Копируем значение из B если индекс A указывает на конец массива или
            // элемент из B меньше элемента из A
        else if (i == arrayASize || arrayA[i] > arrayB[j])
            arrayC[(*arrayCSize)++] = arrayB[j++];
            // Третий случай. Элементы равны, в этом случае нужно сдвинуть оба индекса
        else {
            j++;
            i++;
        }
    }
}

bool includesOrdered(const int *const arrayA, const size_t arrayASize,
                                const int *const arrayB, const size_t arrayBSize) {
    size_t i = 0, j = 0;
    bool result = true;

    while ((i < arrayASize || j < arrayBSize) && result) {
        // Первый случай. A[i] < B[j]. Элемент в массиве не найден, присваиваем result значение false
        if (j == arrayBSize || (i < arrayASize && arrayA[i] < arrayB[j]))
            result = false;
            // Второй случай. A[i] > B[j].  Продолжаем поиск
        else if (i == arrayASize || arrayA[i] > arrayB[j])
            j++;
            // Третий случай. Элементы равны, в этом случае нужно сдвинуть индекс i
        else
            i++;
    }

    return result;
}

bool equalOrdered(const int *const arrayA, const size_t arrayASize,
                                    const int *const arrayB, const size_t arrayBSize) {
    return arrayASize == arrayBSize &&
           includesOrdered(arrayA, arrayASize, arrayB, arrayBSize) &&
           includesOrdered(arrayB, arrayBSize, arrayA, arrayASize);
}

void fillUniversumOrdered(const int *const arrayA, const size_t arrayASize,
                         const int *const universum, const size_t universumSize,
                         int *arrayC, size_t *const arrayCSize) {
    differenceOrdered(universum, universumSize, arrayA, arrayASize, arrayC, arrayCSize);
}

bool includesStrictOrdered(const int *const arrayA, const size_t arrayASize,
                             const int *const arrayB, const size_t arrayBSize) {
    return !equalOrdered(arrayA, arrayASize, arrayB, arrayBSize) &&
           includesOrdered(arrayA, arrayASize, arrayB, arrayBSize);
}