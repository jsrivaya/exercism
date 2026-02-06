#include "roman_numerals.h"

#include <iostream>
#include <map>
#include <string>

namespace roman_numerals {

//     M	D	C	L	X	V	I
//  1000	500	100	50	10	5	1
const std::string romans[13] = {
    "M", "CM",
    "D", "CD",
    "C", "XC",
    "L", "XL",
    "X", "IX",
    "V", "IV",
    "I"
};
const int decimals[13] = {
    1000, 900,
    500, 400,
    100, 90,
    50, 40,
    10, 9,
    5, 4,
    1
};

std::string convert(unsigned number) {
    std::string roman{};

    for (int i=0; i<13; ++i) {
        int times = number / decimals[i];
        number = number % decimals[i];
        for (int j=0; j<times; ++j) {
            roman += romans[i];
        }
    }

    return roman;
}
    
}  // namespace roman_numerals
