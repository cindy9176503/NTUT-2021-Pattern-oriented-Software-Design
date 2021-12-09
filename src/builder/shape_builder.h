#pragma once

#include "../circle.h"
#include "../rectangle.h"
#include "../two_dimensional_vector.h"
#include "../triangle.h"
#include "../compound_shape.h"

#include <stack>

class ShapeBuilder {
public:
    ~ShapeBuilder() {
        // segmentation fault

        // while (!_shapes.empty())
        // {
        //     auto item = _shapes.top();
        //     _shapes.pop();
        //     delete item;
        // }
    }

    void buildCircle(double radius) {
        _shapes.push(new Circle(radius));
    }

    void buildRectangle(double length, double width) {
        _shapes.push(new Rectangle(length, width));
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
        return _shapes.top();
    }

private:
    std::stack<Shape*> _shapes;
};