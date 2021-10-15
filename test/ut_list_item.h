#include "../src/list_item.h"

TEST(CaseListItem, GetText) {
    ListItem l("list");
    ASSERT_EQ("- list", l.getText());
}

TEST(CaseListItem, GetLevel) {
    ListItem l("list");
    ASSERT_EQ(0, l.getLevel());
}

TEST(CaseListItem, AddShouldThrow) {
    ListItem l("list");
    ASSERT_ANY_THROW(l.add(new ListItem("123")));
}