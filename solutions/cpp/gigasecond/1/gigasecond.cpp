#include "gigasecond.h"

namespace gigasecond {

ptime advance(const ptime& date){
    return date + seconds(1000000000);
}

}  // namespace gigasecond
