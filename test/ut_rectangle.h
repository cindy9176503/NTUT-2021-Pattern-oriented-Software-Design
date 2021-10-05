#include "../src/rectangle.h"

TEST(CaseRectangle, Area) {
    Rectangle r(5.0, 10.0);
    ASSERT_NEAR(50.0, r.area(), 0.01);
}

TEST(CaseRectangle, Perimeter) {
    Rectangle r(5.0, 10.0);
    ASSERT_NEAR(30.0, r.perimeter(), 0.01);
}

TEST(CaseRectangle, Info1) {
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

TEST(CaseRectangle, Not_positive_double1) {   
    ASSERT_ANY_THROW(Rectangle r(-5.0, 10.0));
}

TEST(CaseRectangle, Not_positive_double2) {   
    ASSERT_ANY_THROW(Rectangle r(5.0, -10.0));
}

TEST(CaseRectangle, Not_positive_double3) {   
    ASSERT_ANY_THROW(Rectangle r(-5.0, -10.0));
}