#pragma once
#include <vector>

namespace sublist {

enum class List_comparison {
    equal,
    sublist,
    superlist,
    unequal
};

List_comparison sublist(const std::vector<int>&, const std::vector<int>&);

}  // namespace sublist
