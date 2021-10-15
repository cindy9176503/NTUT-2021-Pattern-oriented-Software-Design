#include "../src/text.h"

TEST(CaseText, GetText) {
    Text t("text");
    ASSERT_EQ("text", t.getText());
}

TEST(CaseText, GetLevel) {
    Text t("text");
    ASSERT_EQ(0, t.getLevel());
}

TEST(CaseText, Add_ShouldException) {
    Text t("text");
    ASSERT_ANY_THROW(t.add(new Text("123")));
}