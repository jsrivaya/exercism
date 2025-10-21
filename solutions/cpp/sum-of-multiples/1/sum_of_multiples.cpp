#include "sum_of_multiples.h"
#include<set>
#include<numeric>

namespace sum_of_multiples {
std::set<unsigned int> get_multiples(const unsigned int& n, const unsigned int& max){
    std::set<unsigned int> multiples;
    for(unsigned int i=1, m=n; m<max; ++i, m=n*i)
        if(m%n==0) multiples.emplace(m);

    return multiples;
}
    
unsigned int to(const std::vector<unsigned int>& items, const unsigned int& level) {
    std::set<unsigned int> multiples;
    for(const auto i : items) {
        multiples.merge(get_multiples(i, level));
    }

    return std::accumulate(multiples.begin(), multiples.end(), 0);
}

}  // namespace sum_of_multiples
