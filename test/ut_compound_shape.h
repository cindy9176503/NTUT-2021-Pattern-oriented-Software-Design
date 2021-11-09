#include "../src/compound_shape.h"
#include "../src/circle.h"
#include "../src/rectangle.h"
#include "../src/triangle.h"
#include "../src/two_dimensional_vector.h"
#include "../src/iterator/iterator.h"


TEST(CaseCompoundShape, GetArea_AddShape) {
    CompoundShape* cs = new CompoundShape();
    Rectangle* rec = new Rectangle(1.0, 1.0);
    Rectangle* rec2 = new Rectangle(2.0, 2.0);
    Iterator* it;

    cs -> addShape(rec);
    cs -> addShape(rec2);
    
    ASSERT_NEAR(5.0, cs -> area(), 0.01);

    delete cs, rec, rec2, it;
}

TEST(CaseCompoundShape, GetArea_DelectShape) {
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

TEST(CaseCompoundShape, GetArea_DelectShape2) {
    CompoundShape* cs = new CompoundShape();
    Rectangle* rec = new Rectangle(1.0, 1.0);
    Rectangle* rec2 = new Rectangle(2.0, 2.0);
    Iterator* it;

    cs -> addShape(rec);
    cs -> addShape(rec2);
    cs -> deleteShape(rec);
    
    ASSERT_NEAR(4.0, cs -> area(), 0.01);

    delete cs, rec, rec2, it;
}

TEST(CaseCompoundShape, GetArea_Empty_Exception) {
    CompoundShape* cs = new CompoundShape();

    ASSERT_ANY_THROW(cs -> area());

    delete cs;
}

TEST(CaseCompoundShape, GetPerimeter_AddShape) {
    CompoundShape* cs = new CompoundShape();
    Rectangle* rec = new Rectangle(1.0, 1.0);
    Rectangle* rec2 = new Rectangle(2.0, 2.0);
    Iterator* it;

    cs -> addShape(rec);
    cs -> addShape(rec2);
    
    ASSERT_NEAR(12.0, cs -> perimeter(), 0.01);

    delete cs, rec, rec2, it;
}

TEST(CaseCompoundShape, GetPerimeter_DelectShape) {
    CompoundShape* cs = new CompoundShape();
    Rectangle* rec = new Rectangle(1.0, 1.0);
    Rectangle* rec2 = new Rectangle(2.0, 2.0);
    Iterator* it;

    cs -> addShape(rec);
    cs -> addShape(rec2);
    cs -> deleteShape(rec);

    ASSERT_NEAR(8.0, cs -> perimeter(), 0.01);

    delete cs, rec, rec2, it;
}

TEST(CaseCompoundShape, GetPerimeter_DelectShape2) {
    CompoundShape* cs = new CompoundShape();
    Rectangle* rec = new Rectangle(1.0, 1.0);
    Rectangle* rec2 = new Rectangle(2.0, 2.0);
    Iterator* it;

    cs -> addShape(rec);
    cs -> addShape(rec2);
    cs -> deleteShape(rec2);

    ASSERT_NEAR(4.0, cs -> perimeter(), 0.01);

    delete cs, rec, rec2, it;
}

TEST(CaseCompoundShape, GetPerimeter_DelectShape3) {
    CompoundShape* cs = new CompoundShape();
    Rectangle* rec = new Rectangle(1.0, 1.0);
    Rectangle* rec2 = new Rectangle(1.0, 1.0);
    Iterator* it;

    cs -> addShape(rec);
    cs -> addShape(rec2);
    cs -> deleteShape(rec);

    ASSERT_NEAR(4.0, cs -> perimeter(), 0.01);

    delete cs, rec, rec2, it;
}

TEST(CaseCompoundShape, GetInfo) {
    CompoundShape* cs = new CompoundShape();
    Circle* c = new Circle(1.0);
    Circle* c2 = new Circle(2.0);
    TwoDimensionalVector* vec1 = new TwoDimensionalVector(3.0, 4.0);
    TwoDimensionalVector* vec2 = new TwoDimensionalVector(3.0, 0.0);
    Triangle* t = new Triangle(*vec1, *vec2);

    cs -> addShape(c);
    cs -> addShape(c2);
    cs -> addShape(t);

    ASSERT_EQ("CompoundShape\n{\nCircle (1.00)\nCircle (2.00)\nTriangle ([3.00,4.00] [3.00,0.00])\n}", cs -> info()); 

    delete cs, c, c2, vec1, vec2, t;
}

TEST(CaseCompoundShape, GetInfo_Empty_Exception) {
    CompoundShape* cs = new CompoundShape();

    ASSERT_ANY_THROW(cs -> info());

    delete cs;
}

TEST(CaseCompoundShape, DeleteShape_Empty_Exception) {
    CompoundShape* cs = new CompoundShape();
    Circle* c = new Circle(1.0);

    ASSERT_ANY_THROW(cs -> deleteShape(c));

    delete cs, c;
}

// TEST(CaseCompoundShape, DeleteShape_Invaild_Exception) {
//     CompoundShape* cs = new CompoundShape();
//     Circle* c = new Circle(1.0);
//     Circle* c2 = new Circle(2.0);

//     cs -> addShape(c);
    
//     ASSERT_ANY_THROW(cs -> deleteShape(c2));

//     delete cs, c, c2;
// }

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

TEST(CaseCompoundShape, AddShape) {
    CompoundShape* cs = new CompoundShape();
    Rectangle* rec = new Rectangle(1.0, 1.0);
    Rectangle* rec2 = new Rectangle(2.0, 2.0);
    Iterator* it;

    cs -> addShape(rec);
    
    ASSERT_NEAR(1.0, cs -> area(), 0.01);

    delete cs, rec, rec2, it;
}

TEST(CaseCompoundShape, AddShape2) {
    CompoundShape* cs = new CompoundShape();
    Rectangle* rec = new Rectangle(1.0, 1.0);
    Rectangle* rec2 = new Rectangle(2.0, 2.0);
    Iterator* it;

    cs -> addShape(rec);
    cs -> addShape(rec2);
    
    ASSERT_NEAR(5.0, cs -> area(), 0.01);

    delete cs, rec, rec2, it;
}


