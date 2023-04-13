#include <iostream>

bool F2(bool a, bool b, bool c) {
    return (b && !c) || (c && !(a || b));
}

bool F4(bool a, bool b, bool c) {
    return (b ^ c) && (((b && !c) && !(c && !a)) ^ (c && !a));
}

int main() {
    std::cout << "A B C F2 F4" << std::endl;
    for (int bA = 0; bA <= 1; bA++)
        for (int bB = 0; bB <= 1; bB++)
            for (int bC = 0; bC <= 1; bC++) {
                std::cout << bA << " " << bB << " " << bC << " " << F2(bA, bB, bC) << "  " << F4(bA, bB, bC) << std::endl;
            }
    std::cout << std::endl;
    return 0;
}