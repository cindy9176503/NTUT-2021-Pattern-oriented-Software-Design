#ifndef CIRCLE_H
#define CIRCLE_H

#include "shape.h"
#include <cmath>
#include <sstream>

class Circle : public Shape {
public:
    Circle(double radius) : _radius(radius){
        if(_radius <= 0) { throw "Not a positive double radius"; }
    }

    double area() const override { return pow(_radius, 2) * M_PI; }

    double perimeter() const override { return _radius * 2 * M_PI; }

    std::string info() const override {
        std::stringstream stream;
        stream << std::fixed << std::setprecision(2) << _radius;
        std::string info = "Circle (" + stream.str() + ")";

        return info;
    }
private:
    double _radius;
};

#endif