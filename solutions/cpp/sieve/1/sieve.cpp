#include "sieve.h"
#include<iostream>
namespace sieve {

std::vector<int> primes(int number){
    std::vector<int> result;
    if(number<=1) return result;
    
    std::vector<bool> numbers(number+1, true);

    for(int i=2; i<=number; i++) {
        if(numbers[i]){ // it's prime
            for(auto j=i; j*i<=number; ++j) {
                numbers[j*i] = false; // all multiples are not prime
            }
            result.emplace_back(i);
        }
    }

    return result;
}

}  // namespace sieve
