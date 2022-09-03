#include "../src/list_item.h"

TEST(CaseListItem, ListItemShouldBeAArticle) {
    Article* li = new ListItem("list");
    ASSERT_EQ(typeid(li), typeid(Article*));

    delete li;
}

TEST(CaseListItem, GetText) {
    ListItem l("list");
    ASSERT_EQ("list", l.getText());
}

TEST(CaseListItem, GetLevelShouldEq0) {
    ListItem l("list");
    ASSERT_EQ(0, l.getLevel());
}

TEST(CaseListItem, AddShouldThrow) {
    ListItem l("list");
    ASSERT_ANY_THROW(l.add(new ListItem("123")));
}

TEST(CaseListItem, CreateIteratorIsNullIterator) {
    ListItem l("list");
    ASSERT_EQ(typeid(NullIterator), typeid(*l.createIterator()));
}