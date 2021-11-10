#include "../src/text.h"
#include "../src/iterator/null_iterator.h"

TEST(CaseText, GetText) {
    Text t("text");
    ASSERT_EQ("text", t.getText());
}

TEST(CaseText, GetLevel) {
    Text t("text");
    ASSERT_EQ(0, t.getLevel());
}

TEST(CaseText, AddShouldThrow) {
    Text t("text");
    ASSERT_ANY_THROW(t.add(new Text("123")));
}

TEST(CaseText, CreateIterator_IsNullIterator) {
    Text t("text");
    ASSERT_EQ(typeid(NullIterator), typeid(*t.createIterator()));
}
