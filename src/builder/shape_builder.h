#pragma once

#include <list>
#include <stack>

#include "../circle.h"
#include "../compound_shape.h"
#include "../iterator/iterator.h"
#include "../rectangle.h"
#include "../triangle.h"
#include "../two_dimensional_vector.h"

class ShapeBuilder {
public:
    static ShapeBuilder* getInstance() {
        if (_instance == nullptr) {
            _instance = new ShapeBuilder();
        }

        return _instance;
    }

    ~ShapeBuilder() {}

    void buildCircle(double radius) {
        _shapes.push(new Circle(radius));
    }

    void buildRectangle(double width, double height) {
        _shapes.push(new Rectangle(width, height));
    }

    void buildTriangle(double x1, double y1, double x2, double y2) { 
        TwoDimensionalVector vec1(x1, y1);
        TwoDimensionalVector vec2(x2, y2);   
        _shapes.push(new Triangle(vec1, vec2));
    }

    void buildCompoundBegin() {
        _shapes.push(new CompoundShape());
    }

    void buildCompoundEnd() {
        std::list<Shape*> components;
        Shape* top = _shapes.top();

        while(typeid(*top) != typeid(CompoundShape) ||
             (typeid(*top) == typeid(CompoundShape) && !top->createIterator()->isDone())) {
            components.push_back(top);
            _shapes.pop();
            top = _shapes.top();
        }
    
        if(!components.empty()) {
            for(auto it = components.rbegin(); it != components.rend(); it ++) {
                top->addShape(*it);
            }
        }
    }

    Shape* getShape() {
        if(_shapes.empty()){
            return nullptr;
        }else{
            return _shapes.top();
        }
    }

    void reset() {
        _instance = nullptr;
        while(!_shapes.empty()) {
            Shape* s = _shapes.top();
            delete s;
            _shapes.pop();
        }
    }

private:
    ShapeBuilder() {
    };

    inline static ShapeBuilder* _instance  = nullptr;

    std::stack<Shape*> _shapes;
};