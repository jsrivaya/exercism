#include "isogram.h"

#include <unordered_set>

namespace isogram {

bool is_isogram(const std::string& word) {
    std::unordered_set<char> letters{};

    for (const auto& c : word) {
        if (c != '-' && c != ' ') {
            if(letters.find(std::tolower(c)) != letters.end()) return false;
            letters.emplace(std::tolower(c));
        }
    }

    return true;
}

}  // namespace isogram
