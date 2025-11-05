#include "perfect_numbers.h"
#include<iostream>

namespace perfect_numbers {
classification classify(int n) {
    if (n <= 0) throw std::domain_error{"out of domain"};

    long long sum{};
    for(auto i = 1; i <= n/2 && sum <= n; ++i) {
        if(n%i == 0) sum += i;
    }

    if (sum > n) return classification::abundant;
    if (sum < n) return classification::deficient;

    return classification::perfect;
}
}  // namespace perfect_numbers
