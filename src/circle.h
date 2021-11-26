#pragma once

#include <cmath>

#include "./iterator/null_iterator.h"
#include "./shape.h"
#include "./visitor/shape_visitor.h"

class Circle : public Shape {
   public:
    Circle(double radius) : _radius(radius) {}

    double area() const override {}

    double perimeter() const override {}

    std::string info() const override {}

    void accept(ShapeVisitor* visitor) override {}

    Iterator* createIterator() override {}

   private:
    double _radius;
};