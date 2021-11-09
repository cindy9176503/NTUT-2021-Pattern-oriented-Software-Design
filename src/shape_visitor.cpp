#include <iostream>
#include <string>
#include <sstream>

#include "./shape_visitor.h"
#include "./circle.h"
#include "./rectangle.h"
#include "./triangle.h"
#include "./compound_shape.h"
#include "./iterator/iterator.h"

void ShapeInfoVisitor::visitCircle(Circle* c) {
    this->infoLabel = _currentInfoLabel;
    int spaceNum = this->infoLabel * 2;
    for(int i = 0; i<spaceNum; i++) { _result += " "; }
    _result = _result + c->info();

    // std::stringstream stream1;
    // stream1 << this->infoLabel;
    // std::cout << stream1.str() << std::endl;
}

void ShapeInfoVisitor::visitRectangle(Rectangle* r) {
    this->infoLabel = _currentInfoLabel;
    int spaceNum = this->infoLabel * 2;
    for(int i = 0; i<spaceNum; i++) { _result += " "; }
    _result = _result + r->info();
}

void ShapeInfoVisitor::visitTriangle(Triangle* t) {
    this->infoLabel = _currentInfoLabel;
    int spaceNum = this->infoLabel * 2;
    for(int i = 0; i<spaceNum; i++) { _result += " "; }
    _result = _result + t->info();
}

void ShapeInfoVisitor::visitCompoundShape(CompoundShape* cs) {
    this->infoLabel = _currentInfoLabel;
    int spaceNum = this->infoLabel * 2;

    std::string space = "";
    for(int i = 0; i < spaceNum; i ++) { space += " "; }
    _result = _result + space + "CompoundShape\n" + space + "{\n";

    _currentInfoLabel ++;

    Iterator* it = cs->createIterator();
    for (it->first(); !it->isDone(); it->next()) {
        it->currentItem()->accept(this);
        _result += "\n";
    }

    _currentInfoLabel --;

    _result = _result + space + "}";

    delete it;
}

std::string ShapeInfoVisitor::getResult() {
    // std::cout<< _result <<std::endl;
    return _result;
}
