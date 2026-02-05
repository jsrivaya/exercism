#include "word_count.h"

#include <algorithm>
#include <cctype>
#include <vector>
#include <iostream>
namespace word_count {

std::map<std::string, int> words(const std::string& subtitle) {

    std::map<std::string, int> words_count{};
    const std::vector<char> separators = {':', '!', '?', ',', '\t', '\n', ' '};
    std::string word{};
    for (size_t i = 0; i < subtitle.size(); ++i) {
        const auto c = subtitle[i];
        if (std::isalpha(c) || std::isdigit(c) ||
            (c == '\'' && word!="" && i<(subtitle.size()-1) && std::isalpha(subtitle[i+1])
            )) {
            word += std::tolower(c);
        } else if (word != "") {
            // end of word
            words_count[word]++;
            word = "";
        }
    }
    if (word != "") {
        words_count[word]++;
    }
    return words_count;
}

}  // namespace word_count
