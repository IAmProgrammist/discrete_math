#include <stdio.h>
#include "../libs/alg/algc.h"

int main() {
    bool** corr;
    initCorrespondence(&corr, CORRESPONDENCE_SIZE);

    int amount;
    scanf("%d", &amount);

    inputCorrespondence(corr, amount);

    printf("  ");

    for (int i = 0; i < CORRESPONDENCE_SIZE; i++) {
        printf("%d ", i);
    }

    printf("\n");

    for (int i = 0; i < CORRESPONDENCE_SIZE; i++) {
        printf("%d ", i);
        for (int j = 0; j < CORRESPONDENCE_SIZE; j++)
            printf("%d ", corr[i][j]);

        printf("\n");
    }

    printf("Is function? %s.\n", isFunction(corr, CORRESPONDENCE_SIZE) ? "yes" : "no");
    printf("Is display? %s.\n", isDisplay(corr, CORRESPONDENCE_SIZE) ? "yes" : "no");
    printf("Is surjective? %s.\n", isSurjective(corr, CORRESPONDENCE_SIZE) ? "yes" : "no");
    printf("Is injection? %s.\n", isInjective(corr, CORRESPONDENCE_SIZE) ? "yes" : "no");
    printf("Is bijection? %s.\n", isBijective(corr, CORRESPONDENCE_SIZE) ? "yes" : "no");

    clearCorrespondence(corr, CORRESPONDENCE_SIZE);
}