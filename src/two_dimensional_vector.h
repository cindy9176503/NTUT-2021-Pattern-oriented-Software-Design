#pragma once

#include <cmath>
#include <iostream>

class TwoDimensionalVector {
   public:
    TwoDimensionalVector(double x, double y) : _x(x), _y(y) {}

    double x() const { return _x; }

    double y() const { return _y; }

    double length() const {}

    double dot(TwoDimensionalVector vec) const {}

    double cross(TwoDimensionalVector vec) const {}

    TwoDimensionalVector subtract(TwoDimensionalVector vec) const {}

    std::string info() const {}

   private:
    double _x, _y;
};
