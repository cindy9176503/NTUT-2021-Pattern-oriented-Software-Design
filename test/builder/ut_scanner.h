#include "../../src/shape.h"
#include "../../src/builder/shape_builder.h"

TEST(CaseScanner, BuildCircle) {
    std::string input = "I Circle eee ,tt{t3.14159a";
    Scanner scanner(input);
    std::string first = scanner.next();
    std::string second = scanner.next();
    double third = scanner.nextDouble(); 

    ASSERT_TRUE(first == "Circle");
    ASSERT_TRUE(second == ",");
    ASSERT_TRUE(third == 3.14159);
}

// TEST(CaseScanner, BuildRectangle) {
//     std::string input = "Rectangle (3.14, 4.00)";
//     Scanner scanner(input);
//     std::string first = scanner.next();
//     std::string second = scanner.next();
//     double third = scanner.nextDouble(); 

//     ASSERT_TRUE(first == "Rectangle");
//     ASSERT_TRUE(second == "(");
//     ASSERT_TRUE(third == 3.14);
// }

// TEST(CaseScanner, BuildTriangle) {
//     std::string input = "Triangle ([3, 0] [0.000, 4.0])";
//     Scanner scanner(input);
//     std::string first = scanner.next();
//     std::string second = scanner.next();
//     double third = scanner.nextDouble(); 

//     ASSERT_TRUE(first == "Triangle");
//     ASSERT_TRUE(second == "(");
//     ASSERT_TRUE(third == 3);
// }

// TEST(CaseScanner, BuildEmptyCompound) {
//     std::string input = "CompoundShape {}";
//     Scanner scanner(input);
//     std::string first = scanner.next();
//     std::string second = scanner.next();
//     std::string third = scanner.next();

//     ASSERT_TRUE(first == "CompoundShape");
//     ASSERT_TRUE(second == "{");
//     ASSERT_TRUE(third == "}");
// }

// TEST(CaseScanner, BuildSimpleCompound) {
//     std::string input = "CompoundShape {\n  Circle (1.0)\n  Rectangle (3.14 4.00)\n  Triangle ([3,0] [0,4])\n}\n";
//     Scanner scanner(input);
//     std::string first = scanner.next();
//     std::string second = scanner.next();
//     double third = scanner.nextDouble();

//     ASSERT_TRUE(first == "CompoundShape");
//     ASSERT_TRUE(second == "{");
//     ASSERT_TRUE(third == 1.0);
// }

// TEST(CaseScanner, BuildComplexCompound){
//     std::string input = "CompoundShape {\n  Circle (1.0)\n  Triangle ([3,0] [0,4])\n  CompoundShape {\n    Circle (1.0)\n    Rectangle (3.14 4.00)\n    Triangle ([3,0] [0,4])\n  }\n  Rectangle (3.14 4.00)\n}\n";
//     Scanner scanner(input);
//     std::string first = scanner.next();
//     std::string second = scanner.next();
//     double third = scanner.nextDouble();
//     double fourth = scanner.nextDouble();

//     ASSERT_TRUE(first == "CompoundShape");
//     ASSERT_TRUE(second == "{");
//     ASSERT_TRUE(third == 1.0);
//     ASSERT_TRUE(fourth == 3);
// }