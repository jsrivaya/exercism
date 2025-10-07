#include "pangram.h"
#include <algorithm>
#include <iostream>

namespace pangram {

bool is_pangram(std::string str) {
    std::vector<bool> english_alphabet(26, false);
    std::transform(str.begin(), str.end(), str.begin(), [](unsigned char c) {
        return std::tolower(c);
    });
    
    std::cout << "String: " << str << std::endl;

    for(auto itr = str.begin(); itr < str.end(); ++itr) {
        std::cout << *itr - 'a' << std::endl;
        auto letter = *itr - 'a';
        if (letter >= 0) {
             english_alphabet[letter] = true;   
        }
    }
    for(const auto& letter : english_alphabet)
        if(!letter) return false;

    return true;
    
}
}  // namespace pangram
