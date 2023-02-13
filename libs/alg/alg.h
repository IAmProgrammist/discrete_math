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

void uniteBool(const bool *const arrayA,
               const bool *const arrayB,
               bool *arrayC, size_t universumSize);

void intersectBool(const bool *const arrayA,
                   const bool *const arrayB,
                   bool *arrayC, size_t universumSize);

void differenceBool(const bool *const arrayA,
                    const bool *const arrayB,
                    bool *arrayC, size_t universumSize);

void symmetricDifferenceBool(const bool *const arrayA,
                             const bool *const arrayB,
                             bool *arrayC, size_t universumSize);

bool includesBool(const bool *const arrayA,
                  const bool *const arrayB, const size_t universumSize);

bool equalBool(const bool *const arrayA,
               const bool *const arrayB, const size_t universumSize);

void fillUniversumBool(const bool *const arrayA, bool *const arrayC, const size_t universumSize);

bool includesStrictBool(const bool *const arrayA,
                        const bool *const arrayB, const size_t universumSize);


void uniteOrdered(const int *const arrayA, const size_t arrayASize,
                  const int *const arrayB, const size_t arrayBSize,
                  int *arrayC, size_t *const arrayCSize);

void intersectOrdered(const int *const arrayA, const size_t arrayASize,
                      const int *const arrayB, const size_t arrayBSize,
                      int *arrayC, size_t *const arrayCSize);

void differenceOrdered(const int *const arrayA, const size_t arrayASize,
                       const int *const arrayB, const size_t arrayBSize,
                       int *arrayC, size_t *const arrayCSize);

void symmetricDifferenceOrdered(const int *const arrayA, const size_t arrayASize,
                                const int *const arrayB, const size_t arrayBSize,
                                int *arrayC, size_t *const arrayCSize);

bool includesOrdered(const int *const arrayA, const size_t arrayASize,
                     const int *const arrayB, const size_t arrayBSize);

bool equalOrdered(const int *const arrayA, const size_t arrayASize,
                  const int *const arrayB, const size_t arrayBSize);

void fillUniversumOrdered(const int *const arrayA, const size_t arrayASize,
                          const int *const universum, const size_t universumSize,
                          int *arrayC, size_t *const arrayCSize);

bool includesStrictOrdered(const int *const arrayA, const size_t arrayASize,
                           const int *const arrayB, const size_t arrayBSize);


void uniteUnordered(const int *const arrayA, const size_t arrayASize,
                    const int *const arrayB, const size_t arrayBSize,
                    int *arrayC, size_t *const arrayCSize);

void intersectUnordered(const int *const arrayA, const size_t arrayASize,
                        const int *const arrayB, const size_t arrayBSize,
                        int *arrayC, size_t *const arrayCSize);

void differenceUnordered(const int *const arrayA, const size_t arrayASize,
                         const int *const arrayB, const size_t arrayBSize,
                         int *arrayC, size_t *const arrayCSize);

void symmetricDifferenceUnordered(const int *const arrayA, const size_t arrayASize,
                                  const int *const arrayB, const size_t arrayBSize,
                                  int *arrayC, size_t *const arrayCSize);

bool includesUnordered(const int *const arrayA, const size_t arrayASize,
                       const int *const arrayB, const size_t arrayBSize);

bool equalUnordered(const int *const arrayA, const size_t arrayASize,
                    const int *const arrayB, const size_t arrayBSize);

void fillUniversumUnordered(const int *const arrayA, const size_t arrayASize,
                            const int *const universum, const size_t universumSize,
                            int *arrayC, size_t *const arrayCSize);

bool includesStrictUnordered(const int *const arrayA, const size_t arrayASize,
                             const int *const arrayB, const size_t arrayBSize);

#endif //DISCRETE_MATH_ALG_H
