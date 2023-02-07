#include "../alg.h"

bool isBContainsEveryElementOfASets(const int *const arrayA, const size_t arrayASize,
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