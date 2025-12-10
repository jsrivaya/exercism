#include "acronym.h"
#include <iostream>
namespace acronym {

std::string acronym(const std::string& phrase) {
    char prev = ' ';
    std::string result{};
    for (const auto& c : phrase) {
        if (!std::isalpha(prev) &&
            std::isalpha(c) &&
            prev != '\'') {
            result += std::toupper(c);
        }
        prev = c;
    }
    return result;
}

}  // namespace acronym
