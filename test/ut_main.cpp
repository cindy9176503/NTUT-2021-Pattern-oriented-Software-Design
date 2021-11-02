#include <gtest/gtest.h>
#include "./ut_circle.h"
#include "./ut_iterator.h"
#include "./ut_compound_shape.h"

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

// circle大致完成。
// 正要處理iterator與shape互相include的問題，處理完後就可寫compoundshape。