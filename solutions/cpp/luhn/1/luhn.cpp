#include "luhn.h"
#include<algorithm>
#include <cctype>

namespace luhn {

bool valid(const std::string& str){
    // reverse string, remove spaces and detect invalid characters
    std::string rev_str = "";
    bool valid = true;

    std::for_each(str.rbegin(), str.rend(), [&rev_str, &valid](unsigned char c){
        if (std::isdigit(c)) rev_str += c;
        else if (c != ' ') valid = false;
    });
    if(!valid) return false;
    if(rev_str.length() <= 1) return false;

    // calculate sum by double every other digit
    int sum = 0;
    for(size_t i=0; i<rev_str.length(); ++i) {
        int digit = (rev_str[i] - '0');
        if (i%2 != 0) {
            digit*=2;
            if(digit > 9) digit -=9;
        }
        sum += digit;
    }
    return (sum%10==0);
}

}  // namespace luhn
