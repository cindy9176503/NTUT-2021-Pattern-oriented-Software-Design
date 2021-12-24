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
    static ShapeBuilder* getInstance() {}

    ~ShapeBuilder() {}

    void buildCircle(double radius) {}

    void buildRectangle(double length, double width) {}

    void buildTriangle(double x1, double y1, double x2, double y2) {}

    void buildCompoundBegin() {}

    void buildCompoundEnd() {}

    Shape* getShape() {}

    void reset() {}

private:
    ShapeBuilder() {
        std::cout << "Singleton constructor\n";
    };

   static ShapeBuilder instance;
};