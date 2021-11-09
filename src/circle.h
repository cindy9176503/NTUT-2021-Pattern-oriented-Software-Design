#pragma once

#include "shape.h"
#include "iterator/null_iterator.h"
#include "./shape_visitor.h"

#include <iomanip>
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

    Iterator* createIterator() override { return new NullIterator(); }

    void accept(ShapeVisitor* visitor) { 
        visitor->visitCircle(this); 
    }
private:
    double _radius;
};