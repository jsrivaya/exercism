#include "hexadecimal.h"
#include <cmath>
#include <regex>

namespace hexadecimal {
bool isHex(const std::string& str) {
    return std::regex_match(str, std::regex("^[0-9a-fA-F]+$"));
}
int getDigit(const unsigned char c) {
    if (std::isdigit(c)) {
        return (c - '0');
    }
    return 10 + std::tolower(c) - 'a';    
}

unsigned int convert(const std::string& str){
    if(!isHex(str)) return 0;
    
    int index = str.length()-1;
    int number = 0;
    for(const auto& c : str) {
        number += getDigit(c) * pow(16, index);
        --index;
    }
    return number;
}

}  // namespace hexadecimal
