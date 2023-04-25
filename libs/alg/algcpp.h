#ifndef DISCRETE_MATH_ALGCPP_H
#define DISCRETE_MATH_ALGCPP_H

#include <vector>
#include <iostream>

template <class T>
class Sett {
public:
    std::vector<T> elements;

    Sett<T>(std::vector<T> elms) {
        elements = elms;
        std::sort(elements.begin(), elements.end());
    }

    ~Sett() {

    }

    Sett<T> operator*(Sett<T> anotherSet) {
        std::vector<T> arrayC(0, 0);
        int arrayASize = elements.size();
        int arrayBSize = anotherSet.elements.size();
        size_t i = 0, j = 0;

        while (i < arrayASize && j < arrayBSize)
            if (elements[i] < anotherSet.elements[j])
                i++;
            else if (elements[i] > anotherSet.elements[j])
                j++;
            else {
                arrayC.push_back(elements[i]);
                i++;
                j++;
            }

        return Sett<T>(arrayC);
    }

    Sett<T> operator-(Sett<T> anotherSet) {
        std::vector<T> arrayC(0, 0);
        int arrayASize = elements.size();
        int arrayBSize = anotherSet.elements.size();
        size_t i = 0, j = 0;

        while (i < arrayASize && j < arrayBSize)
            if (elements[i] < anotherSet.elements[j])
                arrayC.push_back(elements[i++]);
            else if (elements[i] > anotherSet.elements[j])
                j++;
            else {
                i++;
                j++;
            }

        while (i < arrayASize)
            arrayC.push_back(elements[i++]);

        return Sett<T>(arrayC);
    }

    Sett<T> operator+(Sett<T> anotherSet) {
        std::vector<int> arrayC(0, 0);
        int arrayASize = elements.size();
        int arrayBSize = anotherSet.elements.size();
        size_t i = 0, j = 0;

        while (i < arrayASize && j < arrayBSize)
            if (elements[i] < anotherSet.elements[j])
                arrayC.push_back(elements[i++]);
            else if (elements[i] > anotherSet.elements[j])
                arrayC.push_back(anotherSet.elements[j++]);
            else {
                arrayC.push_back(elements[i]);
                i++;
                j++;
            }

        while (i < arrayASize)
            arrayC.push_back(elements[i++]);

        while (j < arrayBSize)
            arrayC.push_back(anotherSet.elements[j++]);

        return Sett<T>(arrayC);
    }

    Sett<T> non(Sett<T> universum) {
        std::vector<T> arrayC(0, 0);
        int arraySize = elements.size();
        int universumSize = universum.elements.size();
        size_t i = 0, j = 0;
        // Проверяем, что универсум действительно универсум
        assert(arraySize == 0 || elements[arraySize - 1] <= universum.elements[universumSize - 1]);

        while (i < universumSize && j < arraySize) {
            if (universum.elements[i] < elements[j])
                arrayC.push_back(universum.elements[i++]);
            else if (universum.elements[i] == elements[j]) {
                i++;
                j++;
                // вторым его отличием будет то, что если элемент есть в A и его нет в universum, программа будет падать
            } else
                assert(elements[j] >= universum.elements[i]);
        }

        while (i < universumSize)
            arrayC.push_back(universum.elements[i++]);

        return Sett<T>(arrayC);
    }

    Sett<T> operator^(Sett<T> anotherSet) {
        std::vector<T> arrayC(0, 0);
        int arrayASize = elements.size();
        int arrayBSize = anotherSet.elements.size();
        size_t i = 0, j = 0;

        while (i < arrayASize && j < arrayBSize)
            if (elements[i] < anotherSet.elements[j])
                arrayC.push_back(elements[i++]);
            else if (elements[i] > anotherSet.elements[j])
                arrayC.push_back(anotherSet.elements[j++]);
            else {
                j++;
                i++;
            }

        while (i < arrayASize)
            arrayC.push_back(elements[i++]);

        while (j < arrayBSize)
            arrayC.push_back(anotherSet.elements[j++]);

        return Sett<T>(arrayC);
    }

    bool operator==(Sett<T> other) {
        return elements == other.elements;
    }

    bool operator!=(Sett<T> other) {
        return !(*this == other);
    }

    void print() {
        for (int i = 0; i < elements.size(); i++) {
            std::cout << elements[i] << " ";
        }

        std::cout << std::endl;
    }

    void print(std::ostream& out) {
        for (int i = 0; i < elements.size(); i++) {
            out << elements[i] << " ";
        }

        out << std::endl;
    }
};

#endif //DISCRETE_MATH_ALGCPP_H
