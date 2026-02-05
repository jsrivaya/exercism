#include "isbn_verifier.h"

namespace isbn_verifier {

bool is_valid(const std::string& isbn) {
    size_t count = 0;
    int mult = 10;
    int sum = 0;
    for (const auto& c : isbn) {
        if(std::isdigit(c) ||
            (count == 9 && std::toupper(c) == 'X')) {
            auto digit = (c - '0');
            if (std::toupper(c) == 'X') {
                digit = 10;
            }
            sum += digit * mult;
            ++count;
            --mult;
        } else if (c != '-') {
            return false;
        }
    }
    return (count == 10) && (sum > 0) && (sum % 11) == 0;
}

}  // namespace isbn_verifier
