#pragma once

#include <cmath>

#include "./iterator/null_iterator.h"
#include "./shape.h"
#include "./visitor/shape_visitor.h"

class Circle : public Shape {
public:
    Circle(double radius): _radius(radius){
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

    void accept(ShapeVisitor* visitor) override { 
        visitor->visitCircle(this); 
    }

    Iterator* createIterator() override { return new NullIterator(); }

private:
    double _radius;
};