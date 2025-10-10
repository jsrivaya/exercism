#include "trinary.h"
#include<algorithm>
#include<cmath>
#include <cctype>

namespace trinary {

int to_decimal(const std::string& trinary){
    int result = 0;
    int pow = 0;
    std::for_each(trinary.rbegin(), trinary.rend(), [&pow, &result](const char c) {
        if(!std::isdigit(c)) return;

        result += (c-'0') * std::pow(3, pow);
        ++pow;
    });
    return result;
}

}  // namespace trinary
