#pragma once

#include <cmath>
#include <iostream>

#include "./iterator/null_iterator.h"
#include "./shape.h"
#include "./two_dimensional_vector.h"

class Triangle : public Shape {
   public:
    Triangle(TwoDimensionalVector vec1, TwoDimensionalVector vec2) {}

    double area() const override {}

    double perimeter() const override {}

    std::string info() const override {}

    void accept(ShapeVisitor* visitor) override {}

    Iterator* createIterator() override {}
};
