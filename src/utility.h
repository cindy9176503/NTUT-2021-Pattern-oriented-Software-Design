// you should define a template class or type `ShapeConstraint`

#pragma once

#include "./iterator/iterator.h"
#include "./compound_shape.h"

template<class ShapeConstraint>
Shape* selectShape(Shape* shape, ShapeConstraint constraint) { 
    Iterator* it = shape -> createIterator();
    Shape* result = nullptr;
    for(it -> first(); !it -> isDone(); it -> next()) {
        if(constraint(it->currentItem())){
            result = it->currentItem();
            break;
        }
    }
    return result;
}