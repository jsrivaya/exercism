#include "resistor_color_duo.h"
#include<map>

namespace resistor_color_duo {
std::map<std::string, int> codes = {
    {"black", 0},
    {"brown", 1},
    {"red", 2},
    {"orange", 3},
    {"yellow", 4},
    {"green", 5},
    {"blue", 6},
    {"violet", 7},
    {"grey", 8},
    {"white", 9},
};

int value(const std::vector<std::string>& code) {
    int result = 0;
    result = result * 10 + codes[code[0]];
    result = result * 10 + codes[code[1]];

    return result;
}
    
}  // namespace resistor_color_duo
