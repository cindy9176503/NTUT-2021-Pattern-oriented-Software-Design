#pragma once

#include "./shape.h"
#include "./iterator/iterator.h"
#include "./iterator/null_iterator.h"
#include "./iterator/compound_iterator.h"

#include <list>
#include <sstream>

class CompoundShape : public Shape {
public:
    ~CompoundShape() { }

    double area() const override { return 0; }

    double perimeter() const override { return 0; }

    std::string info() const override {        
        return 0;     
    }

    Iterator* createIterator() override { 
        std::stringstream ss, ss2;

        //_count = _shapes -> size();
        
        ss << _shapes->size();
        std::cout << ss.str()  << std::endl;

        NullIterator* ni;
        CompoundIterator* ci;
         
        return 0;
        //return new CompoundIterator(_shapes->begin(), _shapes->end());
    }

    void addShape(Shape* shape) override { _shapes->push_back(shape); }

    void deleteShape(Shape* shape) override {
        
    }
private:
    //std::list<Shape*> _shapes;
    std::list<Shape*>* _shapes = new std::list<Shape*>;
    int _count;
};