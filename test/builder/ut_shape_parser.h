#include "../../src/shape.h"
#include "../../src/builder/shape_parser.h"

TEST(CaseParser, BuildCircle){
    std::string input = "./test/data/circle.txt";
    ShapeParser* parser = new ShapeParser(input);
    Shape* result = parser->getShape();

    ASSERT_NEAR(1.0*1.0*M_PI, result->area(), 0.01);

    delete parser, result;
}

TEST(CaseParser, BuildRectangle){
    std::string input = "./test/data/rectangle.txt";
    ShapeParser* parser = new ShapeParser(input);
    Shape* result = parser->getShape();

    ASSERT_NEAR(3.14*4.00, result->area(), 0.01);

    delete parser, result;
}

TEST(CaseParser, BuildTriangle){
    std::string input = "./test/data/triangle.txt";
    ShapeParser* parser = new ShapeParser(input);
    Shape* result = parser->getShape();

    ASSERT_NEAR(6.0, result->area(), 0.01);

    delete parser, result;
}

TEST(CaseParser, BuildEmptyCompound){
    std::string input = "./test/data/empty_compound.txt";

    ShapeParser* parser = new ShapeParser(input);
    Shape* result = parser->getShape();

    ASSERT_NEAR(0.0, result->area(), 0.01);

    delete parser, result;
}

TEST(CaseParser, BuildSimpleCompound){
    std::string input = "./test/data/simple_compound.txt";
    ShapeParser* parser = new ShapeParser(input);
    Shape* result = parser->getShape();

    ASSERT_NEAR(1.0*M_PI + 3.14*4.00 + 6.0, result->area(), 0.01);

    delete parser, result;
}

TEST(CaseParser, BuildComplexCompound){
    std::string input = "./test/data/complex_compound.txt";
    ShapeParser* parser = new ShapeParser(input);
    Shape* result = parser->getShape();

    ASSERT_NEAR((1.0*M_PI + 3.14*4.00 + 6.0)*2, result->area(), 0.01);

    delete parser, result;
}