#include "prime_factors.h"
namespace prime_factors {

std::vector<long long> of(long long n) {
    std::vector<long long> result{};

    if (n <= 1) return result;
    for (auto i=2; i*i<=n; ++i) {
        while (n % i == 0){
            result.emplace_back(i);
            n /= i;
        }
    }
    if (n>1) result.emplace_back(n);

    return result;
}

}  // namespace prime_factors
