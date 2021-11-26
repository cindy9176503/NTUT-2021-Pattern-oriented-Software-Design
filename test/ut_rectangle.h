#include "../src/rectangle.h"
#include "../src/iterator/null_iterator.h"

TEST(CaseRectangle, Area) {
    Rectangle r(5.0, 10.0);
    ASSERT_NEAR(50.0, r.area(), 0.01);
}

TEST(CaseRectangle, Area2) {
    Rectangle r(10.0, 10.0);
    ASSERT_NEAR(100.0, r.area(), 0.01);
}

TEST(CaseRectangle, Perimeter) {
    Rectangle r(5.0, 10.0);
    ASSERT_NEAR(30.0, r.perimeter(), 0.01);
}

TEST(CaseRectangle, Perimeter2) {
    Rectangle r(50.3, 120.4);
    ASSERT_NEAR(341.4, r.perimeter(), 0.01);
}

TEST(CaseRectangle, Info) {
    Rectangle r(5.0, 10.0);
    ASSERT_TRUE("Rectangle (5.00 10.00)" == r.info());
}

TEST(CaseRectangle, Info2) {
    Rectangle r(5.123, 10.789);
    ASSERT_TRUE("Rectangle (5.12 10.79)" == r.info());
}

TEST(CaseRectangle, Info3) {
    Rectangle r(3.14, 4);
    ASSERT_TRUE("Rectangle (3.14 4.00)" == r.info());
}

TEST(CaseRectangle, Not_positive_double) {   
    ASSERT_ANY_THROW(Rectangle r(-5.0, 10.0));
}

TEST(CaseRectangle, Not_positive_double2) {   
    ASSERT_ANY_THROW(Rectangle r(5.0, -10.0));
}

TEST(CaseRectangle, Not_positive_double3) {   
    ASSERT_ANY_THROW(Rectangle r(-5.0, -10.0));
}

TEST(CaseRectangle, IsNullIterator) {
    Rectangle r(1.0, 2.0);
    ASSERT_EQ(typeid(NullIterator), typeid(*r.createIterator()));
}

TEST(CaseRectangle, NullIterator_isDoneTrue) {
    Rectangle r(1.0, 2.0);
    ASSERT_TRUE(r.createIterator()->isDone());
}

TEST(CaseRectangle, NullIterator_First_Exception) {
    Rectangle r(1.0, 2.0);
    ASSERT_ANY_THROW(r.createIterator()->first());
}

TEST(CaseRectangle, NullIterator_Next_Exception) {
    Rectangle r(1.0, 2.0);
    ASSERT_ANY_THROW(r.createIterator()->next());
}

TEST(CaseRectangle, NullIterator_Current_Exception) {
    Rectangle r(1.0, 2.0);
    ASSERT_ANY_THROW(r.createIterator()->next());
}

TEST(CaseRectangle, AddShape_Exception) { 
    Rectangle r(1.0, 2.0);
    Shape* r2 = new Rectangle(1.0, 2.0);
    ASSERT_ANY_THROW(r.addShape(r2));

    delete r2;
}

TEST(CaseRectangle, DeleteShape_Exception) { 
    Rectangle r(1.0, 2.0);
    Shape* r2 = new Rectangle(1.0, 2.0);
    ASSERT_ANY_THROW(r.deleteShape(r2));

    delete r2;
}