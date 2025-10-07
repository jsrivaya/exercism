#include "pangram.h"
#include <algorithm>
#include <iostream>
#include <bitset>

namespace pangram {

bool is_pangram(std::string str) {
    std::bitset<26> alphabet;

    for(auto& letter : str)
        if(std::isalpha(letter))
            alphabet.set(std::tolower(letter) - 'a');

    return alphabet.all();
}
}  // namespace pangram
