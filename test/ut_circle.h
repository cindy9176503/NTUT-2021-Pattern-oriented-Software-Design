#include "../src/circle.h"

TEST(CaseCircle, Area) {
    Circle c(10.0);
    ASSERT_NEAR(314.159, c.area(), 0.01);
}

TEST(CaseCircle, Area2) {
    Circle c(5.6123);
    ASSERT_NEAR(98.954, c.area(), 0.01);
}

TEST(CaseCircle, Perimeter) {
    Circle c(10.0);
    ASSERT_NEAR(62.832, c.perimeter(), 0.01);
}

TEST(CaseCircle, Perimeter2) {
    Circle c(25);
    ASSERT_NEAR(157.08, c.perimeter(), 0.01);
}

TEST(CaseCircle, Info) {
    Circle c(17.5678);
    ASSERT_TRUE("Circle (17.57)" == c.info());
}

TEST(CaseCircle, Info2) {
    Circle c(17);
    ASSERT_TRUE("Circle (17.00)" == c.info());
}

TEST(CaseCircle, Info3) {
    Circle c(1.1);
    ASSERT_TRUE("Circle (1.10)" == c.info());
}

TEST(CaseCircle, Not_positive_double) {   
    ASSERT_ANY_THROW(Circle c(-5));
}

TEST(CaseCircle, Not_positive_double2) {   
    ASSERT_ANY_THROW(Circle c(0));
}