#include "etl.h"

#include <cctype>

namespace etl {

std::map<char, int> transform(const std::map<int, std::vector<char>>& old) {
    std::vector<int> points = {1, 2, 3, 4, 5, 8, 10};

    std::map<char, int> result{};

    for (const auto& p : points) {
        auto it = old.find(p);
        if (it == old.end()) continue; // skip if key not found

        for (const auto& letter : old.at(p)) {
            result[std::tolower(letter)] = p;
        }
    }
    return result;
}
    
}  // namespace etl
