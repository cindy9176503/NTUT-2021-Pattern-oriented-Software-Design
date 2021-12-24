#include "../../src/shape.h"
#include "../../src/builder/shape_builder.h"

TEST(CaseShapeBuilder, MultiBuilderNeedEqual) {
    ShapeBuilder* builder = ShapeBuilder::getInstance();
    ShapeBuilder* builder1 = ShapeBuilder::getInstance();

    ASSERT_EQ(builder, builder1);

    delete builder, builder1;
}

TEST(CaseShapeBuilder, BuildCircle) {
    ShapeBuilder* builder = ShapeBuilder::getInstance();

    builder->buildCircle(1.0);
    Shape* result = builder->getShape();

    ASSERT_NEAR(1.0*1.0*M_PI, result->area(), 0.01);

    delete builder, result;
}

TEST(CaseShapeBuilder, BuildCircleException) {
    ShapeBuilder* builder = ShapeBuilder::getInstance();

    ASSERT_ANY_THROW(builder->buildCircle(-1));

    delete builder;
}
TEST(CaseShapeBuilder, BuildRectangle) {
    ShapeBuilder* builder = ShapeBuilder::getInstance();

    builder->buildRectangle(1.0, 2.0);
    Shape* result = builder->getShape();

    ASSERT_NEAR(2.0, result->area(), 0.01);

    delete builder, result;
}

TEST(CaseShapeBuilder, BuildTriangle) {
    ShapeBuilder* builder = ShapeBuilder::getInstance();

    builder->buildTriangle(3.0, 4.0, 3.0, 0.0);
    Shape* result = builder->getShape();

    ASSERT_NEAR(6.0, result->area(), 0.01);

    delete builder, result;
}

TEST(CaseShapeBuilder, BuildEmptyCompound) {
    ShapeBuilder* builder = ShapeBuilder::getInstance();

    builder->buildCompoundBegin();
    builder->buildCompoundEnd();
    Shape* result = builder->getShape();

    ASSERT_NEAR(0.0, result->area(), 0.01);

    delete builder, result;
}

TEST(CaseShapeBuilder, BuildSimpleCompound) {
    ShapeBuilder* builder = ShapeBuilder::getInstance();

    builder->buildCompoundBegin();
    builder->buildRectangle(1.0, 2.0);
    builder->buildRectangle(1.0, 2.0);
    builder->buildCompoundEnd();
    Shape* result = builder->getShape();

    ASSERT_NEAR(4, result->area(), 0.01);

    delete builder, result;
}

TEST(CaseShapeBuilder, BuildComplexCompound){
    ShapeBuilder* builder = ShapeBuilder::getInstance();

    builder->buildCompoundBegin();
    builder->buildCompoundBegin();
    builder->buildRectangle(1.0, 1.0);
    builder->buildRectangle(2.0, 2.0);
    builder->buildCompoundEnd();
    builder->buildRectangle(3.0, 3.0);
    builder->buildCompoundEnd();
    Shape* result = builder->getShape()->createIterator()->currentItem();

    ASSERT_NEAR(5.0, result->area(), 0.01);

    delete builder;
}
