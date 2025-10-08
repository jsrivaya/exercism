#pragma once
#include <map>
#include <string>

namespace nucleotide_count {

std::map<char, int> count(std::string_view);

}  // namespace nucleotide_count
