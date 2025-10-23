#include "matching_brackets.h"
#include<stack>
namespace matching_brackets {

bool check(const std::string& str) {
    std::stack<unsigned char> s;
    for(const auto& c : str) {
        if(c == '[' || c == '{' || c == '(') {
            s.push(c);
            continue;
        }
        if(c == ']' || c == '}' || c == ')') {
            if (s.empty()) return false;
            if ((c == ']' && s.top() != '[') ||
                (c == '}' && s.top() != '{') ||
                (c == ')' && s.top() != '(')) {
                return false;
            }
            s.pop();
        }
    }
    return s.empty();
}
    
}  // namespace matching_brackets
