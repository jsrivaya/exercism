#include "diamond.h"

namespace diamond {

std::vector<std::string> rows(const unsigned char letter) {
    auto size = 1 + (letter - 'A') * 2;
    std::string row(size, ' ');
    std::vector<std::string> result(size, row);

    // auto letter = 'A';
    for (auto i = 0; i < (1 + size / 2); ++i) {
        result[i][size/2 - i] = 'A' + i;
        result[i][size/2 + i] = 'A' + i;
    }
    for (int i = size/2; i >= 0; --i) {
        result[size-i-1][size/2 - i] = 'A' + i;
        result[size-i-1][size/2 + i] = 'A' + i;
    }
    
    return result;
}

}  // namespace diamond
