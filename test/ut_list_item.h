#include "../src/list_item.h"

TEST(CaseListItem, ListItem_GetText) {
    ListItem l("list");
    ASSERT_EQ("- list", l.getText());
}

TEST(CaseListItem, ListItem_GetLevel) {
    ListItem l("list");
    ASSERT_EQ(0, l.getLevel());
}

TEST(CaseListItem, ListItem_Add_Exception) {
    ListItem l("list");
    ASSERT_ANY_THROW(l.add(new ListItem("123")));
}