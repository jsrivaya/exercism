#include "rotational_cipher.h"

namespace rotational_cipher {

std::string rotate(const std::string s, unsigned int rot) {
    std::string result;
    result.reserve(s.capacity());

    for(const auto& c : s) {
        if (std::isalpha(c)){
            char base = std::islower(c) ? 'a' : 'A';
            char shifted = (c - base + rot) % 26;
            if (shifted < 0) shifted += 26; // Handle negative rotations
            result += base + shifted;
        } else {
            result += c;
        }
    }
    return result;
}

}  // namespace rotational_cipher
