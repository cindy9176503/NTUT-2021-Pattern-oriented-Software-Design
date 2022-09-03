#include "../../src/text.h"
#include "../../src/list_item.h"
#include "../../src/paragraph.h"
#include "../../src/visitor/markdown_visitor.h"

TEST(CaseMarkdownVisitor, VisitText) {
    Text t("text");

    ArticleVisitor* visitor = new MarkdownVisitor();
    t.accept(visitor);
    std::string result = visitor->getResult();

    ASSERT_TRUE("text\n" == result);

    delete visitor;
}

TEST(CaseMarkdownVisitor, VisitListItem) {
    ListItem li("list");

    ArticleVisitor* visitor = new MarkdownVisitor();
    li.accept(visitor);
    std::string result = visitor->getResult();

    ASSERT_TRUE("- list\n" == result);

    delete visitor;
}

TEST(CaseMarkdownVisitor, VisitSimpleParagraph) {
    Paragraph p(1, "title");
    p.add(new ListItem("list1"));
    p.add(new ListItem("list2"));
    p.add(new Text("text"));

    ArticleVisitor* visitor = new MarkdownVisitor();
    p.accept(visitor);
    std::string result = visitor->getResult();

    ASSERT_EQ("# title\n- list1\n- list2\ntext\n", result);

    delete visitor;
}

TEST(CaseMarkdownVisitor, VisitComplexParagraph) {
    Paragraph p(1, "title");
    p.add(new ListItem("list1"));
    p.add(new ListItem("list2"));
    p.add(new Text("text"));
    Paragraph* p2 = new Paragraph(2, "title2");
    p2->add(new ListItem("list3"));
    p2->add(new ListItem("list4"));
    p2->add(new Text("sub text"));
    p.add(p2);

    ArticleVisitor* visitor = new MarkdownVisitor();
    p.accept(visitor);
    std::string result = visitor->getResult();

    ASSERT_EQ("# title\n- list1\n- list2\ntext\n## title2\n- list3\n- list4\nsub text\n", result);

    delete visitor;
}