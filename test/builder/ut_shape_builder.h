#include "../../src/shape.h"
#include "../../src/builder/shape_builder.h"

TEST(CaseBuilder, BuildCircle) {
    ShapeBuilder* builder = new ShapeBuilder();

    builder->buildCircle(1.0);
    Shape* result = builder->getShape();

    ASSERT_NEAR(1*1*M_PI, result->area(), 0.01);

    delete builder, result;
}

TEST(CaseBuilder, BuildRectangle) {
    ShapeBuilder* builder = new ShapeBuilder();

    builder->buildRectangle(1.0, 2.0);
    Shape* result = builder->getShape();

    ASSERT_NEAR(2.0, result->area(), 0.01);

    delete builder, result;
}

TEST(CaseBuilder, BuildTriangle) {
    ShapeBuilder* builder = new ShapeBuilder();

    builder->buildTriangle(3.0, 4.0, 3.0, 0.0);
    Shape* result = builder->getShape();

    ASSERT_NEAR(6.0, result->area(), 0.01);

    delete builder, result;
}

TEST(CaseBuilder, BuildEmptyCompound) {
    ShapeBuilder* builder = new ShapeBuilder();

    builder->buildCompoundBegin();
    builder->buildCompoundEnd();
    Shape* result = builder->getShape();

    ASSERT_NEAR(0.0, result->area(), 0.01);

    delete builder, result;
}

TEST(CaseBuilder, BuildSimpleCompound) {
    ShapeBuilder* builder = new ShapeBuilder();

    builder->buildCompoundBegin();
    builder->buildRectangle(1.0, 2.0);
    builder->buildRectangle(1.0, 2.0);
    builder->buildCompoundEnd();
    Shape* result = builder->getShape();

    ASSERT_NEAR(4, result->area(), 0.01);

    delete builder, result;
}

TEST(CaseBuilder, BuildComplexCompound){
    ShapeBuilder* builder = new ShapeBuilder();

    builder->buildCompoundBegin();
    builder->buildCompoundBegin();
    builder->buildRectangle(1.0, 1.0);
    builder->buildRectangle(2.0, 2.0);
    builder->buildCompoundEnd();
    builder->buildRectangle(3.0, 3.0);
    builder->buildCompoundEnd();
    Shape* result = builder->getShape();

    ASSERT_NEAR(5.0, result->createIterator()->currentItem()->area(), 0.01);

    delete builder, result;
}