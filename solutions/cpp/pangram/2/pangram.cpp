#include "pangram.h"
#include <algorithm>
#include <iostream>

namespace pangram {

bool is_pangram(std::string str) {
    std::vector<bool> english_alphabet(26, false);

    // transform: remove no-alphabet character
    str.erase(std::remove_if(str.begin(), str.end(),
        [](char c) {
            return !std::isalpha(c);
        }),
    str.end());

    // transform: to lowercase each character
    std::transform(str.begin(), str.end(), str.begin(), [](unsigned char c) {
        return std::tolower(c);
    });

    for(auto itr = str.begin(); itr < str.end(); ++itr) {
        auto letter = *itr - 'a';
        if (letter >= 0) english_alphabet[letter] = true;   
    }
    for(const auto& letter : english_alphabet)
        if(!letter) return false;

    return true;
    
}
}  // namespace pangram
