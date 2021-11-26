#pragma once

#include <iostream>
#include <list>

#include "./iterator/compound_iterator.h"
#include "./shape.h"

class CompoundShape : public Shape {
   public:
    ~CompoundShape() {}

    double area() const override {}

    double perimeter() const override {}

    std::string info() const override {}

    void accept(ShapeVisitor* visitor) override {}

    Iterator* createIterator() override {}

    void addShape(Shape* shape) override {}

    void deleteShape(Shape* shape) override {}

   private:
    std::list<Shape*> _shapes;
};