#include "../../libs/alg/alg.h"

Sett<int> U(std::vector<int>({1, 2, 3, 4, 5, 6, 7, 8, 9, 10}));
Sett<int> A(std::vector<int>({4, 5, 7, 8, 9, 10}));
Sett<int> B(std::vector<int>({2, 3, 4, 5, 6, 10}));
Sett<int> C(std::vector<int>({4, 5, 7, 8, 10}));

// Функция для вычисления левой части уравнения
template<typename T>
Sett<T> left(Sett<T> X) {
    return A * (B + X) ^ C;
}

// Функция для вычисления правой части уравнения
template<typename T>
Sett<T> right(Sett<T> X) {
    return A - (B * X.non(U)) ^ (C * X);
}

int main() {
    // Решения уравнений
    std::vector<Sett<int>> decisions = {
            Sett<int>({9}),
            Sett<int>({1, 2, 3, 4, 5, 6, 7, 8, 9, 10}),
            Sett<int>({1, 5, 6, 9}),
            Sett<int>({1, 2, 3, 4, 5, 9, 10}),
            Sett<int>({7, 8, 9, 10}),
            Sett<int>({1, 2, 5, 6, 7, 9}),
            Sett<int>({2, 3, 7, 8, 9, 10}),
            Sett<int>({3, 4, 5, 6, 8, 9, 10})
    };

    for (auto &x: decisions)
        // Проверяем, что левая и правая части уравнений равны
        if (left(x) != right(x)) {
                std::cerr << "Множество" << std::endl;
                x.print(std::cerr);
                std::cerr << "не является решением уравнения" << std::endl;
                return 1;
        }

    std::cout << "Решения подходят для уравнения" << std::endl;

    return 0;
}