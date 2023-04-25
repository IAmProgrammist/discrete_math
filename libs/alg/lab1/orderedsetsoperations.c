#include "../algc.h"

void uniteOrdered(const int *const arrayA, const size_t arrayASize,
                  const int *const arrayB, const size_t arrayBSize,
                  int *arrayC, size_t *const arrayCSize) {
    // Индексы в массиве A и B
    size_t i = 0, j = 0;

    // Пока индексы не указывают на конец массива выполняем цикл
    while (i < arrayASize && j < arrayBSize)
        if (arrayA[i] < arrayB[j])
            // Первый случай. Копируем значение из A если индекс B указывает на конец массива или
            // элемент из A меньше элемента из B
            arrayC[(*arrayCSize)++] = arrayA[i++];
        else if (arrayA[i] > arrayB[j])
            // Второй случай. Копируем значение из B если индекс A указывает на конец массива или
            // элемент из B меньше элемента из A
            arrayC[(*arrayCSize)++] = arrayB[j++];
        else {
            // Третий случай. Элементы равны, сохраняем его в С и свдигаем оба индекса
            arrayC[(*arrayCSize)++] = arrayA[i];
            i++;
            j++;
        }

    // Копируем оставшиеся элементы из A если таковые есть
    while (i < arrayASize)
        arrayC[(*arrayCSize)++] = arrayA[i++];

    // Копируем оставшиеся элементы из B если таковые есть
    while (j < arrayBSize)
        arrayC[(*arrayCSize)++] = arrayB[j++];
}

void intersectOrdered(const int *const arrayA, const size_t arrayASize,
                      const int *const arrayB, const size_t arrayBSize,
                      int *arrayC, size_t *const arrayCSize) {
    // Индексы в массиве A и B
    size_t i = 0, j = 0;

    // Пока индексы не указывают на конец массива выполняем цикл
    while (i < arrayASize && j < arrayBSize)
        // Первый случай. A меньше элемента из B
        if (arrayA[i] < arrayB[j])
            i++;
            // Второй случай. A больше элемента из B
        else if (arrayA[i] > arrayB[j])
            j++;
            // Третий случай. A равен элементу из B. В третьем случае копируем элемент и сдвигаем оба индекса
        else {
            arrayC[(*arrayCSize)++] = arrayA[i];
            i++;
            j++;
        }
}

void differenceOrdered(const int *const arrayA, const size_t arrayASize,
                       const int *const arrayB, const size_t arrayBSize,
                       int *arrayC, size_t *const arrayCSize) {
    // Индексы в массиве A и B
    size_t i = 0, j = 0;

    // Пока индексы не указывают на конец массива выполняем цикл
    while (i < arrayASize && j < arrayBSize)
        if (arrayA[i] < arrayB[j])
            // Первый случай. Элемент из A оказался меньше элемента из B или индекс j указывает на конец B
            // Если A[i] < B[j], то в B больше никогда не встретится A[i], так как все последующие элементы
            // будут больше B[j], поэтому можем добавлять элемент в C.
            // Также добавляем элемент если мы достигли конца B - больше элементов не будет, и следующие элементы A
            // в нём не встретятся
            arrayC[(*arrayCSize)++] = arrayA[i++];
        else if (arrayA[i] > arrayB[j])
            // Второй случай. B[j] < A[i]. Здесь пока ничего не ясно, сдвигаем j
            j++;
        else {
            // Третий случай. Элементы равны, поэтому переходим к следующему элементу A увеличивая i и j
            i++;
            j++;
        }

    // Копируем оставшиеся элементы из A если таковые есть
    while (i < arrayASize)
        arrayC[(*arrayCSize)++] = arrayA[i++];
}

void symmetricDifferenceOrdered(const int *const arrayA, const size_t arrayASize,
                                const int *const arrayB, const size_t arrayBSize,
                                int *arrayC, size_t *const arrayCSize) {
    // Индексы в массиве A и B
    size_t i = 0, j = 0;

    // Пока индексы не указывают на конец массива выполняем цикл
    while (i < arrayASize && j < arrayBSize)
        if (arrayA[i] < arrayB[j])
            // Первый случай. Копируем значение из A если индекс B указывает на конец массива или
            // элемент из A меньше элемента из B
            arrayC[(*arrayCSize)++] = arrayA[i++];
        else if (arrayA[i] > arrayB[j])
            // Второй случай. Копируем значение из B если индекс A указывает на конец массива или
            // элемент из B меньше элемента из A
            arrayC[(*arrayCSize)++] = arrayB[j++];
        else {
            // Третий случай. Элементы равны, в этом случае нужно сдвинуть оба индекса
            j++;
            i++;
        }

    // Копируем оставшиеся элементы из A если таковые есть
    while (i < arrayASize)
        arrayC[(*arrayCSize)++] = arrayA[i++];

    // Копируем оставшиеся элементы из B если таковые есть
    while (j < arrayBSize)
        arrayC[(*arrayCSize)++] = arrayB[j++];
}

bool includesOrdered(const int *const arrayA, const size_t arrayASize,
                     const int *const arrayB, const size_t arrayBSize) {
    size_t i = 0, j = 0;
    bool result = arrayASize <= arrayBSize &&
                  arrayA[arrayASize - 1] <= arrayB[arrayBSize - 1];

    while (i < arrayASize && result)
        // Первый случай. A[i] < B[j]. Элемент в массиве не найден, присваиваем result значение false
        if (arrayA[i] < arrayB[j])
            result = false;
            // Второй случай. A[i] > B[j].  Продолжаем поиск
        else if (arrayA[i] > arrayB[j])
            j++;
        else {
            // Третий случай. Элементы равны, в этом случае нужно сдвигаем оба индекса
            i++;
            j++;
        }

    return result;
}

bool equalOrdered(const int *const arrayA, const size_t arrayASize,
                  const int *const arrayB, const size_t arrayBSize) {
    // Если упорядоченные массивы равны, логично предположить, что и размеры их тоже равны
    if (arrayASize != arrayBSize)
        return false;

    for (size_t i = 0; i < arrayASize; i++)
        if (arrayA[i] != arrayB[i])
            return false;

    return true;
}

void fillUniversumOrdered(const int *const array, const size_t arraySize,
                          const int *const universum, const size_t universumSize,
                          int *arrayC, size_t *const arrayCSize) {
    // Алгоритм схож с алгоритмом разницы множеств
    size_t i = 0, j = 0;
    // Проверяем, что универсум действительно универсум
    assert(array[arraySize - 1] <= universum[universumSize - 1]);

    while (i < universumSize && j < arraySize) {
        if (universum[i] < array[j])
            arrayC[(*arrayCSize)++] = universum[i++];
        else if (universum[i] == array[j]){
            i++;
            j++;
        // вторым его отличием будет то, что если элемент есть в A и его нет в universum, программа будет падать
        } else assert(array[j] >= universum[i]);
    }

    while (i < universumSize)
        arrayC[(*arrayCSize)++] = universum[i++];
}

bool includesStrictOrdered(const int *const arrayA, const size_t arrayASize,
                           const int *const arrayB, const size_t arrayBSize) {
    size_t i = 0, j = 0;
    // Отличием от нестрогого включения является то, что если A и включено в B, их размеры не должны быть равны
    bool result = arrayASize < arrayBSize &&
                  arrayA[arrayASize - 1] <= arrayB[arrayBSize - 1];

    while (i < arrayASize && result)
        if (arrayA[i] < arrayB[j])
            result = false;
        else if (arrayA[i] > arrayB[j])
            j++;
        else {
            i++;
            j++;
        }

    return result;
}