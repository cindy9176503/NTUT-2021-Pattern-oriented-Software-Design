#include "../../src/circle.h"
#include "../../src/rectangle.h"
#include "../../src/triangle.h"
#include "../../src/two_dimensional_vector.h"
#include "../../src/visitor/shape_info_visitor.h"

TEST(CaseShapeInfoVisitor, VisitCircle) {
    Circle c(17.5678);

    ShapeInfoVisitor* visitor = new ShapeInfoVisitor();
    c.accept(visitor);
    std::string result = visitor->getResult();

    ASSERT_TRUE("Circle (17.57)\n" == result);

    delete visitor;
}

TEST(CaseShapeInfoVisitor, VisitRectangle) {
    Rectangle r(5.0, 6.0);

    ShapeInfoVisitor* visitor = new ShapeInfoVisitor();
    r.accept(visitor);
    std::string result = visitor->getResult();

    ASSERT_TRUE("Rectangle (5.00 6.00)\n" == result);

    delete visitor;
}

TEST(CaseShapeInfoVisitor, VisitTriangle) {
    TwoDimensionalVector vec1(3.0, 4.0);
    TwoDimensionalVector vec2(3.0, 0.0);
    Triangle t(vec1, vec2);
   
    ShapeInfoVisitor* visitor = new ShapeInfoVisitor();
    t.accept(visitor);
    std::string result = visitor->getResult();

    ASSERT_TRUE("Triangle ([3.00,4.00] [3.00,0.00])\n" == result);

    delete visitor;
}

TEST(CaseShapeInfoVisitor, VisitCompoundShape) {
    Shape* cs = new CompoundShape();
    Shape* cs2 = new CompoundShape();
    Shape* c = new Circle(1.0);
    Shape* r = new Rectangle(5.0, 6.0);
    TwoDimensionalVector* vec1 = new TwoDimensionalVector(3.0, 4.0);
    TwoDimensionalVector* vec2 = new TwoDimensionalVector(3.0, 0.0);
    Shape* t = new Triangle(*vec1, *vec2);

    cs->addShape(c);
    cs->addShape(r);
    cs2->addShape(t);
    cs->addShape(cs2);
    
    ShapeInfoVisitor* visitor = new ShapeInfoVisitor();
    cs->accept(visitor);
    std::string result = visitor->getResult();

    ASSERT_EQ("CompoundShape {\n  Circle (1.00)\n  Rectangle (5.00 6.00)\n  CompoundShape {\n    Triangle ([3.00,4.00] [3.00,0.00])\n  }\n}\n", result); 

    delete cs, cs2, c, r, vec1, vec2, t, visitor, result;
}