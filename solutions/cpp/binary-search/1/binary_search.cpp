#include "binary_search.h"
#include <iostream>

namespace binary_search {

std::size_t find(const std::vector<int>& data, int song) {

    int ptr_1 = 0;
    int ptr_2 = data.size() - 1;

    while(ptr_1 <= ptr_2) {
        auto middle = ptr_1 + (ptr_2 - ptr_1) / 2;
        if (data[middle] == song) {
            return middle;
        } else if (data[middle] > song) {
            ptr_2 = middle - 1;
        } else {
            ptr_1 = middle + 1;
        }
    }
    throw std::domain_error("not found");
}
    
}  // namespace binary_search
