#include "../src/paragraph.h"

TEST(CaseParagraph, GetLevel) {
    Paragraph p(1, "title");
    ASSERT_EQ(1, p.getLevel());
}

TEST(CaseParagraph, GetLevel2) {
    ASSERT_ANY_THROW(Paragraph p(0, "title"));
}

TEST(CaseParagraph, GetLevel3) {
    ASSERT_ANY_THROW(Paragraph p(7, "title"));
}

TEST(CaseParagraph, GetText) {
    Paragraph p(1, "title");
    ASSERT_EQ("# title\n", p.getText());
}

TEST(CaseParagraph, GetText2) {
    Paragraph p(1, "title");
    p.add(new ListItem("list1"));
    ASSERT_EQ("# title\n- list1", p.getText());
}

TEST(CaseParagraph, GetText3) {
    Paragraph p(1, "title");
    p.add(new ListItem("list1"));
    p.add(new ListItem("list2"));
    p.add(new Text("text"));
    ASSERT_EQ("# title\n- list1\n- list2\ntext", p.getText());
}

TEST(CaseParagraph, GetText4) {
    Paragraph p(1, "title");
    Paragraph* p2 = new Paragraph(2, "title2");
    p2->add(new ListItem("list3"));
    p2->add(new ListItem("list4"));
    p2->add(new Text("sub text"));
    p.add(p2);
    ASSERT_EQ("# title\n## title2\n- list3\n- list4\nsub text", p.getText());
}

TEST(CaseParagraph, GetText5) {
    Paragraph p(1, "title");
    p.add(new ListItem("list1"));
    p.add(new ListItem("list2"));
    p.add(new Text("text"));
    Paragraph* p2 = new Paragraph(2, "title2");
    p2->add(new ListItem("list3"));
    p2->add(new ListItem("list4"));
    p2->add(new Text("sub text"));
    p.add(p2);
    ASSERT_EQ("# title\n- list1\n- list2\ntext\n## title2\n- list3\n- list4\nsub text", p.getText());
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

