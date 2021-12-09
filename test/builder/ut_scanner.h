#include "../../src/shape.h"
#include "../../src/builder/shape_builder.h"

TEST(CaseScanner, IsDone_True) {
    std::string input = "Circle (1.0)\n";
    Scanner scanner(input);
    scanner.nextDouble();
    scanner.next();

    ASSERT_TRUE(scanner.isDone());
}

TEST(CaseScanner, IsDone_False) {
    std::string input = "Circle (1.0)\n";
    Scanner scanner(input);
    scanner.nextDouble();

    ASSERT_FALSE(scanner.isDone());
}

TEST(CaseScanner, ScanCircle) {
    std::string input = "Circle (1.0)";
    Scanner scanner(input);

    ASSERT_TRUE("Circle" == scanner.next());
    ASSERT_TRUE(1.0 == scanner.nextDouble());
}

TEST(CaseScanner, ScanRectangle) {
    std::string input = "Rectangle (3.14, 4.00)";
    Scanner scanner(input);

    ASSERT_TRUE("Rectangle" == scanner.next());
    ASSERT_TRUE("(" == scanner.next());
    ASSERT_TRUE(3.14 == scanner.nextDouble());
    ASSERT_TRUE(4.00 == scanner.nextDouble());
}

TEST(CaseScanner, ScanTriangle) {
    std::string input = "Triangle ([3, 0] [0.000, 4.0])";
    Scanner scanner(input);

    ASSERT_TRUE("Triangle" == scanner.next());
    ASSERT_TRUE("(" == scanner.next());
    ASSERT_TRUE(3 == scanner.nextDouble());
    ASSERT_TRUE(0 == scanner.nextDouble());
    ASSERT_TRUE(0.000 == scanner.nextDouble());
    ASSERT_TRUE(4.0 == scanner.nextDouble());
}

TEST(CaseScanner, ScanEmptyCompound) {
    std::string input = "CompoundShape {}";
    Scanner scanner(input);
    scanner.next();
    scanner.next();
    scanner.next();

    ASSERT_TRUE(scanner.isDone());
}

TEST(CaseScanner, ScanSimpleCompound) {
    std::string input = "CompoundShape{Circle(1.0)\nCircle(1.0)}\n";
    Scanner scanner(input);
    scanner.nextDouble();
    scanner.nextDouble();
    scanner.next();
    scanner.next();

    ASSERT_TRUE(scanner.isDone());
}

TEST(CaseScanner, ScanComplexCompound){
    std::string input = "CompoundShape {\nCircle (1.0)\n  CompoundShape {\nCircle (1.0)\n}\nCircle (1.0)\n}\n";
    Scanner scanner(input);
    scanner.nextDouble();
    scanner.nextDouble();
    scanner.nextDouble();
    scanner.next();
    scanner.next();

    ASSERT_TRUE(scanner.isDone());
}

TEST(CaseScanner, ScanIllegalWordShouldIgnore) {
    std::string input = "I Circle eee ,tt{t3.14159a";
    Scanner scanner(input);

    ASSERT_TRUE("Circle" == scanner.next());
    ASSERT_TRUE("," == scanner.next());
    ASSERT_TRUE(3.14159 == scanner.nextDouble());
}

TEST(CaseScanner, NextShouldThrowExceptionWhenIsDone) {
    std::string input = "CompoundShape {}\n";
    Scanner scanner(input);
    scanner.next();
    scanner.next();
    scanner.next();

    ASSERT_ANY_THROW(scanner.next());
}

TEST(CaseScanner, NextDoubleShouldThrowExceptionWhenIsDone) {
    std::string input = "CompoundShape {}\n";
    Scanner scanner(input);
    scanner.next();
    scanner.next();
    scanner.next();

    ASSERT_ANY_THROW(scanner.nextDouble());
}