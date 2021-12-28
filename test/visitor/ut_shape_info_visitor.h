#include "../../src/circle.h"
#include "../../src/rectangle.h"
#include "../../src/triangle.h"
#include "../../src/two_dimensional_vector.h"
#include "../../src/visitor/shape_info_visitor.h"

TEST(CaseShapeInfoVisitor, VisitCircle) {
    Circle *c = new Circle(1.0);
    ShapeInfoVisitor* visitor = new ShapeInfoVisitor();

    visitor->visitCircle(c);

    ASSERT_TRUE("Circle (1.00)\n" == visitor->getResult());

    delete c;
    delete visitor;
}

TEST(CaseShapeInfoVisitor, VisitRectangle) {
    Rectangle *r = new Rectangle(5.0, 6.0);
    ShapeInfoVisitor* visitor = new ShapeInfoVisitor();

    visitor->visitRectangle(r);

    ASSERT_TRUE("Rectangle (5.00 6.00)\n" == visitor->getResult());

    delete r;
    delete visitor;
}

TEST(CaseShapeInfoVisitor, VisitTriangle) {
    TwoDimensionalVector vec1(3.0, 4.0);
    TwoDimensionalVector vec2(3.0, 0.0);
    Triangle *t = new Triangle(vec1, vec2);
    ShapeInfoVisitor* visitor = new ShapeInfoVisitor();

    visitor->visitTriangle(t);

    ASSERT_TRUE("Triangle ([3.00,4.00] [3.00,0.00])\n" == visitor->getResult());

    delete t;
    delete visitor;
}

TEST(CaseShapeInfoVisitor, VisitCompoundShape) {
    CompoundShape* cs = new CompoundShape();
    CompoundShape* cs2 = new CompoundShape();
    Shape* c = new Circle(1.0);
    Shape* r = new Rectangle(5.0, 6.0);
    ShapeInfoVisitor* visitor = new ShapeInfoVisitor();

    cs->addShape(c);
    cs2->addShape(r);
    cs->addShape(cs2);
    
    visitor->visitCompoundShape(cs);

    ASSERT_EQ("CompoundShape {\n  Circle (1.00)\n  CompoundShape {\n    Rectangle (5.00 6.00)\n  }\n}\n", visitor->getResult());

    delete cs;
    delete visitor;
}