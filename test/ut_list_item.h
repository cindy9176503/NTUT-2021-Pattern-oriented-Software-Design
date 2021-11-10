#include "../src/list_item.h"

TEST(CaseListItem, GetText) {
    ListItem l("list");
    ASSERT_EQ("- list", l.getText());
}

TEST(CaseListItem, GetText2) {
    ListItem l("hello!");
    ASSERT_EQ("- hello!", l.getText());
}

TEST(CaseListItem, GetLevel) {
    ListItem l("list");
    ASSERT_EQ(0, l.getLevel());
}

TEST(CaseListItem, AddShouldThrow) {
    ListItem l("list");
    ASSERT_ANY_THROW(l.add(new ListItem("123")));
}

TEST(CaseListItem, CreateIterator_IsNullIterator) {
    ListItem l("list");
    ASSERT_EQ(typeid(NullIterator), typeid(*l.createIterator()));
}
