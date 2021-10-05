#include "../src/two_dimensional_vector.h"

TEST(CaseTwoDimensionalVector, x){
    TwoDimensionalVector vec(1.00123, 2.0);
    ASSERT_NEAR(1.000, vec.x(), 0.01);
}

TEST(CaseTwoDimensionalVector, y){
    TwoDimensionalVector vec(1.0, 2.0198);
    ASSERT_NEAR(2.020, vec.y(), 0.01);
}

TEST(CaseTwoDimensionalVector, length){
    TwoDimensionalVector vec(1.0, 2.0);
    ASSERT_NEAR(2.236, vec.length(), 0.01);
}

TEST(CaseTwoDimensionalVector, Dot) {
    TwoDimensionalVector vec1(3.0, 4.0);
    TwoDimensionalVector vec2(3.0, 0.0);
    ASSERT_NEAR(9.0, vec1.dot(vec2), 0.01);
}

TEST(CaseTwoDimensionalVector, Cross) {
    TwoDimensionalVector vec1(3.0, 4.0);
    TwoDimensionalVector vec2(3.0, 0.0);
    ASSERT_NEAR(-12.0, vec1.cross(vec2), 0.01);
}

TEST(CaseTwoDimensionalVector, Subtract) {
    TwoDimensionalVector vec(2.0, 3.0);
    TwoDimensionalVector vec2(3.0, 1.0);
    ASSERT_NEAR(-1.0, vec.subtract(vec2).x(), 0.01);
    ASSERT_NEAR(2.0, vec.subtract(vec2).y(), 0.01);
}

TEST(CaseTwoDimensionalVector, Subtract2) {
    TwoDimensionalVector vec(2.5912, 3.9978);
    TwoDimensionalVector vec2(2.0, 3.0);
    ASSERT_NEAR(0.591, vec.subtract(vec2).x(), 0.01);
    ASSERT_NEAR(0.998, vec.subtract(vec2).y(), 0.01);
}

TEST(CaseTwoDimensionalVector, Info) {
    TwoDimensionalVector vec(3, 12.433);
    ASSERT_TRUE("[3.00,12.43]" == vec.info());
}

TEST(CaseTwoDimensionalVector, Info2) {
    TwoDimensionalVector vec(3.198, 12.433);
    ASSERT_STREQ("[3.20,12.43]", vec.info().c_str());
}