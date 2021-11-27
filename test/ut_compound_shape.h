#include "../src/compound_shape.h"
#include "../src/circle.h"
#include "../src/rectangle.h"
#include "../src/triangle.h"
#include "../src/two_dimensional_vector.h"
#include "../src/iterator/iterator.h"
#include "../src/visitor/shape_info_visitor.h"

TEST(CaseCompoundShape, Constructor_NoException) {
    ASSERT_NO_THROW(new CompoundShape());
}

TEST(CaseCompoundShape, Area) {
    CompoundShape* cs = new CompoundShape();
    Rectangle* rec = new Rectangle(1.0, 1.0);
    Rectangle* rec2 = new Rectangle(2.0, 2.0);

    cs -> addShape(rec);
    cs -> addShape(rec2);
    
    ASSERT_NEAR(5.0, cs -> area(), 0.01);

    delete cs, rec, rec2;
}

TEST(CaseCompoundShape, Perimeter) {
    CompoundShape* cs = new CompoundShape();
    Rectangle* rec = new Rectangle(1.0, 1.0);
    Rectangle* rec2 = new Rectangle(2.0, 2.0);

    cs -> addShape(rec);
    cs -> addShape(rec2);
    
    ASSERT_NEAR(12.0, cs -> perimeter(), 0.01);

    delete cs, rec, rec2;
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

TEST(CaseCompoundShape, Accept) {
    CompoundShape* cs = new CompoundShape();
    ShapeInfoVisitor* visitor = new ShapeInfoVisitor();

    ASSERT_NO_THROW(cs->accept(visitor));
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

    cs -> addShape(rec);
    cs -> addShape(rec2);
    
    ASSERT_NEAR(5.0, cs -> area(), 0.01);

    delete cs, rec, rec2;
}

TEST(CaseCompoundShape, DelectShape) {
    CompoundShape* cs = new CompoundShape();
    Rectangle* rec = new Rectangle(1.0, 1.0);
    Rectangle* rec2 = new Rectangle(2.0, 2.0);

    cs -> addShape(rec);
    cs -> addShape(rec2);
    cs -> deleteShape(rec2);
    
    ASSERT_NEAR(1.0, cs -> area(), 0.01);

    delete cs, rec, rec2;
}

TEST(CaseCompoundShape, DeleteInnerShape) {
    CompoundShape* cs = new CompoundShape();
    CompoundShape* cs2 = new CompoundShape();
    Rectangle* rec = new Rectangle(1.0, 1.0);
    Rectangle* rec2 = new Rectangle(2.0, 2.0);

    cs2 -> addShape(rec);
    cs2 -> addShape(rec2);
    cs -> addShape(cs2);
    cs -> deleteShape(rec2);

    ASSERT_NEAR(1.0, cs -> area(), 0.01);

    delete cs, cs2, rec, rec2;
}

TEST(CaseCompoundShape, DeleteShape_DeleteALL_IsDoneTRUE) {
    CompoundShape* cs = new CompoundShape();
    Circle* c = new Circle(1.0);
    Iterator* it;

    cs -> addShape(c);
    cs -> deleteShape(c);

    it = cs -> createIterator();
    ASSERT_TRUE(it -> isDone());

    delete cs, c, it;
}

TEST(CaseCompoundShape, Empty_Exception) {
    CompoundShape* cs = new CompoundShape();

    ASSERT_ANY_THROW(cs -> area());

    delete cs;
}

TEST(CaseCompoundShape, CompoundShapeShouldBeAShape) { 
    Shape* cs = new CompoundShape();

    ASSERT_TRUE(typeid(cs) == typeid(Shape*));

    delete cs;
}