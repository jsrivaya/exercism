#include "yacht.h"

#include <algorithm>

namespace yacht {

bool sequal(const std::string& s1, const std::string& s2) {
    return s1.size() == s2.size() &&
        std::equal(s1.begin(), s1.end(), s2.begin(), s2.end(), [](char c1, char c2) {
            return std::tolower(c1) == std::tolower(c2);
        });
}
int four_of_a_kind (const std::vector<int>& roll) {
    for(const auto& r : roll) {
        if (const auto count = std::count(roll.cbegin(), roll.cend(), r); count >= 4) {
            return 4 * r;
        }
    }
    return 0;
}
int full_house (const std::vector<int>& roll) {
    bool low, high = false;
    int total = 0;
    for(const auto& r : roll) {
        if (const auto count = std::count(roll.cbegin(), roll.cend(), r); !low && count == 2) {
            low = true;
            total += 2 * r;
        }
        if (const auto count = std::count(roll.cbegin(), roll.cend(), r); !high && count == 3) {
            high = true;
            total += 3 * r;
        }
        if (low && high) break;
    }
    return low && high ? total : 0;
}

int straight (const std::vector<int>& roll, const std::vector<int>& values) {
    for(const auto& v : values) {
        auto f = std::find(roll.begin(), roll.end(), v);
        if (f == roll.end()) {
            return 0;
        }
    }
    return 30;
}
int choice(const std::vector<int>& roll) {
    int count = 0;
    for (const auto& r : roll) {
        count += r;
    }
    return count;
}
int yacht(const std::vector<int>& roll) {
    for (const auto& r : roll) {
        if (r != roll[0]) return 0;
    }
    return 50;
}
    
int score(const std::vector<int>& roll, const std::string& category) {

    if (sequal(category, "ones")) {
        return std::count(roll.cbegin(), roll.cend(), 1);
    } else if (sequal(category, "twos")) {
        return 2 * std::count(roll.cbegin(), roll.cend(), 2);
    } else if (sequal(category, "threes")) {
        return 3 * std::count(roll.cbegin(), roll.cend(), 3);
    } else if (sequal(category, "fours")) {
        return 4 * std::count(roll.cbegin(), roll.cend(), 4);
    } else if (sequal(category, "fives")) {
        return 5 * std::count(roll.cbegin(), roll.cend(), 5);
    } else if (sequal(category, "sixes")) {
        return 6 * std::count(roll.cbegin(), roll.cend(), 6);
    } else if (sequal(category, "full house")) {
        return full_house(roll);
    } else if (sequal(category, "four of a kind")) {
        return four_of_a_kind(roll);
    } else if (sequal(category, "little straight")) {
        return straight (roll, {1, 2, 3, 4, 5});
    } else if (sequal(category, "big straight")) {
        return straight (roll, {2, 3, 4, 5, 6});
    } else if (sequal(category, "choice")) {
        return choice(roll);
    } else if (sequal(category, "yacht")) {
        return yacht(roll);
    }

    return 0;
}

}  // namespace yacht
