#include "two_fer.h"

namespace two_fer {

std::string two_fer(const std::string_view name){
    std::ostringstream oss;
    oss << "One for " << name << ", one for me.";
    return oss.str();
}

}  // namespace two_fer
