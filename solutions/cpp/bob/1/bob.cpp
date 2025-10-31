#include "bob.h"
#include <cctype>
#include <map>

namespace bob {

std::map<std::string, std::string> response {
    {"question", "Sure."},
    {"yell", "Whoa, chill out!"},
    {"yell question", "Calm down, I know what I'm doing!"},
    {"silence", "Fine. Be that way!"},
    {"whatever", "Whatever."},
};

bool is_space(const unsigned char c){
    return c == ' ' || c == '\t' || c == '\n' || c == '\r';
}

std::string hey(const std::string& s){

    bool yell = false;
    bool question = false;
    bool silence = false;

    if (s.empty()) return response["silence"];

    size_t count_alpha{}, count_upper{}, count_space{};
    for(size_t i=0; i<s.length(); ++i) {
        if(is_space(s[i])) ++count_space;
        if(s[i] == '?'){
            for(; i<s.length() && (s[i]=='?' || is_space(s[i])); ++i);
            if(i == s.length()) question = true;
        }
        if(std::isalpha(s[i])) {
            ++count_alpha;
            if(std::isupper(s[i]))
                ++count_upper;
        }
    }
    if(count_alpha > 0 && count_alpha == count_upper) yell = true;
    if(count_space == s.length()) silence = true;

    if(silence) return response["silence"];
    if(yell && question) return response["yell question"];
    if(yell) return response["yell"];
    if(question) return response["question"];

    return response["whatever"];
}

}  // namespace bob
