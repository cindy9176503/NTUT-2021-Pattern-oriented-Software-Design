#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "two_dimensional_vector.h"
#include <cmath>
#include <sstream>

class Triangle: public Shape {
public:
    Triangle(TwoDimensionalVector vec1, TwoDimensionalVector vec2) : _vec1(vec1), _vec2(vec2) {
        if(vec1.y() / vec1.x() == vec2.y() / vec2.x()) { throw "Not two non-parallel two dimensional vectors"; }
    }

    double area() const override { return abs(_vec1.cross(_vec2) / 2); }

    double perimeter() const override { return _vec1.length() + _vec2.length() + _vec1.subtract(_vec2).length(); }

    std::string info() const override {
        std::stringstream stream1, stream2;
        stream1 << std::fixed << std::setprecision(2) << _vec1.x() << "," << _vec1.y();
        stream2 << std::fixed << std::setprecision(2) << _vec2.x() << "," << _vec2.y();
        std::string info = "Triangle ([" + stream1.str() + "] [" + stream2.str() + "])";

        return info;
    }
private:
    TwoDimensionalVector _vec1, _vec2;
};

#endif