#include "binary.h"
#include <cmath>

namespace binary {

unsigned int convert(const std::string& str) {
    unsigned dec = 0;
    auto pow = str.length() - 1;
    for(const auto& c : str) {
        if(!std::isdigit(c)) {
            return 0;
        }
        dec += (c-'0') * std::pow(2, pow);
        --pow;
    }
    return dec;
}
    
}  // namespace binary
