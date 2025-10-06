#pragma once

namespace triangle {

enum class flavor {
    none,
    equilateral,
    isosceles,
    scalene
};

flavor kind(double, double, double);

}  // namespace triangle
