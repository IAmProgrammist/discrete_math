#pragma once

template <typename T>
Sett<T>::Sett(std::vector<T> elms) {
    elements = elms;
    std::sort(elements.begin(), elements.end());
}

template <typename T>
Sett<T> Sett<T>::operator*(Sett<T> anotherSet) {
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

template <typename T>
Sett<T> Sett<T>::operator-(Sett<T> anotherSet) {
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

template <typename T>
Sett<T> Sett<T>::operator+(Sett<T> anotherSet) {
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

template <typename T>
Sett<T> Sett<T>::non(Sett<T> universum) {
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

template <typename T>
Sett<T> Sett<T>::operator^(Sett<T> anotherSet) {
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

template <typename T>
bool Sett<T>::operator==(Sett<T> other) {
    return elements == other.elements;
}

template <typename T>
bool Sett<T>::operator!=(Sett<T> other) {
    return !(*this == other);
}

template <class T>
std::ostream& operator<<(std::ostream& output, const Sett<T>& outputElement) {
    for (int i = 0; i < outputElement.elements.size(); i++) {
        output << outputElement.elements[i] << " ";
    }

    return output;
}