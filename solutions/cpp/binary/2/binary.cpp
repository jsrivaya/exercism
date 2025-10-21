#include "binary.h"

namespace binary {

unsigned int convert(const std::string& str) {
	auto result = 0;
	for (auto const &c : str) {
		result <<= 1;
		switch (c) {
    		case '1': result |= 1;
    		case '0': break;
    		default: return 0;
		}
	}
	return result;
}
    
}  // namespace binary
