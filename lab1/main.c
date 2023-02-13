#include <printf.h>
#include "../libs/alg/alg.h"

#define MAX_ARRAY_SIZE 10000

void countExpressionOneUsingUnorderedSets();

void countExpressionOneUsingOrderedSets();

void countExpressionOneUsingBoolSets();

void countExpressionTwoUsingUnorderedSets();

void countExpressionTwoUsingOrderedSets();

void countExpressionTwoUsingBoolSets();

int main() {
    countExpressionOneUsingUnorderedSets();
    countExpressionOneUsingOrderedSets();
    countExpressionOneUsingBoolSets();

    countExpressionTwoUsingUnorderedSets();
    countExpressionTwoUsingOrderedSets();
    countExpressionTwoUsingBoolSets();
}

void countExpressionOneUsingUnorderedSets() {
    printf("Counting Expression One using unordered sets\n");
    size_t arrayASize = 5, arrayBSize = 5, arrayCSize = 5;
    int arrayA[MAX_ARRAY_SIZE] = {5, 8, 4, 1, 2},
            arrayB[MAX_ARRAY_SIZE] = {6, 3, 9, 2, 5},
            arrayC[MAX_ARRAY_SIZE] = {4, 9, 7, 6, 5};

    // First operation
    size_t arrayFirstOperationSize = 0;
    int arrayFirstOperation[MAX_ARRAY_SIZE] = {};
    symmetricDifferenceUnordered(arrayA, arrayASize, arrayC, arrayCSize, arrayFirstOperation, &arrayFirstOperationSize);

    // Second operation
    size_t arraySecondOperationSize = 0;
    int arraySecondOperation[MAX_ARRAY_SIZE] = {};
    intersectUnordered(arrayA, arrayASize, arrayC, arrayCSize, arraySecondOperation, &arraySecondOperationSize);

    // Third operation
    size_t arrayThirdOperationSize = 0;
    int arrayThirdOperation[MAX_ARRAY_SIZE] = {};
    intersectUnordered(arrayB, arrayBSize, arrayFirstOperation, arrayFirstOperationSize, arrayThirdOperation,
                       &arrayThirdOperationSize);

    // Fourth operation
    size_t arrayFourthOperationSize = 0;
    int arrayFourthOperation[MAX_ARRAY_SIZE] = {};
    uniteUnordered(arrayB, arrayBSize, arrayThirdOperation, arrayThirdOperationSize, arrayFourthOperation,
                   &arrayFourthOperationSize);

    // Fifth operation
    size_t arrayDSize = 0;
    int arrayD[MAX_ARRAY_SIZE] = {};
    differenceUnordered(arraySecondOperation, arraySecondOperationSize, arrayFourthOperation, arrayFourthOperationSize,
                        arrayD, &arrayDSize);

    printf("Answer: ");
    for (size_t i = 0; i < arrayDSize; i++)
        printf("%d ", arrayD[i]);

    printf("\n");
    printf("\n");
}

void countExpressionTwoUsingOrderedSets() {
    printf("Counting Expression Two using ordered sets\n");
    size_t arrayASize = 6, arrayBSize = 4, arrayCSize = 5;
    int arrayA[MAX_ARRAY_SIZE] = {1, 2, 3, 4, 6, 7},
            arrayB[MAX_ARRAY_SIZE] = {1, 3, 6, 7},
            arrayC[MAX_ARRAY_SIZE] = {3, 4, 5, 6, 8};

    // First operation
    size_t arrayFirstOperationSize = 0;
    int arrayFirstOperation[MAX_ARRAY_SIZE] = {};
    symmetricDifferenceOrdered(arrayA, arrayASize, arrayC, arrayCSize, arrayFirstOperation, &arrayFirstOperationSize);

    // Second operation
    size_t arrayDSize = 0;
    int arrayD[MAX_ARRAY_SIZE] = {};
    differenceOrdered(arrayFirstOperation, arrayFirstOperationSize, arrayB, arrayBSize, arrayD, &arrayDSize);

    printf("Answer: ");
    for (size_t i = 0; i < arrayDSize; i++)
        printf("%d ", arrayD[i]);

    printf("\n");
    printf("\n");
}

void countExpressionTwoUsingUnorderedSets() {
    printf("Counting Expression Two using unordered sets\n");
    size_t arrayASize = 6, arrayBSize = 4, arrayCSize = 5;
    int arrayA[MAX_ARRAY_SIZE] = {6, 2, 4, 7, 1, 3},
            arrayB[MAX_ARRAY_SIZE] = {7, 3, 6, 1},
            arrayC[MAX_ARRAY_SIZE] = {4, 3, 6, 5, 8};

    // First operation
    size_t arrayFirstOperationSize = 0;
    int arrayFirstOperation[MAX_ARRAY_SIZE] = {};
    symmetricDifferenceUnordered(arrayA, arrayASize, arrayC, arrayCSize, arrayFirstOperation, &arrayFirstOperationSize);

    // Second operation
    size_t arrayDSize = 0;
    int arrayD[MAX_ARRAY_SIZE] = {};
    differenceUnordered(arrayFirstOperation, arrayFirstOperationSize, arrayB, arrayBSize, arrayD, &arrayDSize);

    printf("Answer: ");
    for (size_t i = 0; i < arrayDSize; i++)
        printf("%d ", arrayD[i]);

    printf("\n");
    printf("\n");
}

void countExpressionOneUsingBoolSets() {
    printf("Counting Expression One using bool sets\n");
    bool arrayA[MAX_ARRAY_SIZE] = {false, true, true, false, true, true, false, false, true},
            arrayB[MAX_ARRAY_SIZE] = {false, false, true, true, false, true, true, false, false, true},
            arrayC[MAX_ARRAY_SIZE] = {false, false, false, false, true, true, false, true, false, true};

    // First operation
    bool arrayFirstOperation[MAX_ARRAY_SIZE] = {};
    symmetricDifferenceBool(arrayA, arrayC, arrayFirstOperation, MAX_ARRAY_SIZE);

    // Second operation
    bool arraySecondOperation[MAX_ARRAY_SIZE] = {};
    intersectBool(arrayA, arrayC, arraySecondOperation, MAX_ARRAY_SIZE);

    // Third operation
    bool arrayThirdOperation[MAX_ARRAY_SIZE] = {};
    intersectBool(arrayB, arrayFirstOperation, arrayThirdOperation, MAX_ARRAY_SIZE);

    // Fourth operation
    bool arrayFourthOperation[MAX_ARRAY_SIZE] = {};
    uniteBool(arrayB, arrayThirdOperation, arrayFourthOperation,
              MAX_ARRAY_SIZE);

    // Fifth operation
    bool arrayD[MAX_ARRAY_SIZE] = {};
    differenceBool(arraySecondOperation, arrayFourthOperation, arrayD, MAX_ARRAY_SIZE);

    printf("Answer: ");
    for (size_t i = 0; i < MAX_ARRAY_SIZE; i++)
        if (arrayD[i])
            printf("%zu ", i);

    printf("\n");
    printf("\n");
}

void countExpressionOneUsingOrderedSets() {
    printf("Counting Expression One using ordered sets\n");
    size_t arrayASize = 5, arrayBSize = 5, arrayCSize = 5;
    int arrayA[MAX_ARRAY_SIZE] = {1, 2, 4, 5, 8},
            arrayB[MAX_ARRAY_SIZE] = {2, 3, 5, 6, 9},
            arrayC[MAX_ARRAY_SIZE] = {4, 5, 6, 7, 9};

    // First operation
    size_t arrayFirstOperationSize = 0;
    int arrayFirstOperation[MAX_ARRAY_SIZE] = {};
    symmetricDifferenceOrdered(arrayA, arrayASize, arrayC, arrayCSize, arrayFirstOperation, &arrayFirstOperationSize);

    // Second operation
    size_t arraySecondOperationSize = 0;
    int arraySecondOperation[MAX_ARRAY_SIZE] = {};
    intersectOrdered(arrayA, arrayASize, arrayC, arrayCSize, arraySecondOperation, &arraySecondOperationSize);

    // Third operation
    size_t arrayThirdOperationSize = 0;
    int arrayThirdOperation[MAX_ARRAY_SIZE] = {};
    intersectOrdered(arrayB, arrayBSize, arrayFirstOperation, arrayFirstOperationSize, arrayThirdOperation,
                     &arrayThirdOperationSize);

    // Fourth operation
    size_t arrayFourthOperationSize = 0;
    int arrayFourthOperation[MAX_ARRAY_SIZE] = {};
    uniteOrdered(arrayB, arrayBSize, arrayThirdOperation, arrayThirdOperationSize, arrayFourthOperation,
                 &arrayFourthOperationSize);

    // Fifth operation
    size_t arrayDSize = 0;
    int arrayD[MAX_ARRAY_SIZE] = {};
    differenceOrdered(arraySecondOperation, arraySecondOperationSize, arrayFourthOperation, arrayFourthOperationSize,
                      arrayD, &arrayDSize);

    printf("Answer: ");
    for (size_t i = 0; i < arrayDSize; i++)
        printf("%d ", arrayD[i]);

    printf("\n");
    printf("\n");
}

void countExpressionTwoUsingBoolSets() {
    printf("Counting Expression Two using bool sets\n");
    bool arrayA[MAX_ARRAY_SIZE] = {false, true, true, true, true, false, true, true},
            arrayB[MAX_ARRAY_SIZE] = {false, true, false, true, false, false, true, true},
            arrayC[MAX_ARRAY_SIZE] = {false, false, false, true, true, true, true, false, true};

    // First operation
    bool arrayFirstOperation[MAX_ARRAY_SIZE] = {};
    symmetricDifferenceBool(arrayA, arrayC, arrayFirstOperation, MAX_ARRAY_SIZE);

    // Second operation
    bool arrayD[MAX_ARRAY_SIZE] = {};
    differenceBool(arrayFirstOperation, arrayB, arrayD, MAX_ARRAY_SIZE);

    printf("Answer: ");
    for (size_t i = 0; i < MAX_ARRAY_SIZE; i++)
        if (arrayD[i])
        printf("%zu ", i);

    printf("\n");
    printf("\n");
}
