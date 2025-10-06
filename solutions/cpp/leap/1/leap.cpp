#include "leap.h"

namespace leap {

bool is_leap_year(const int year) {
    if (year%100 == 0) {
        return year%400 == 0 ? true : false;
    }
    return year%4 == 0 ? true : false;
}
    
}  // namespace leap
