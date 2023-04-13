#include <iostream>
#include <vector>

class Sett {
public:
    std::vector<int> elements;

    Sett(std::vector<int> elms) {
        elements = elms;
        std::sort(elements.begin(), elements.end());
    }

    ~Sett() {
    }

    Sett operator*(Sett anotherSet) {
        std::vector<int> arrayC(0, 0);
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

        return Sett(arrayC);
    }

    Sett operator-(Sett anotherSet) {
        std::vector<int> arrayC(0, 0);
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

        return Sett(arrayC);
    }

    Sett operator+(Sett anotherSet) {
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

        return Sett(arrayC);
    }

    Sett non(Sett universum) {
        std::vector<int> arrayC(0, 0);
        int arraySize = elements.size();
        int universumSize = universum.elements.size();
        size_t i = 0, j = 0;
        // Проверяем, что универсум действительно универсум
        assert(elements[arraySize - 1] <= universum.elements[universumSize - 1]);

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

        return Sett(arrayC);
    }

    Sett operator^(Sett anotherSet) {
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
                j++;
                i++;
            }

        while (i < arrayASize)
            arrayC.push_back(elements[i++]);

        while (j < arrayBSize)
            arrayC.push_back(anotherSet.elements[j++]);

        return Sett(arrayC);
    }

    void print() {
        for (int i = 0; i < elements.size(); i++) {
            std::cout << elements[i] << " ";
        }

        std::cout << std::endl;
    }
};

int main() {
    Sett A(std::vector<int>({1, 3, 5, 7}));
    Sett B(std::vector<int>({2, 3, 6, 7}));
    Sett C(std::vector<int>({4, 5, 6, 7}));
    Sett U(std::vector<int>({0, 1, 2, 3, 4, 5, 6, 7}));

    Sett F3 = A.non(U) - C;
    Sett F4 = B - A - C;

    F3.print();
    F4.print();

    return 0;
}