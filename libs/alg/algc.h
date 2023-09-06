#ifndef DISCRETE_MATH_ALGC_H
#define DISCRETE_MATH_ALGC_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

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

void fillUniversumBool(const bool *const arrayA, const bool *const universum, bool *const arrayB,
                       const size_t universumSize);

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

void fillUniversumOrdered(const int *const array, const size_t arraySize,
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

#define CORRESPONDENCE_SIZE 5

void initCorrespondence(bool ***corr, int size);

void clearCorrespondence(bool **corr, int size);

void inputCorrespondence(bool **corr, int amount);

// Соответствие называется функцией, если элемент из области определения
// Имеет один и только один элемент из области значения.
// С точки зрения программы, в ряду может не быть или быть только одно значение true
// Иначе, соответствие - не функция.
bool isFunction(bool **corr, int size);

// Если область определения равна области отправления, функция является отображением.
// С точки зрения программы, если хоть в одном из рядов содержатся только нули,
// соответствие - не отображение.
bool isDisplay(bool **corr, int size);

// Если область значений равна области прибытия, функция является суръективной.
// С точки зрения программы, если хоть в одном из столбцов содержатся только нули,
// соответствие - не отображение.
bool isSurjective(bool **corr, int size);

// Функция называется инъекцией, если различные элементы из облас-
//ти определения имеют различные образы или, по другому, если прооб-
//разом любого элемента из области значений является одноэлементное
//множество.
// С точки зрения программы, в столбце может быть 0 или 1 единиц
bool isInjective(bool **corr, int size);

// Отображение биективно, если коръективно и инъективно
// С точки зрения программы всё тоже просто - используем готовые функции.
bool isBijective(bool **corr, int size);

#ifdef __cplusplus
}
#endif

#endif //DISCRETE_MATH_ALGC_H
