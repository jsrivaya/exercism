#include "secret_handshake.h"
#include<algorithm>

namespace secret_handshake {

std::vector<std::string> commands(unsigned int number) {

    std::vector<std::string> result;
    if(number & 1) result.emplace_back("wink");
    if(number & 2) result.emplace_back("double blink");
    if(number & 4) result.emplace_back("close your eyes");
    if(number & 8) result.emplace_back("jump");
    if(number & 16) std::reverse(result.begin(), result.end());

    return result;
}

}  // namespace secret_handshake
