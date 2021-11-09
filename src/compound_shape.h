#pragma once

#include "./shape.h"
#include "./iterator/iterator.h"
#include "./iterator/null_iterator.h"
#include "./iterator/compound_iterator.h"

#include <list>



class CompoundShape : public Shape {
public:
    ~CompoundShape() {
        for (auto it = _shapes.begin(); it != _shapes.end(); ++ it) {
            delete *it;
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
        if(!_shapes.size()) { throw "empty"; return 0;}
        std::string result = "CompoundShape\n{\n";
        for (auto it = _shapes.begin(); it != _shapes.end(); ++ it) {
            result += (*it) -> info();
            result += "\n";
        }
        result += "}";

        return result;      
    }

    Iterator* createIterator() override { return new CompoundIterator<std::list<Shape*>::iterator>(_shapes.begin(), _shapes.end()); }

    void addShape(Shape* shape) override { _shapes.push_back(shape); }

    void deleteShape(Shape* shape) override {
        if(!_shapes.size()) { throw "empty"; }
        else {
            _shapes.remove(shape);

            // for (auto del_it = _shapes.begin(); del_it != _shapes.end(); ++ del_it) {
            //     if (*del_it == shape) { 
            //         del_it = _shapes.erase(del_it); 
            //         return;
            //     }    
            // }
            // throw "can't find the shape to delete";
        }
    }

    void accept(ShapeVisitor* visitor) {
        visitor->visitCompoundShape(this);
    }

private:
    std::list<Shape*> _shapes;
};