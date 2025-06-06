#include <iostream>

#include "bear.h"
#include "ktest.hpp"

int main() {
    ktest::runAllTests();

    Bear bear;

    while (bear.state() != BearStates::ENRAGED) {
        std::string input;
        if (!std::getline(std::cin, input)) {
            return 0;
        }

        const BearAction action = parseBearAction(input);
        std::cout << bear.doToBear(action) << std::endl;
    }

    return 0;
}