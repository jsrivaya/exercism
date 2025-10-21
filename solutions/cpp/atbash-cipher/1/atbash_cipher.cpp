#include "atbash_cipher.h"

namespace atbash_cipher {

std::string encode(const std::string& str){
    std::string result{};
    int count{};

    for(auto& c : str) {
        if (!std::isalnum(c)) continue;
        result += std::isalpha(c) ? 'a' + 'z' - std::tolower(c) : c;

        if (++count % 5 == 0) result += ' ';
    }

    if (!result.empty() && result.back() == ' ') {
        result.pop_back();
    }
    return result;
}
    
std::string decode(const std::string& str){
    std::string result;
    result.reserve(str.size());

    for (const unsigned char c : str) {
        if (std::isdigit(c)) result += c;
        else if (std::isalpha(c)) result += 'a' + 'z' - std::tolower(c);
    }

    return result;
}

}  // namespace atbash_cipher
