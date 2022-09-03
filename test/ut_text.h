#include "../src/text.h"
#include "../src/iterator/null_iterator.h"

TEST(CaseText, TextShouldBeAArticle) {
    Article* t = new Text("text");
    ASSERT_EQ(typeid(t), typeid(Article*));

    delete t;
}

TEST(CaseText, GetText) {
    Text t("text");
    ASSERT_EQ("text", t.getText());
}

TEST(CaseText, GetLevelShouldEq0) {
    ListItem l("list");
    ASSERT_EQ(0, l.getLevel());
}

TEST(CaseText, AddShouldThrow) {
    Text t("text");
    ASSERT_ANY_THROW(t.add(new Text("123")));
}

TEST(CaseText, CreateIteratorShouldBeNullIterator) {
    Text t("text");
    ASSERT_EQ(typeid(NullIterator), typeid(*t.createIterator()));
}