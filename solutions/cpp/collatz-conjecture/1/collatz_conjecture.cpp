#include "collatz_conjecture.h"
#include <iostream>

namespace collatz_conjecture {

int steps(int number){
    if (number <= 0) throw std::domain_error ("Numbers > 0 accepted only!");

    int steps = 0;
    while(number != 1) {
        if (number%2 == 0) number/=2;
        else number = (number*3)+1;

        ++steps;
    }
    return steps;
}

}  // namespace collatz_conjecture
