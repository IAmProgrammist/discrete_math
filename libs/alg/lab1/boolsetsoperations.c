#include "../alg.h"

static void moveIndexToNextElementInSet(const bool *const arrayA, size_t *index, size_t universumSize) {
    if (*index >= universumSize) return;

    (*index)++;
    while (*index < universumSize && !arrayA[*index])
        (*index)++;
}

void uniteBool(const bool *const arrayA,
                  const bool *const arrayB,
                  bool *arrayC, size_t universumSize) {
    // Индексы в массиве A и B
    size_t i = 0, j = 0;
    if (!arrayA[i])
        moveIndexToNextElementInSet(arrayA, &i, universumSize);
    if (!arrayB[i])
        moveIndexToNextElementInSet(arrayB, &j, universumSize);

    // Пока индексы не указывают на конец массива выполняем цикл
    while (i < universumSize || j < universumSize) {
        // Первый случай. Копируем значение из A если индекс B указывает на конец массива или
        // элемент из A меньше элемента из B
        if (j == universumSize || (i < universumSize && i < j)) {
            // Второй случай. Копируем значение из B если индекс A указывает на конец массива или
            // элемент из B меньше элемента из A
            arrayC[i] = true;

            moveIndexToNextElementInSet(arrayA, &i, universumSize);
        } else if (i == universumSize || i > j) {
            arrayC[j] = true;

            moveIndexToNextElementInSet(arrayB, &j, universumSize);
            // Третий случай. Элементы равны, в этом случае нужно сдвинуть любой из индексов, здесь мог быть как i, так и j
        } else
            moveIndexToNextElementInSet(arrayA, &i, universumSize);
    }
}

void intersectBool(const bool *const arrayA,
                      const bool *const arrayB,
                      bool *arrayC, size_t universumSize) {
    // Индексы в массиве A и B
    size_t i = 0, j = 0;
    if (!arrayA[i])
        moveIndexToNextElementInSet(arrayA, &i, universumSize);
    if (!arrayB[i])
        moveIndexToNextElementInSet(arrayB, &j, universumSize);

    // Пока индексы не указывают на конец массива выполняем цикл
    while (i < universumSize && j < universumSize) {
        // Первый случай. A меньше элемента из B
        if (i < universumSize && i < j)
            moveIndexToNextElementInSet(arrayA, &i, universumSize);
        // Второй случай. A больше элемента из B
        else if (j < universumSize && i > j)
            moveIndexToNextElementInSet(arrayB, &j, universumSize);
        // Третий случай. A равен элементу из B. В третьем случае копируем элемент и сдвигаем индекс массива A
        else {
            arrayC[i] = true;
            
            moveIndexToNextElementInSet(arrayA, &i, universumSize);
        }
    }
}

void differenceBool(const bool *const arrayA,
                       const bool *const arrayB,
                       bool *arrayC, size_t universumSize) {
    // Индексы в массиве A и B
    size_t i = 0, j = 0;
    if (!arrayA[i])
        moveIndexToNextElementInSet(arrayA, &i, universumSize);
    if (!arrayB[i])
        moveIndexToNextElementInSet(arrayB, &j, universumSize);

    // Пока индексы не указывают на конец массива выполняем цикл
    while (i < universumSize || j < universumSize) {
        // Первый случай. Элемент из A оказался меньше элемента из B или индекс j указывает на конец B
        // Если A[i] < B[j], то в B больше никогда не встретится A[i], так как все последующие элементы
        // будут больше B[j], поэтому можем добавлять элемент в C.
        // Также добавляем элемент если мы достигли конца B - больше элементов не будет, и следующие элементы A
        // в нём не встретятся
        if (j == universumSize || (i < universumSize && i < j)) {
            arrayC[i] = true;

            moveIndexToNextElementInSet(arrayA, &i, universumSize);
        // Второй случай. B[j] < A[i]. Здесь пока ничего не ясно, сдвигаем j индекс
        } else if (j < universumSize && i > j)
            moveIndexToNextElementInSet(arrayB, &j, universumSize);
        // Третий случай. Элементы равны, поэтому переходим к следующему элементу A увеличивая i
        else
            moveIndexToNextElementInSet(arrayA, &i, universumSize);
    }
}

void symmetricDifferenceBool(const bool *const arrayA,
                                const bool *const arrayB,
                                bool *arrayC, size_t universumSize) {
    size_t i = 0, j = 0;
    if (!arrayA[i])
        moveIndexToNextElementInSet(arrayA, &i, universumSize);
    if (!arrayB[i])
        moveIndexToNextElementInSet(arrayB, &j, universumSize);

    while (i < universumSize || j < universumSize) {
        // Первый случай. Копируем значение из A если индекс B указывает на конец массива или
        // элемент из A меньше элемента из B
        if (j == universumSize || (i < universumSize && i < j)) {
            arrayC[i] = true;

            moveIndexToNextElementInSet(arrayA, &i, universumSize);
        // Второй случай. Копируем значение из B если индекс A указывает на конец массива или
        // элемент из B меньше элемента из A
        } else if (i == universumSize || i > j) {
            arrayC[j] = true;

            moveIndexToNextElementInSet(arrayB, &j, universumSize);
        // Третий случай. Элементы равны, в этом случае нужно сдвинуть оба индекса
        } else {
            moveIndexToNextElementInSet(arrayA, &i, universumSize);
            moveIndexToNextElementInSet(arrayB, &j, universumSize);
        }
    }
}

bool includesBool(const bool *const arrayA,
                     const bool *const arrayB, const size_t universumSize) {
    size_t i = 0, j = 0;
    if (!arrayA[i])
        moveIndexToNextElementInSet(arrayA, &i, universumSize);
    if (!arrayB[i])
        moveIndexToNextElementInSet(arrayB, &j, universumSize);
    bool result = true;

    while ((i < universumSize || j < universumSize) && result) {
        // Первый случай. A[i] < B[j]. Элемент в массиве не найден, присваиваем result значение false
        if (j == universumSize || (i < universumSize && i < j))
            result = false;
            // Второй случай. A[i] > B[j].  Продолжаем поиск
        else if (i == universumSize || i > j)
            moveIndexToNextElementInSet(arrayB, &j, universumSize);
            // Третий случай. Элементы равны, в этом случае нужно сдвинуть индекс i
        else
            moveIndexToNextElementInSet(arrayA, &i, universumSize);
    }

    return result;
}

bool equalBool(const bool *const arrayA,
                  const bool *const arrayB, const size_t universumSize) {
    return includesBool(arrayA, arrayB, universumSize) &&
           includesBool(arrayB,  arrayA, universumSize);
}

void fillUniversumBool(const bool *const arrayA, bool *const arrayC, const size_t universumSize) {
    bool* universum = (bool*) malloc(universumSize * sizeof(bool));
    for (size_t i = 0; i < universumSize; i++)
        universum[i] = true;

    differenceBool(universum, arrayA, arrayC, universumSize);
}

bool includesStrictBool(const bool *const arrayA,
                           const bool *const arrayB, const size_t universumSize) {
    return !equalBool(arrayA, arrayB, universumSize) &&
           includesBool(arrayA, arrayB, universumSize);
}