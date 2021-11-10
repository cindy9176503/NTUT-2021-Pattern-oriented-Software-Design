#include "../../src/text.h"
#include "../../src/list_item.h"
#include "../../src/paragraph.h"
#include "../../src/visitor/markdown_visitor.h"

TEST(CaseMarkdownVisitor, TextInfo) {
    Text t("text");

    MarkdownVisitor* visitor = new MarkdownVisitor();
    t.accept(visitor);
    std::string result = visitor->getResult();

    ASSERT_TRUE("text" == result);

    delete visitor;
}

TEST(CaseMarkdownVisitor, ListItemInfo) {
    ListItem l("list");

    MarkdownVisitor* visitor = new MarkdownVisitor();
    l.accept(visitor);
    std::string result = visitor->getResult();

    ASSERT_TRUE("- list" == result);

    delete visitor;
}

TEST(CaseMarkdownVisitor, ParagraphInfo) {
    Paragraph p(1, "title");
    p.add(new ListItem("list1"));
    p.add(new ListItem("list2"));
    p.add(new Text("text"));

    MarkdownVisitor* visitor = new MarkdownVisitor();
    p.accept(visitor);
    std::string result = visitor->getResult();

    ASSERT_EQ("# title\n- list1\n- list2\ntext", result);

    delete visitor;
}
