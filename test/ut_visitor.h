#include <list>

#include "../src/circle.h"
#include "../src/rectangle.h"
#include "../src/triangle.h"
#include "../src/two_dimensional_vector.h"
#include "../src/compound_shape.h"
#include "../src/shape_visitor.h"


TEST(CaseVisitor, CircleInfo) {
    Circle c(17.5678);

    ShapeInfoVisitor* visitor = new ShapeInfoVisitor();
    c.accept(visitor);
    std::string result = visitor->getResult();

    ASSERT_TRUE("Circle (17.57)" == result);

    delete visitor;
}

TEST(CaseVisitor, RectangleInfo) {
    Rectangle r(5.0, 6.0);

    ShapeInfoVisitor* visitor = new ShapeInfoVisitor();
    r.accept(visitor);
    std::string result = visitor->getResult();

    ASSERT_TRUE("Rectangle (5.00 6.00)" == result);

    delete visitor;
}

TEST(CaseVisitor, TriangleInfo) {
    TwoDimensionalVector vec1(3.0, 4.0);
    TwoDimensionalVector vec2(3.0, 0.0);
    Triangle t(vec1, vec2);
   
    ShapeInfoVisitor* visitor = new ShapeInfoVisitor();
    t.accept(visitor);
    std::string result = visitor->getResult();

    ASSERT_TRUE("Triangle ([3.00,4.00] [3.00,0.00])" == result);

    delete visitor;
}

TEST(CaseVisitor, CompoundShapeInfo) {
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

    ASSERT_EQ("CompoundShape\n{\n  Circle (1.00)\n  Rectangle (5.00 6.00)\n  CompoundShape\n  {\n    Triangle ([3.00,4.00] [3.00,0.00])\n  }\n}", result); 

    delete cs, cs2, c, r, vec1, vec2, t, visitor, result;
}

//------------------------------------------------------------------------------

TEST(CaseVisitor, SelectShapeOnCircle) {
    Circle* c = new Circle(3.0);
    
    SelectShapeVisitor* visitor = new SelectShapeVisitor([](Shape* shape) {
        return shape->area() > 20.0 && shape->area() < 30.0;
    });

    c->accept(visitor);
    Shape* result = visitor->getShape();

    ASSERT_EQ(c, result);

    delete c, visitor;
}

TEST(CaseVisitor, SelectShapeOnCircleNotFound) {
    Circle* c = new Circle(1.0);
    
    SelectShapeVisitor* visitor = new SelectShapeVisitor([](Shape* shape) {
        return shape->area() > 20.0 && shape->area() < 30.0;
    });

    c->accept(visitor);
    Shape* result = visitor->getShape();

    ASSERT_EQ(nullptr, result);
    delete c, visitor;
} 

TEST(CaseVisitor, SelectShapeOnRectangle) {
    Shape* r = new Rectangle(5.0, 5.0);
    
    SelectShapeVisitor* visitor = new SelectShapeVisitor([](Shape* shape) {
        return shape->area() > 20.0 && shape->area() < 30.0;
    });
    r->accept(visitor);
    Shape* result = visitor->getShape();

    ASSERT_EQ(r, result);

    delete r, visitor, result;
}

TEST(CaseVisitor, SelectShapeOnRectangleNotFound) {
    Shape* r = new Rectangle(1.0, 1.0);
    
    SelectShapeVisitor* visitor = new SelectShapeVisitor([](Shape* shape) {
        return shape->area() > 20.0 && shape->area() < 30.0;
    });
    r->accept(visitor);
    Shape* result = visitor->getShape();

    ASSERT_EQ(nullptr, result);

    delete r, visitor, result;
}

TEST(CaseVisitor, SelectShapeOnTriangle) {
    TwoDimensionalVector vec1(3.0, 4.0);
    TwoDimensionalVector vec2(3.0, 0.0);
    Triangle* t = new Triangle(vec1, vec2);
    
    SelectShapeVisitor* visitor = new SelectShapeVisitor([](Shape* shape) {
        return shape->area() > 5.0 && shape->area() < 10.0;
    });
    t->accept(visitor);
    Shape* result = visitor->getShape();

    ASSERT_EQ(t, result);

    delete t, visitor, result;
}

TEST(CaseVisitor, SelectShapeOnTriangleNotFound) {
    TwoDimensionalVector vec1(3.0, 4.0);
    TwoDimensionalVector vec2(3.0, 0.0);
    Triangle* t = new Triangle(vec1, vec2);
    
    SelectShapeVisitor* visitor = new SelectShapeVisitor([](Shape* shape) {
        return shape->area() > 20.0 && shape->area() < 30.0;
    });
    t->accept(visitor);
    Shape* result = visitor->getShape();

    ASSERT_EQ(nullptr, result);

    delete t, visitor, result;
}

TEST(CaseVisitor, SelectShapeOnCompoundShape) {
    Shape* cs = new CompoundShape();
    Shape* c = new Circle(1.0);
    Shape* r = new Rectangle(5.0, 5.0);
    TwoDimensionalVector* vec1 = new TwoDimensionalVector(3.0, 4.0);
    TwoDimensionalVector* vec2 = new TwoDimensionalVector(3.0, 0.0);
    Shape* t = new Triangle(*vec1, *vec2);

    cs->addShape(c);
    cs->addShape(r);
    cs->addShape(t);
    
    SelectShapeVisitor* visitor = new SelectShapeVisitor([](Shape* shape) {
        return shape->area() > 20.0 && shape->area() < 30.0;
    });
    cs->accept(visitor);
    Shape* result = visitor->getShape();

    ASSERT_EQ(r, result);

    delete cs, c, r, vec1, vec2, t, visitor, result;
} 

//------------------------------------------------------------------------------

TEST(CaseVisitor, SelectAllShape_Circle) {
    Circle* c = new Circle(3.0);
    
    SelectAllShapeVisitor* visitor = new SelectAllShapeVisitor([](Shape* shape) {
        return shape->area() > 20.0 && shape->area() < 30.0;
    });

    c->accept(visitor);
    std::list<Shape*> result = visitor->getResult();

    ASSERT_EQ(c, result.front());

    delete c, visitor, result;
}

TEST(CaseVisitor, SelectAllShape_Circle_NotFound) {
    Circle* c = new Circle(1.0);
    
    SelectAllShapeVisitor* visitor = new SelectAllShapeVisitor([](Shape* shape) {
        return shape->area() > 20.0 && shape->area() < 30.0;
    });

    c->accept(visitor);
    std::list<Shape*> result = visitor->getResult();

    ASSERT_EQ(0, result.size());

    delete c, visitor, result;
}

TEST(CaseVisitor, SelectAllShape_CompoundShape) {
    Shape* cs = new CompoundShape();
    Shape* c = new Circle(3.0);
    Shape* r1 = new Rectangle(1.0, 1.0);
    Shape* r2 = new Rectangle(5.0, 5.0);

    cs->addShape(c);
    cs->addShape(r1);
    cs->addShape(r2);

    SelectAllShapeVisitor* visitor = new SelectAllShapeVisitor([](Shape* shape) {
        return shape->area() > 20.0 && shape->area() < 30.0;
    });

    cs->accept(visitor);
    std::list<Shape*> result = visitor->getResult();

    // std::cout<< result.front()->info() <<std::endl;
    // std::cout<< result.back()->info() <<std::endl;

    ASSERT_EQ(c, result.front());
    ASSERT_EQ(r2, result.back());
    ASSERT_EQ(2, result.size());

    delete cs, c, r1, r2, visitor, result;
}

TEST(CaseVisitor, SelectAllShape_GetResultInfo_CompoundShape) {
    Shape* cs = new CompoundShape();
    Shape* c = new Circle(3.0);
    Shape* r1 = new Rectangle(1.0, 1.0);
    Shape* r2 = new Rectangle(5.0, 5.0);

    cs->addShape(c);
    cs->addShape(r1);
    cs->addShape(r2);

    SelectAllShapeVisitor* visitor = new SelectAllShapeVisitor([](Shape* shape) {
        return shape->area() > 20.0 && shape->area() < 30.0;
    });

    cs->accept(visitor);
    std::string result = visitor->getResultInfo();

    std::cout<< result <<std::endl;

    delete cs, c, r1, r2, visitor, result;
}