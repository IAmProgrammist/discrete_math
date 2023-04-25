#include <stdio.h>
#include <assert.h>

#include "../../libs/alg/algc.h"

#define MAX_ARRAY_SIZE 1000

void testCase1() {
    int arrayA[MAX_ARRAY_SIZE] = {4, 66, 5};
    int arrayB[MAX_ARRAY_SIZE] = {17, 9, 10};
    int arrayC[MAX_ARRAY_SIZE];
    size_t arrayCSize = 0, arrayASize = 3, arrayBSize = 3;

    uniteRepeatingElementsArrays(arrayA, arrayASize, arrayB, arrayBSize, arrayC, &arrayCSize);

    assert(arrayCSize == 0);

    printf("Test 1 OK\n");
}

void testCase2() {
    int arrayA[MAX_ARRAY_SIZE] = {1, 3, 2};
    int arrayB[MAX_ARRAY_SIZE] = {};
    int arrayC[MAX_ARRAY_SIZE];
    size_t arrayCSize = 0, arrayASize = 3, arrayBSize = 0;

    uniteRepeatingElementsArrays(arrayA, arrayASize, arrayB, arrayBSize, arrayC, &arrayCSize);

    assert(arrayCSize == 0);

    printf("Test 2 OK\n");
}

void testCase3() {
    int arrayA[MAX_ARRAY_SIZE] = {};
    int arrayB[MAX_ARRAY_SIZE] = {8, 10, 9};
    int arrayC[MAX_ARRAY_SIZE];
    size_t arrayCSize = 0, arrayASize = 0, arrayBSize = 3;

    uniteRepeatingElementsArrays(arrayA, arrayASize, arrayB, arrayBSize, arrayC, &arrayCSize);

    assert(arrayCSize == 0);

    printf("Test 3 OK\n");
}

void testCase4() {
    int arrayA[MAX_ARRAY_SIZE] = {};
    int arrayB[MAX_ARRAY_SIZE] = {};
    int arrayC[MAX_ARRAY_SIZE];
    size_t arrayCSize = 0, arrayASize = 0, arrayBSize = 0;

    uniteRepeatingElementsArrays(arrayA, arrayASize, arrayB, arrayBSize, arrayC, &arrayCSize);

    assert(arrayCSize == 0);

    printf("Test 4 OK\n");
}

void testCase5() {
    int arrayA[MAX_ARRAY_SIZE] = {1, 2, 3, 4, 5};
    int arrayB[MAX_ARRAY_SIZE] = {5, 1, 10};
    int arrayC[MAX_ARRAY_SIZE];
    size_t arrayCSize = 0, arrayASize = 5, arrayBSize = 3;

    uniteRepeatingElementsArrays(arrayA, arrayASize, arrayB, arrayBSize, arrayC, &arrayCSize);

    assert(arrayCSize == 2);
    assert(arrayC[0] == 5 &&
           arrayC[1] == 1);

    printf("Test 5 OK\n");
}

void test() {
    testCase1();
    testCase2();
    testCase3();
    testCase4();
    testCase5();
}

int main() {
    test();

    size_t aSize, bSize, cSize = 0;
    int arrayA[MAX_ARRAY_SIZE];
    int arrayB[MAX_ARRAY_SIZE];
    int arrayC[MAX_ARRAY_SIZE];

    scanf("%zu", &aSize);
    for(size_t i = 0; i < aSize; i++)
        scanf("%d", arrayA + i);


    scanf("%zu", &bSize);
    for(size_t i = 0; i < bSize; i++)
        scanf("%d", arrayB + i);


    uniteRepeatingElementsArrays(arrayA, aSize, arrayB, bSize, arrayC, &cSize);

    for (size_t i = 0; i < cSize; i++)
        printf("%d ", arrayC[i]);

    printf("\n");

    return 0;
}