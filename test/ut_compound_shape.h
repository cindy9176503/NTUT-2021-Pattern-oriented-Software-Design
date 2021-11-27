#include "../src/compound_shape.h"
#include "../src/circle.h"
#include "../src/rectangle.h"
#include "../src/triangle.h"
#include "../src/two_dimensional_vector.h"
#include "../src/iterator/iterator.h"


TEST(CaseCompoundShape, AddShape) {
    CompoundShape* cs = new CompoundShape();
    Rectangle* rec = new Rectangle(1.0, 1.0);
    Rectangle* rec2 = new Rectangle(2.0, 2.0);
    Iterator* it;

    cs -> addShape(rec);
    cs -> addShape(rec2);
    
    ASSERT_NEAR(5.0, cs -> area(), 0.01);

    delete cs, rec, rec2, it;
}

TEST(CaseCompoundShape, DelectShape) {
    CompoundShape* cs = new CompoundShape();
    Rectangle* rec = new Rectangle(1.0, 1.0);
    Rectangle* rec2 = new Rectangle(2.0, 2.0);
    Iterator* it;

    cs -> addShape(rec);
    cs -> addShape(rec2);
    cs -> deleteShape(rec2);
    
    ASSERT_NEAR(1.0, cs -> area(), 0.01);

    delete cs, rec, rec2, it;
}

TEST(CaseCompoundShape, DeleteInnerShapeCorrectly) {
    CompoundShape* cs = new CompoundShape();
    CompoundShape* cs2 = new CompoundShape();
    Rectangle* rec = new Rectangle(1.0, 1.0);
    Rectangle* rec2 = new Rectangle(2.0, 2.0);
    Iterator* it;

    cs2 -> addShape(rec);
    cs2 -> addShape(rec2);
    cs -> addShape(cs2);
    cs -> deleteShape(rec2);

    ASSERT_NEAR(1.0, cs -> area(), 0.01);

    delete cs, cs2, rec, rec2, it;
}

TEST(CaseCompoundShape, Empty_Exception) {
    CompoundShape* cs = new CompoundShape();

    ASSERT_ANY_THROW(cs -> area());

    delete cs;
}

TEST(CaseCompoundShape, GetInfo) {
    CompoundShape* cs = new CompoundShape();
    Circle* c = new Circle(1.0);
    Circle* c2 = new Circle(2.0);

    cs -> addShape(c);
    cs -> addShape(c2);

    ASSERT_EQ("CompoundShape", cs -> info()); 

    delete cs, c, c2;
}

TEST(CaseCompoundShape, DeleteShape_OneShape) {
    CompoundShape* cs = new CompoundShape();
    Circle* c = new Circle(1.0);
    Iterator* it;

    cs -> addShape(c);
    cs -> deleteShape(c);

    it = cs -> createIterator();
    ASSERT_TRUE(it -> isDone());

    delete cs, c, it;
}

TEST(CaseCompoundShape, DeleteShape_OneShape_DeleteALL_IsDoneTRUE) {
    CompoundShape* cs = new CompoundShape();
    Circle* c = new Circle(1.0);
    Iterator* it;

    cs -> addShape(c);
    cs -> deleteShape(c);

    it = cs -> createIterator();
    ASSERT_TRUE(it -> isDone());

    delete cs, c, it;
}

TEST(CaseCompoundShape, DeleteShape_TwoShape) {
    CompoundShape* cs = new CompoundShape();
    Circle* c = new Circle(1.0);
    Circle* c2 = new Circle(2.0);
    Iterator* it;

    cs -> addShape(c);
    cs -> addShape(c2);
    cs -> deleteShape(c);

    it = cs -> createIterator();
    ASSERT_EQ(c2, it -> currentItem());

    delete cs, c, c2, it;
}

TEST(CaseCompoundShape, DeleteShape_TwoShape_DeleteALL_IsDoneTRUE) {
    CompoundShape* cs = new CompoundShape();
    Circle* c = new Circle(1.0);
    Circle* c2 = new Circle(2.0);
    Iterator* it;

    cs -> addShape(c);
    cs -> addShape(c2);
    cs -> deleteShape(c);
    cs -> deleteShape(c2);

    it = cs -> createIterator();
    ASSERT_TRUE(it -> isDone());

    delete cs, c, c2, it;
}

TEST(CaseCompoundShape, CreateIterator) {
    Circle *c = new Circle(1.0);  
    CompoundShape* cs = new CompoundShape();
    Iterator* it;

    cs -> addShape(c);
    it = cs -> createIterator();
    
    ASSERT_EQ(c, it -> currentItem());

    delete c, cs, it;
}