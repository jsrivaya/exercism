#include "grains.h"
#include <cmath>
#include <ranges>

namespace grains {

unsigned long long square(unsigned int square_number){
    // 2^square_number-1
    return 1ULL << (square_number-1);
}
unsigned long long total(){
    auto result = 0ULL;
    // C++20 support:
    // for (const int i : std::views::iota(1, 65)) {
    //     result += square(i);
    // }
    // C++20 not supported:
    for (int i = 1; i<=64; ++i) {
        result += square(i);
    }
    return result;
}

}  // namespace grains
