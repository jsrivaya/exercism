#include "scrabble_score.h"
#include<unordered_map>

namespace scrabble_score {

unsigned score(const std::string& s) {
    std::unordered_map<char, int> letter_values{};
    auto add_scores = [&](std::initializer_list<char> keys, int value) {
        for (char k : keys) letter_values[k] = value;
    };
    add_scores({'A','E','I','O','U','L','N','R','S','T'}, 1);
    add_scores({'D','G'}, 2);
    add_scores({'B','C','M','P'}, 3);
    add_scores({'F','H','V','W','Y'}, 4);
    add_scores({'K'}, 5);
    add_scores({'J','X'}, 8);
    add_scores({'Q','Z'}, 10);
    
    unsigned points{};
    for(const auto& c : s) {
        points += letter_values.at(std::toupper(c));
    }
    return points;
}

}  // namespace scrabble_score
