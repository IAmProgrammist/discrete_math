#ifndef DISCRETE_MATH_ALG_H
#define DISCRETE_MATH_ALG_H

#include <stdlib.h>
#include <stdbool.h>

void uniteArraysWithoutRepeating(const int *const arrayA, const size_t arrayASize,
                                 const int *const arrayB, const size_t arrayBSize,
                                 int *arrayC, size_t *const arrayCSize);

void uniteRepeatingElementsArrays(const int *const arrayA, const size_t arrayASize,
                                  const int *const arrayB, const size_t arrayBSize,
                                  int *arrayC, size_t *const arrayCSize);

void getArrayWithElementsFromANotPresentInB(const int *const arrayA, const size_t arrayASize,
                                            const int *const arrayB, const size_t arrayBSize,
                                            int *arrayC, size_t *const arrayCSize);

void getArrayWithElementsFromANotPresentInB(const int *const arrayA, const size_t arrayASize,
                                            const int *const arrayB, const size_t arrayBSize,
                                            int *arrayC, size_t *const arrayCSize);

void getArrayOfNotRepeatingValues(const int *const arrayA, const size_t arrayASize,
                                  const int *const arrayB, const size_t arrayBSize,
                                  int *arrayC, size_t *const arrayCSize);

bool isBContainsEveryElementOfA(const int *const arrayA, const size_t arrayASize,
                                const int *const arrayB, const size_t arrayBSize);

bool isArraysConsistsOfSameElements(const int *const arrayA, const size_t arrayASize,
                                    const int *const arrayB, const size_t arrayBSize);

bool isArraysConsistsOfDifferentElements(const int *const arrayA, const size_t arrayASize,
                                    const int *const arrayB, const size_t arrayBSize);

void uniteArrays(const int *const arrayA, const size_t arrayASize,
                 const int *const arrayB, const size_t arrayBSize,
                 int *arrayC, size_t *arrayCSize);

void uniteRepeatingElementsInSets(const int *const arrayA, const size_t arrayASize,
                                  const int *const arrayB, const size_t arrayBSize,
                                  int *arrayC, size_t *arrayCSize);

void getUniqueElementsOfA(const int *const arrayA, const size_t arrayASize,
                          const int *const arrayB, const size_t arrayBSize,
                          int *arrayC, size_t *arrayCSize);

void uniteArraysOnlyUnique(const int *const arrayA, const size_t arrayASize,
                           const int *const arrayB, const size_t arrayBSize,
                           int *arrayC, size_t *arrayCSize);

bool isBContainsEveryElementOfASets(const int *const arrayA, const size_t arrayASize,
                                    const int *const arrayB, const size_t arrayBSize);

#endif //DISCRETE_MATH_ALG_H
