#include "../algc.h"

void uniteBool(const bool *const arrayA,
                  const bool *const arrayB,
                  bool *arrayC, size_t arrayCapacity) {
    for (size_t i = 0; i < arrayCapacity; i++) {
        // Если элемент есть хотя бы в одном из массивов, добавляем его в итоговый
        arrayC[i] = arrayA[i] || arrayB[i];
    }
}

void intersectBool(const bool *const arrayA,
                      const bool *const arrayB,
                      bool *arrayC, size_t arrayCapacity) {
    for (size_t i = 0; i < arrayCapacity; i++) {
        // Если элемент есть в обоих массивах, добавлеяем его в итоговый
        arrayC[i] = arrayA[i] && arrayB[i];
    }
}

void differenceBool(const bool *const arrayA,
                       const bool *const arrayB,
                       bool *arrayC, size_t arrayCapacity) {
    for (size_t i = 0; i < arrayCapacity; i++) {
        // Добавляем элемент только если он есть в A и его нет в B. Получили формулу из таблицы истинности
        //  A   B   F
        //  0   0   0
        //  0   1   0
        //  1   0   1
        //  1   1   0
        //
        // F = A & (!B)
        arrayC[i] = arrayA[i] && (!arrayB[i]);
    }
}

void symmetricDifferenceBool(const bool *const arrayA,
                                const bool *const arrayB,
                                bool *arrayC, size_t arrayCapacity) {
    for (size_t i = 0; i < arrayCapacity; i++) {
        // Добавляем элемент если он есть только в A или только в B. Используем операцию xor
        arrayC[i] = arrayA[i] ^ arrayB[i];
    }
}

bool includesBool(const bool *const arrayA,
                     const bool *const arrayB, const size_t arrayCapacity) {

    for (size_t i = 0; i < arrayCapacity; i++) {
        // Если элемент есть в A, но его нет в B, значит A не включено в B, возвращаем false.
        if (arrayA[i] && !arrayB[i])
            return false;
    }

    return true;
}

bool equalBool(const bool *const arrayA,
                  const bool *const arrayB, const size_t arrayCapacity) {
    for (size_t i = 0; i < arrayCapacity; i++) {
        // Тут всё просто, если элементы не равны - возвращаем false.
        if (arrayA[i] != arrayB[i])
            return false;
    }

    return true;
}

void fillUniversumBool(const bool *const arrayA, const bool *const universum, bool *const arrayB,
                       const size_t arrayCapacity) {
    for (size_t i = 0; i < arrayCapacity; i++) {
        // Если элемент есть в A, но его нет в универсуме, то произойдёт падение программы.
        assert(!arrayA[i] || universum[i]);
        // Инвертируем значения массива A и сохраняем в B. B - искомое множество. Также проверяем что A[i] есть в универсуме
        arrayB[i] = !arrayA[i] && universum[i];
    }
}

bool includesStrictBool(const bool *const arrayA,
                           const bool *const arrayB, const size_t arrayCapacity) {
    bool result = false;

    for (size_t i = 0; i < arrayCapacity; i++) {
        // Если элемент есть в A, но его нет в B, значит A не включено в B, возвращаем false.
        if (arrayA[i] && !arrayB[i])
            return false;

        // Если есть хотя бы один элемент, который есть в B, но его нет в A, можем утверждать, что множества
        // не равны
        result |= arrayB[i] && !arrayA[i];
    }

    return result;
}