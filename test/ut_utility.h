#include "../src/rectangle.h"
#include "../src/utility.h"
#include "../src/compound_shape.h"

TEST(CaseUtility, SelectShape) {
    Shape* cs = new CompoundShape();
    Shape* s = new Rectangle(1.0, 1.0);
    Shape* s2 = new Rectangle(5.0, 5.0);

    cs -> addShape(s);
    cs -> addShape(s2);

    Shape* result = selectShape(cs, [](Shape* shape){
        return shape -> area() > 20.0 && shape -> area() < 30.0;
    });

    ASSERT_EQ(s2, result);

    delete cs, s, s2, result;
}

TEST(CaseUtility, SelectShape2) {
    Shape* cs = new CompoundShape();
    Shape* s = new Rectangle(5.0, 5.0);
    Shape* s2 = new Rectangle(1.0, 1.0);

    cs -> addShape(s);
    cs -> addShape(s2);

    Shape* result = selectShape(cs, [](Shape* shape){
        return shape -> area() > 20.0 && shape -> area() < 30.0;
    });

    ASSERT_EQ(s, result);

    delete cs, s, s2, result;
}

TEST(CaseUtility, SelectShape3) {
    Shape* cs = new CompoundShape();
    Shape* s = new Rectangle(4.0, 4.0);
    Shape* s2 = new Rectangle(4.0, 4.0);

    cs -> addShape(s);
    cs -> addShape(s2);

    Shape* result = selectShape(cs, [](Shape* shape){
        return shape -> area() > 10.0 && shape -> area() < 30.0;
    });

    ASSERT_EQ(s, result);

    delete cs, s, s2, result;
}

TEST(CaseUtility, SelectShape_NoResult) {
    Shape* cs = new CompoundShape();
    Shape* s = new Rectangle(4.0, 4.0);
    Shape* s2 = new Rectangle(5.0, 5.0);

    cs -> addShape(s);
    cs -> addShape(s2);

    Shape* result = selectShape(cs, [](Shape* shape){
        return shape -> area() > 30.0 && shape -> area() < 50.0;
    });

    ASSERT_EQ(nullptr, result);

    delete cs, s, s2, result;
}