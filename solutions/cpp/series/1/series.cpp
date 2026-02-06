#include "series.h"
#include <iostream>

namespace series {

std::vector<std::string> slice(const std::string& number, unsigned n) {
    if (n > number.length() || n == 0) {
        throw std::domain_error("invalid length");
    }
    std::vector<std::string> result;
    for (unsigned i=0; i+n-1 < number.length(); ++i) {
        auto sub = number.substr(i, n);
        result.emplace_back(sub);
    }

    return result;
}

}  // namespace series
