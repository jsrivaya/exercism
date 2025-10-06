#include "triangle.h"
#include <stdexcept>

namespace triangle {

bool is_triangle(double a, double b, double c) {
    if (a <= 0 || b <= 0 || c <= 0) return false;
    if (a+b < c) return false;
    if (b+c < a) return false;
    if (a+c < b) return false;

    return true;
}

int number_of_equals(double a, double b, double c) {
    if (a == b && a == c) return 3;
    if (a == b || a == c || b == c) return 2;
    return 0;
}
    
flavor kind(double a, double b, double c) {
    if (is_triangle(a,b,c)) {
        switch(number_of_equals(a,b,c)){
            case 0: return flavor::scalene;
            case 2: return flavor::isosceles;
            case 3: return flavor::equilateral;
        }
    }
    throw std::domain_error("Does not represent a triangle");
}

}  // namespace triangle
