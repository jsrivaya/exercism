#include "sublist.h"

#include <algorithm>
#include <iostream>

namespace sublist {

List_comparison sublist(const std::vector<int>& list_a, const std::vector<int>& list_b) {
    if(list_a.empty() && list_b.empty()) return List_comparison::equal;
    if(list_a.empty()) return List_comparison::sublist;
    if(list_b.empty()) return List_comparison::superlist;

    auto itr = std::search(list_a.begin(), list_a.end(), list_b.begin(), list_b.end());
    if (itr != list_a.end()) {
        if (list_a.size() == list_b.size())
            return List_comparison::equal;
        return List_comparison::superlist;
    }

    itr = std::search(list_b.begin(), list_b.end(), list_a.begin(), list_a.end());
    if (itr != list_b.end()) return List_comparison::sublist;

    return List_comparison::unequal;
}

}  // namespace sublist
