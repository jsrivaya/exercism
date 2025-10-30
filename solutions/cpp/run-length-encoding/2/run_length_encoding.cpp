#include "run_length_encoding.h"
#include <sstream>
namespace run_length_encoding {

std::string encode(const std::string& s){
    if(s.empty()) return s;

    std::stringstream result;
    auto current = s[0];
    auto count = 1;
    for (size_t i=1; i < s.length(); ++i){
        auto next = s[i];
        if(current == next){
            ++count;
        } else {
            if (count > 1) result << count;
            result << current;
            count = 1;
        }
        current = next;
    }
    if (count > 1) result << count;
    result << current;
    
    return result.str();
}
    
std::string decode(const std::string& s) {
    if (s.empty()) return s;

    std::string result;
    auto count = 1;
    for(size_t i=0; i<s.length(); ++i) {
        for(auto n=0; std::isdigit(s[i]); ++i) {
            // find the count number
            n = (n * 10) + s[i] - '0';
            count = n;
        }
        result.append(count, s[i]);
        count = 1;
    }

    return result;
}
    
}  // namespace run_length_encoding
