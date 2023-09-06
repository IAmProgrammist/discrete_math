#include <stdio.h>
#include "../algc.h"

void initCorrespondence(bool ***corr, int size) {
    *corr = malloc(sizeof(bool*) * size);

    for (int i = 0; i < size; i++) {
        (*corr)[i] = calloc(size, sizeof(bool));
    }
}

void clearCorrespondence(bool **corr, int size) {
    for (int i = 0; i < size; i++) {
        free(corr[i]);
    }

    free(corr);
}

void inputCorrespondence(bool **corr, int amount) {
    for (int i = 0; i < amount; i++) {
        int direction, arrive;
        scanf("%d %d", &direction, &arrive);

        corr[direction][arrive] = true;
    }
}

bool isFunction(bool **corr, int size) {
    for (int i = 0; i < size; i++) {
        int tAmount = 0;

        for (int j = 0; j < size; j++) {
            tAmount += corr[i][j];

            if (tAmount > 1)
                return false;
        }
    }

    return true;
}

bool isDisplay(bool **corr, int size) {
    if (!isFunction(corr, size))
        return false;

    for (int i = 0; i < size; i++) {
        int tAmount = 0;

        for (int j = 0; j < size; j++)
            tAmount += corr[i][j];

        if (tAmount == 0) return false;
    }

    return true;
}

bool isSurjective(bool **corr, int size) {
    if (!isFunction(corr, size))
        return false;

    for (int i = 0; i < size; i++) {
        int tAmount = 0;

        for (int j = 0; j < size; j++)
            tAmount += corr[j][i];

        if (tAmount == 0) return false;
    }

    return true;
}

bool isInjective(bool **corr, int size) {
    if (!isFunction(corr, size))
        return false;

    for (int i = 0; i < size; i++) {
        int tAmount = 0;

        for (int j = 0; j < size; j++) {
            tAmount += corr[j][i];

            if (tAmount > 1)
                return false;
        }
    }

    return true;
}

bool isBijective(bool **corr, int size) {
    return isDisplay(corr, size) && isSurjective(corr, size) && isInjective(corr, size);
}
