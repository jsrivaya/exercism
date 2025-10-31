#include "high_scores.h"

#include <algorithm>
#include<iostream>
namespace arcade {

std::vector<int> HighScores::list_scores() {
    return scores;
}

int HighScores::latest_score() {
    return scores.back();
}

int HighScores::personal_best() {
    return *std::max_element(scores.begin(), scores.end());
}

std::vector<int> HighScores::top_three() {
    std::vector<int> sorted = scores;
    std::sort(sorted.begin(), sorted.end(), std::greater<>());
    if (sorted.size() > 3) sorted.resize(3);
    return sorted;
}   

}  // namespace arcade
