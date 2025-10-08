#include "nth_prime.h"
#include <cmath>
#include <iostream>
namespace nth_prime {

bool is_prime(int n) {
    if(n!=2 && n%2==0) return false;

    // at this point we can check only even numbers up to sqrt(n)
    for(int i=3; i<=sqrt(n); i+=2) {
        if(n % i == 0) return false;
    }
    return true;
}
    
int nth(int n) {
    if (n == 0) throw std::domain_error("zero is not divisible");
    if (n == 1) return 2;
    if (n == 2) return 3;
    if (n == 3) return 5;

    n -= 3;
    int i = 6;
    for(; n>0; ++i)
        if(is_prime(i)) --n;

    return i-1;
}

}  // namespace nth_prime
