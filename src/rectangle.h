#pragma once

#include <iostream>

#include "./iterator/null_iterator.h"
#include "./shape.h"

class Rectangle : public Shape {
   public:
    Rectangle(double length, double width) : _length(length), _width(width) {}

    double area() const override {}

    double perimeter() const override {}

    std::string info() const override {}

    void accept(ShapeVisitor* visitor) override {}

    Iterator* createIterator() override {}

   private:
    double _length, _width;
};
