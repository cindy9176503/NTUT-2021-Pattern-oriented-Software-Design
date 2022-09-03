#include "../src/paragraph.h"

TEST(CaseParagraph, ParagraphShouldBeAArticle) {
    Article* p = new Paragraph (1, "title");
    ASSERT_EQ(typeid(p), typeid(Article*));
}

TEST(CaseParagraph, GetText) {
    Paragraph p(1, "title");
    ASSERT_EQ("title", p.getText());
}

TEST(CaseParagraph, GetTextWithComplexContent) {
    Paragraph p(1, "title");
    p.add(new ListItem("list1"));
    p.add(new ListItem("list2"));
    p.add(new Text("text"));
    Paragraph* p2 = new Paragraph(2, "title2");
    p2->add(new ListItem("list3"));
    p2->add(new ListItem("list4"));
    p2->add(new Text("sub text"));
    p.add(p2);
    ASSERT_EQ("title", p.getText());
}

TEST(CaseParagraph, GetLevel) {
    Paragraph p(1, "title");
    ASSERT_EQ(1, p.getLevel());
}

TEST(CaseParagraph, LevelIsZeroShouldThrow) {
    ASSERT_ANY_THROW(Paragraph p(0, "title"));
}

TEST(CaseParagraph, LevelIsNegativeShouldThrow) {
    ASSERT_ANY_THROW(Paragraph p(-1, "title"));
}

TEST(CaseParagraph, LevelOutOfRangeShouldThrow) {
    Paragraph p(1, "title");
    ASSERT_EQ("title", p.getText());
}

TEST(CaseParagraph, AddLowerLevelParagraphShouldThrow) {
    Paragraph p(2, "title");
    Paragraph* p2 = new Paragraph(1, "title2");
    ASSERT_ANY_THROW(p.add(p2));
}

TEST(CaseParagraph, AddEqualLevelParagraphShouldThrow) {
    Paragraph p(1, "title");
    Paragraph* p2 = new Paragraph(1, "title2");
    ASSERT_ANY_THROW(p.add(p2));
}