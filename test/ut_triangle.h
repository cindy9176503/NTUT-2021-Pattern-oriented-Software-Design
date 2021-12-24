#include "../src/triangle.h"
#include "../src/iterator/null_iterator.h"

TEST(CaseTriangle, Constructor_NoException) {
    TwoDimensionalVector vec1(3.0, 4.0);
    TwoDimensionalVector vec2(3.0, 0.0);
    ASSERT_NO_THROW(Triangle t(vec1, vec2));
}

TEST(CaseTriangle, Area) {    
    TwoDimensionalVector vec1(3.0, 4.0);
    TwoDimensionalVector vec2(3.0, 0.0);
    Triangle t(vec1, vec2);
    
    ASSERT_NEAR(6.0, t.area(), 0.01);
}

TEST(CaseTriangle, Perimeter) {    
    TwoDimensionalVector vec1(3.0, 4.0);
    TwoDimensionalVector vec2(3.0, 0.0);
    Triangle t(vec1, vec2);

    ASSERT_NEAR(12.0, t.perimeter(), 0.01);
}

TEST(CaseTriangle, Perimeter2) {    
    TwoDimensionalVector vec1(3.0, 4.0);
    TwoDimensionalVector vec2(3.0, 0.0);
    Triangle t(vec1, vec2);

    ASSERT_NEAR(12.0, t.perimeter(), 0.01);
}

TEST(CaseTriangle, Info) {    
    TwoDimensionalVector vec1(3.0, 4.0);
    TwoDimensionalVector vec2(3.0, 0.0);
    Triangle t(vec1, vec2);

    ASSERT_TRUE("Triangle ([3.00,4.00] [3.00,0.00])" == t.info());
}

TEST(CaseTriangle, Info1) {    
    TwoDimensionalVector vec1(3, 12.433);
    TwoDimensionalVector vec2(17.56789, -4);
    Triangle t(vec1, vec2);

    ASSERT_TRUE("Triangle ([3.00,12.43] [17.57,-4.00])" == t.info());
}

TEST(CaseTriangle, Parallel_Exception) {    
    TwoDimensionalVector vec1(3.0, 4.0);
    TwoDimensionalVector vec2(-3.0, -4.0);

    ASSERT_ANY_THROW(Triangle t(vec1, vec2));
}

TEST(CaseTriangle, Parallel_Exception2) {    
    TwoDimensionalVector vec1(1.0, 1.0);
    TwoDimensionalVector vec2(9.0, 9.0);

    ASSERT_ANY_THROW(Triangle t(vec1, vec2));
}

TEST(CaseTriangle, IsNullIterator) {
    TwoDimensionalVector vec1(3.0, 4.0);
    TwoDimensionalVector vec2(3.0, 0.0); 
    Triangle t(vec1, vec2);
    Iterator *it = t.createIterator();

    ASSERT_EQ(typeid(NullIterator) ,typeid(*it));

    delete it;
}

TEST(CaseTriangle, NullIterator_isDoneTrue) {
    TwoDimensionalVector vec1(3.0, 4.0);
    TwoDimensionalVector vec2(3.0, 0.0); 
    Triangle t(vec1, vec2);
    Iterator *it = t.createIterator();

    ASSERT_TRUE(it->isDone());

    delete it;
}

TEST(CaseTriangle, NullIterator_First_Exception) {
    TwoDimensionalVector vec1(3.0, 4.0);
    TwoDimensionalVector vec2(3.0, 0.0);  
    Triangle t(vec1, vec2);
    Iterator *it = t.createIterator();

    ASSERT_ANY_THROW(it->first());

    delete it;
}

TEST(CaseTriangle, NullIterator_Next_Exception) {
    TwoDimensionalVector vec1(3.0, 4.0);
    TwoDimensionalVector vec2(3.0, 0.0);   
    Triangle t(vec1, vec2);
    Iterator *it = t.createIterator();

    ASSERT_ANY_THROW(it->next());

    delete it;
}

TEST(CaseTriangle, NullIterator_Current_Exception) {
    TwoDimensionalVector vec1(3.0, 4.0);
    TwoDimensionalVector vec2(3.0, 0.0);   
    Triangle t(vec1, vec2);
    Iterator *it = t.createIterator();
    Shape* result;

    ASSERT_ANY_THROW(result = it->currentItem());

    delete it, result;
}

TEST(CaseTriangle, AddShape_Exception) { 
    TwoDimensionalVector vec1(3.0, 4.0);
    TwoDimensionalVector vec2(3.0, 0.0);  
    Triangle t(vec1, vec2);
    Triangle* t2 = new Triangle(vec1, vec2);

    ASSERT_ANY_THROW(t.addShape(t2));

    delete t2;
}

TEST(CaseTriangle, DeleteShape_Exception) { 
    TwoDimensionalVector vec1(3.0, 4.0);
    TwoDimensionalVector vec2(3.0, 0.0);  
    Triangle t(vec1, vec2);
    Triangle* t2 = new Triangle(vec1, vec2);

    ASSERT_ANY_THROW(t.deleteShape(t2));

    delete t2;
}

TEST(CaseTriangle, TriangleShouldBeAShape) { 
    TwoDimensionalVector vec1(3.0, 4.0);
    TwoDimensionalVector vec2(3.0, 0.0);  
    Shape* t = new Triangle(vec1, vec2);

    ASSERT_TRUE(typeid(t) == typeid(Shape*));

    delete t;
}

TEST(CaseTriangle, Accept) {
    TwoDimensionalVector vec1(3.0, 4.0);
    TwoDimensionalVector vec2(3.0, 0.0);  
    Shape* t = new Triangle(vec1, vec2);
    ShapeInfoVisitor* visitor = new ShapeInfoVisitor();

    ASSERT_NO_THROW(t->accept(visitor));

    delete t, visitor;
}