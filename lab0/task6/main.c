#include <stdio.h>
#include <assert.h>

#include "../../libs/alg/alg.h"

#define MAX_ARRAY_SIZE 1000

void testCase1() {
    int arrayA[MAX_ARRAY_SIZE] = {4, 5, 12, 33};
    int arrayB[MAX_ARRAY_SIZE] = {17, 9, 10};
    size_t arrayASize = 4, arrayBSize = 3;

    assert(!isArraysConsistsOfSameElements(arrayA, arrayASize, arrayB, arrayBSize));

    printf("Test 1 OK\n");
}

void testCase2() {
    int arrayA[MAX_ARRAY_SIZE] = {10, 9, 17};
    int arrayB[MAX_ARRAY_SIZE] = {17, 9, 10};
    size_t arrayASize = 3, arrayBSize = 3;

    assert(isArraysConsistsOfSameElements(arrayA, arrayASize, arrayB, arrayBSize));

    printf("Test 2 OK\n");
}

void testCase3() {
    int arrayA[MAX_ARRAY_SIZE] = {};
    int arrayB[MAX_ARRAY_SIZE] = {17, 9, 10};
    size_t arrayASize = 0, arrayBSize = 3;

    assert(!isArraysConsistsOfSameElements(arrayA, arrayASize, arrayB, arrayBSize));

    printf("Test 3 OK\n");
}

void testCase4() {
    int arrayA[MAX_ARRAY_SIZE] = {17, 9, 10};
    int arrayB[MAX_ARRAY_SIZE] = {17, 9, 10};
    size_t arrayASize = 3, arrayBSize = 3;

    assert(isArraysConsistsOfSameElements(arrayA, arrayASize, arrayB, arrayBSize));

    printf("Test 4 OK\n");
}

void testCase5() {
    int arrayA[MAX_ARRAY_SIZE] = {17, 9, 10};
    int arrayB[MAX_ARRAY_SIZE] = {};
    size_t arrayASize = 3, arrayBSize = 0;

    assert(!isArraysConsistsOfSameElements(arrayA, arrayASize, arrayB, arrayBSize));

    printf("Test 5 OK\n");
}

void testCase6() {
    int arrayA[MAX_ARRAY_SIZE] = {};
    int arrayB[MAX_ARRAY_SIZE] = {};
    size_t arrayASize = 0, arrayBSize = 0;

    assert(isArraysConsistsOfSameElements(arrayA, arrayASize, arrayB, arrayBSize));

    printf("Test 6 OK\n");
}

void test() {
    testCase1();
    testCase2();
    testCase3();
    testCase4();
    testCase5();
    testCase6();
}

int main() {
    test();

    size_t aSize, bSize;
    int arrayA[MAX_ARRAY_SIZE];
    int arrayB[MAX_ARRAY_SIZE];

    scanf("%zu", &aSize);
    for(size_t i = 0; i < aSize; i++)
        scanf("%d", arrayA + i);


    scanf("%zu", &bSize);
    for(size_t i = 0; i < bSize; i++)
        scanf("%d", arrayB + i);


    bool result = isArraysConsistsOfSameElements(arrayA, aSize, arrayB, bSize);

    if (result)
        printf("YES");
    else
        printf("NO");

    return 0;
}