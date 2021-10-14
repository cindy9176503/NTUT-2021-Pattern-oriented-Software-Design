#include "../src/text.h"

TEST(CaseText, Text_GetText) {
    Text t("text");
    ASSERT_EQ("text", t.getText());
}

TEST(CaseText, Text_GetLevel) {
    Text t("text");
    ASSERT_EQ(0, t.getLevel());
}

TEST(CaseText, Text_Add_Exception) {
    Text t("text");
    ASSERT_ANY_THROW(t.add(new Text("123")));
}