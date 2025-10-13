#include "darts.h"
#include <cmath>

namespace darts {

int score(const float x, const float y){
    if(pow(x,2) + pow(y,2) <= pow(1,2)) return 10;
    if(pow(x,2) + pow(y,2) <= pow(5,2)) return 5;
    if(pow(x,2) + pow(y,2) <= pow(10,2)) return 1;
    return 0;
}

}  // namespace darts
