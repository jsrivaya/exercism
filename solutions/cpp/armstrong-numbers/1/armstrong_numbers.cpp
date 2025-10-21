#include "armstrong_numbers.h"
#include<vector>
#include<cmath>

namespace armstrong_numbers {

bool is_armstrong_number(const unsigned int n){
    std::vector<unsigned int> digits{};
    auto number = n;
    while(number>0) {
        digits.emplace_back(number%10);
        number=number/10;
    }
    unsigned int sum{};
    for (const auto& d : digits) {
        sum += std::pow(d, digits.size());
    }    
    return n == sum;
}

}  // namespace armstrong_numbers
