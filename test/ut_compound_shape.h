#include "../src/compound_shape.h"
#include "../src/circle.h"

TEST(CaseCompoundShape, Creation) {
    CompoundShape* cs1 = new CompoundShape();
    cs1 -> addShape(new Circle(1.1));
    cs1 -> createIterator();
    //EXPECT_EQ(3, cs.count());
    //EXPECT_NEAR(6.283+25, cs.area(), 0.001);
    delete cs1;
}
