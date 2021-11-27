#pragma once

#include <iostream>
#include <list>

#include "./shape.h"
#include "./iterator/iterator.h"
#include "./iterator/null_iterator.h"
#include "./iterator/compound_iterator.h"
#include "./visitor/shape_visitor.h"

class CompoundShape : public Shape {
public:
    ~CompoundShape() {
        for(Shape* s : _shapes){
            delete s;
        }
    }

    double area() const override { 
        if(!_shapes.size()) { throw "empty"; return 0;}
        double result = 0;

        for (auto it = _shapes.begin(); it != _shapes.end(); ++ it) {
            result += (*it) -> area();
        }
        return result; 
    }

    double perimeter() const override { 
        if(!_shapes.size()) { throw "empty"; return 0;}
        double result = 0;

        for (auto it = _shapes.begin(); it != _shapes.end(); ++ it) {
            result += (*it) -> perimeter();
        }
        return result;  
    }

    std::string info() const override { 
        return "CompoundShape";      
    }

    void accept(ShapeVisitor* visitor) {
        visitor->visitCompoundShape(this);
    }

    Iterator* createIterator() override { return new CompoundIterator<std::list<Shape*>::iterator>(_shapes.begin(), _shapes.end()); }

    void addShape(Shape* shape) override { _shapes.push_back(shape); }

    void deleteShape(Shape* shape) override {
        for (auto del_it = _shapes.begin(); del_it != _shapes.end(); del_it ++) {
            if (*del_it == shape) {
                delete *del_it;
                _shapes.erase(del_it);
                break;
            }else{
                Iterator *shapeIt = (*del_it)->createIterator();
                if(!shapeIt->isDone()) {
                    (*del_it)->deleteShape(shape);
                    delete shapeIt;
                }
            }
        }
    }

private:
    std::list<Shape*> _shapes;
};