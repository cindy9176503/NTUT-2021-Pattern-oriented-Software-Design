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

//------------------------------------------------------------------

void SelectShapeVisitor::visitCircle(Circle* c) {
    if (_constraint) {
        if (_constraint(c)) {
            _result = c; 
        }
    }
}

void SelectShapeVisitor::visitRectangle(Rectangle* r) {
    if (_constraint) {
        if (_constraint(r)) {
            _result = r; 
        }
    }
}

void SelectShapeVisitor::visitTriangle(Triangle* t) {
    if (_constraint) {
        if (_constraint(t)) {
            _result = t; 
        }
    }
}

void SelectShapeVisitor::visitCompoundShape(CompoundShape* cs) {
    Iterator* it = cs->createIterator();
    for (it->first(); !it->isDone(); it->next()) {
        it->currentItem()->accept(this);
    }
}

Shape* SelectShapeVisitor::getShape() {
    //std::cout<< _result->info() <<std::endl;
    return _result;
}

//------------------------------------------------------------------

void SelectAllShapeVisitor::visitCircle(Circle* c) {
    if (_constraint) {
        if (_constraint(c)) {
            _result.push_back(c); 
        }
    }
}

void SelectAllShapeVisitor::visitRectangle(Rectangle* r) {
    if (_constraint) {
        if (_constraint(r)) {
            _result.push_back(r); 
        }
    }
}

void SelectAllShapeVisitor::visitTriangle(Triangle* t) {
    if (_constraint) {
        if (_constraint(t)) {
            _result.push_back(t);
        }
    }
}

void SelectAllShapeVisitor::visitCompoundShape(CompoundShape* cs) {
    Iterator* it = cs->createIterator();
    for (it->first(); !it->isDone(); it->next()) {
        it->currentItem()->accept(this);
    }
}

std::string SelectAllShapeVisitor::getResultInfo() {

    for (auto it = _result.begin(); it != _result.end(); ++ it) {
        _resultInfo += (*it) -> info();
        _resultInfo += "\n";
    }

    return _resultInfo;
}

std::list<Shape*> SelectAllShapeVisitor::getResult() {
    //std::cout<< _result.front()->info() <<std::endl;
    return _result;
}