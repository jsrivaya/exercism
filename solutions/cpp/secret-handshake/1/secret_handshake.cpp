#include "secret_handshake.h"
#include "map"
#include <iostream>
#include <deque>

std::map<unsigned int, std::string> secrets {
    {1, "wink"},
    {2, "double blink"},
    {4, "close your eyes"},
    {8, "jump"},
    {16, "Reverse the order of the operations in the secret handshake."}
};

namespace secret_handshake {

std::vector<std::string> commands(unsigned int number) {
    std::deque<std::string> dq{};
    bool reverse{};

    unsigned int mask = 1<<4;
    for(; mask != 0; mask >>= 1) {
        if(number & mask) {
            if (mask == 16) reverse = true;
            else if (reverse) dq.emplace_back(secrets.at(mask));
            else dq.emplace_front(secrets.at(mask));
        }
    }
    return std::vector<std::string>(dq.begin(), dq.end());
}

}  // namespace secret_handshake
