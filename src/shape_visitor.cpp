#include <iostream>

#include "./shape_visitor.h"
#include "./circle.h"
#include "./rectangle.h"
#include "./triangle.h"

void ShapeInfoVisitor::visitCircle(Circle* c) {
    _result = c->info();
}

void ShapeInfoVisitor::visitRectangle(Rectangle* r) {
    _result = r->info();
}

void ShapeInfoVisitor::visitTriangle(Triangle* t) {
    _result = t->info();
}

std::string ShapeInfoVisitor::getInfo() {
    std::cout<< _result <<std::endl;
    return _result;
}