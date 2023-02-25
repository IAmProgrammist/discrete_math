#include <stdio.h>
#include "../libs/alg/alg.h"

#define MAX_ARRAY_SIZE 10000

int main() {
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


    printf("Counting Expression One using ordered sets\n");
    size_t arrayASize1O = 5, arrayBSize1O = 5, arrayCSize1O = 5;
    int arrayA1O[MAX_ARRAY_SIZE] = {1, 2, 4, 5, 8},
            arrayB1O[MAX_ARRAY_SIZE] = {2, 3, 5, 6, 9},
            arrayC1O[MAX_ARRAY_SIZE] = {4, 5, 6, 7, 9};

    // First operation
    size_t arrayFirstOperationSize1O = 0;
    int arrayFirstOperation1O[MAX_ARRAY_SIZE] = {};
    symmetricDifferenceOrdered(arrayA1O, arrayASize1O, arrayC1O, arrayCSize1O, arrayFirstOperation1O, &arrayFirstOperationSize1O);

    // Second operation
    size_t arraySecondOperationSize1O = 0;
    int arraySecondOperation1O[MAX_ARRAY_SIZE] = {};
    intersectOrdered(arrayA1O, arrayASize1O, arrayC1O, arrayCSize1O, arraySecondOperation1O, &arraySecondOperationSize1O);

    // Third operation
    size_t arrayThirdOperationSize1O = 0;
    int arrayThirdOperation1O[MAX_ARRAY_SIZE] = {};
    intersectOrdered(arrayB1O, arrayBSize1O, arrayFirstOperation1O, arrayFirstOperationSize1O, arrayThirdOperation1O,
                     &arrayThirdOperationSize1O);

    // Fourth operation
    size_t arrayFourthOperationSize1O = 0;
    int arrayFourthOperation1O[MAX_ARRAY_SIZE] = {};
    uniteOrdered(arrayB1O, arrayBSize1O, arrayThirdOperation1O, arrayThirdOperationSize1O, arrayFourthOperation1O,
                 &arrayFourthOperationSize1O);

    // Fifth operation
    size_t arrayDSize1O = 0;
    int arrayD1O[MAX_ARRAY_SIZE] = {};
    differenceOrdered(arraySecondOperation1O, arraySecondOperationSize1O, arrayFourthOperation1O, arrayFourthOperationSize1O,
                      arrayD1O, &arrayDSize1O);

    printf("Answer: ");
    for (size_t i = 0; i < arrayDSize1O; i++)
        printf("%d ", arrayD1O[i]);

    printf("\n");
    printf("\n");

    printf("Counting Expression One using bool sets\n");
    bool arrayA1B[MAX_ARRAY_SIZE] = {false, true, true, false, true, true, false, false, true},
            arrayB1B[MAX_ARRAY_SIZE] = {false, false, true, true, false, true, true, false, false, true},
            arrayC1B[MAX_ARRAY_SIZE] = {false, false, false, false, true, true, false, true, false, true};

    // First operation
    bool arrayFirstOperation1B[MAX_ARRAY_SIZE] = {};
    symmetricDifferenceBool(arrayA1B, arrayC1B, arrayFirstOperation1B, MAX_ARRAY_SIZE);

    // Second operation
    bool arraySecondOperation1B[MAX_ARRAY_SIZE] = {};
    intersectBool(arrayA1B, arrayC1B, arraySecondOperation1B, MAX_ARRAY_SIZE);

    // Third operation
    bool arrayThirdOperation1B[MAX_ARRAY_SIZE] = {};
    intersectBool(arrayB1B, arrayFirstOperation1B, arrayThirdOperation1B, MAX_ARRAY_SIZE);

    // Fourth operation
    bool arrayFourthOperation1B[MAX_ARRAY_SIZE] = {};
    uniteBool(arrayB1B, arrayThirdOperation1B, arrayFourthOperation1B,
              MAX_ARRAY_SIZE);

    // Fifth operation
    bool arrayD1B[MAX_ARRAY_SIZE] = {};
    differenceBool(arraySecondOperation1B, arrayFourthOperation1B, arrayD1B, MAX_ARRAY_SIZE);

    printf("Answer: ");
    for (size_t i = 0; i < MAX_ARRAY_SIZE; i++)
        if (arrayD1B[i])
            printf("%zu ", i);

    printf("\n");
    printf("\n");

    printf("Counting Expression Two using unordered sets\n");
    size_t arrayASize2U = 6, arrayBSize2U = 4, arrayCSize2U = 5;
    int arrayA2U[MAX_ARRAY_SIZE] = {6, 2, 4, 7, 1, 3},
            arrayB2U[MAX_ARRAY_SIZE] = {7, 3, 6, 1},
            arrayC2U[MAX_ARRAY_SIZE] = {4, 3, 6, 5, 8};

    // First operation
    size_t arrayFirstOperationSize2U = 0;
    int arrayFirstOperation2U[MAX_ARRAY_SIZE] = {};
    symmetricDifferenceUnordered(arrayA2U, arrayASize2U, arrayC2U, arrayCSize2U, arrayFirstOperation2U, &arrayFirstOperationSize2U);

    // Second operation
    size_t arrayDSize2U = 0;
    int arrayD2U[MAX_ARRAY_SIZE] = {};
    differenceUnordered(arrayFirstOperation2U, arrayFirstOperationSize2U, arrayB2U, arrayBSize2U, arrayD2U, &arrayDSize2U);

    printf("Answer: ");
    for (size_t i = 0; i < arrayDSize2U; i++)
        printf("%d ", arrayD2U[i]);

    printf("\n");
    printf("\n");
    printf("Counting Expression Two using ordered sets\n");
    size_t arrayASize2O = 6, arrayBSize2O = 4, arrayCSize2O = 5;
    int arrayA2O[MAX_ARRAY_SIZE] = {1, 2, 3, 4, 6, 7},
            arrayB2O[MAX_ARRAY_SIZE] = {1, 3, 6, 7},
            arrayC2O[MAX_ARRAY_SIZE] = {3, 4, 5, 6, 8};

    // First operation
    size_t arrayFirstOperationSize2O = 0;
    int arrayFirstOperation2O[MAX_ARRAY_SIZE] = {};
    symmetricDifferenceOrdered(arrayA2O, arrayASize2O, arrayC2O, arrayCSize2O, arrayFirstOperation2O, &arrayFirstOperationSize2O);

    // Second operation
    size_t arrayDSize2O = 0;
    int arrayD2O[MAX_ARRAY_SIZE] = {};
    differenceOrdered(arrayFirstOperation2O, arrayFirstOperationSize2O, arrayB2O, arrayBSize2O, arrayD2O, &arrayDSize2O);

    printf("Answer: ");
    for (size_t i = 0; i < arrayDSize2O; i++)
        printf("%d ", arrayD2O[i]);

    printf("\n");
    printf("\n");
    printf("Counting Expression Two using bool sets\n");
    bool arrayA2B[MAX_ARRAY_SIZE] = {false, true, true, true, true, false, true, true},
            arrayB2B[MAX_ARRAY_SIZE] = {false, true, false, true, false, false, true, true},
            arrayC2B[MAX_ARRAY_SIZE] = {false, false, false, true, true, true, true, false, true};

    // First operation
    bool arrayFirstOperation2B[MAX_ARRAY_SIZE] = {};
    symmetricDifferenceBool(arrayA2B, arrayC2B, arrayFirstOperation2B, MAX_ARRAY_SIZE);

    // Second operation
    bool arrayD2B[MAX_ARRAY_SIZE] = {};
    differenceBool(arrayFirstOperation2B, arrayB2B, arrayD2B, MAX_ARRAY_SIZE);

    printf("Answer: ");
    for (size_t i = 0; i < MAX_ARRAY_SIZE; i++)
        if (arrayD2B[i])
            printf("%zu ", i);

    printf("\n");
    printf("\n");

    return 0;
}
