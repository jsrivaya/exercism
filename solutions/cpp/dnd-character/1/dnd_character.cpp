#include "dnd_character.h"

#include <algorithm>
#include <cmath>
#include <numeric>
#include <random>

namespace dnd_character {

int ability() {
    std::random_device rd; // Obtain a random seed from the OS
    std::mt19937 gen(rd()); // Use the seed to initialize the generator
    std::uniform_int_distribution<> dis(1, 6); // Define the range [1, 6]

    std::vector<int> values;
    for(int i = 0; i<4; ++i) {
        values.emplace_back(dis(gen));
    }
    std::sort(values.begin(), values.end());
    
    return std::accumulate(values.begin(), values.begin() + 3, 0);
}

int modifier (const int n) {
    return std::floor(static_cast<float>(n - 10) / 2);
}

}  // namespace dnd_character
