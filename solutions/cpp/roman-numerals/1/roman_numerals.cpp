#include "roman_numerals.h"

#include <iostream>
#include <map>
#include <string>

namespace roman_numerals {

//     M	D	C	L	X	V	I
//  1000	500	100	50	10	5	1

std::map<int, std::string> map {
    {1, "I"},
    {2, "II"},
    {3, "III"},
    {4, "IV"},
    {5, "V"},
    {9, "IX"},
    {10, "X"},
    {40, "XL"},
    {50, "L"},
    {90, "XC"},
    {100, "C"},
    {400, "CD"},
    {500, "D"},
    {900, "CM"},
    {1000, "M"},
};

std::string convert(unsigned number) {
    std::string roman{};
    for(int i = 1000; number > 0; i/=10) {
        int div = number / i;
        number = number % i;
        if (div == 9) {
            roman += map[9*i];
        } else if (div >= 5) {
            roman += map[5*i];
            while (div > 5) {
                roman += map[i];
                --div;
            }
        } else if (div == 4) {
            roman += map[4*i];
        } else {
            while (div > 0) {
                roman += map[i];
                --div;
            }
        }
    }
    /* a more naive solution:
    // 1000s
    std::string roman{};
    auto div = number / 1000;
    number = number % 1000;
    while (div>0) {
        roman += "M";
        --div;
    }
    // 100s
    div = number / 100;
    number = number % 100;
    if (div == 9) {
        roman += "CM";
    } else if (div >= 5) {
        roman += "D";
        while (div > 5) {
            roman += "C";
            --div;
        }
    } else if (div == 4) {
        roman += "CD";
    } else {
        while (div > 0) {
            roman += "C";
            --div;
        }
    }
    // 10s
    div = number / 10;
    number = number % 10;
    if (div == 9) {
        roman += "XC";
    } else if (div >= 5) {
        roman += "L";
        while (div > 5) {
            roman += "X";
            --div;
        }
    } else if (div == 4) {
        roman += "XL";
    } else {
        while (div > 0) {
            roman += "X";
            --div;
        }
    }

    // 1s
    if (number == 9) {
        roman += "IX";
    } else if (number >= 5) {
        roman += "V";
        while (number > 5) {
            roman += "I";
            --number;
        }
    } else if (number == 4) {
        roman += "IV";
    } else {
        while (number > 0) {
            roman += "I";
            --number;
        }
    }
*/
    return roman;
}
    
}  // namespace roman_numerals
