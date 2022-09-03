#include "../../src/text.h"
#include "../../src/list_item.h"
#include "../../src/paragraph.h"
#include "../../src/visitor/html_visitor.h"

TEST(CaseHtmlVisitor, VisitText) {
    Text t("text");

    ArticleVisitor* visitor = new HtmlVisitor();
    t.accept(visitor);
    std::string result = visitor->getResult();

    ASSERT_TRUE("<span>text</span>" == result);

    delete visitor;
}

TEST(CaseHtmlVisitor, VisitListItem) {
    ListItem li("list");

    ArticleVisitor* visitor = new HtmlVisitor();
    li.accept(visitor);
    std::string result = visitor->getResult();

    ASSERT_TRUE("<li>list</li>" == result);

    delete visitor;
}

TEST(CaseHtmlVisitor, VisitSimpleParagraph) {
    Paragraph p(1, "title");
    p.add(new ListItem("list1"));
    p.add(new ListItem("list2"));
    p.add(new Text("text"));

    ArticleVisitor* visitor = new HtmlVisitor();
    p.accept(visitor);
    std::string result = visitor->getResult();

    ASSERT_EQ("<div><h1>title</h1><li>list1</li><li>list2</li><span>text</span></div>", result);

    delete visitor;
}

TEST(CaseHtmlVisitor, VisitComplexParagraph) {
    Paragraph p(1, "title");
    p.add(new ListItem("list1"));
    p.add(new ListItem("list2"));
    p.add(new Text("text"));
    Paragraph* p2 = new Paragraph(2, "title2");
    p2->add(new ListItem("list3"));
    p2->add(new ListItem("list4"));
    p2->add(new Text("sub text"));
    p.add(p2);

    ArticleVisitor* visitor = new HtmlVisitor();
    p.accept(visitor);
    std::string result = visitor->getResult();

    ASSERT_EQ("<div><h1>title</h1><li>list1</li><li>list2</li><span>text</span><div><h2>title2</h2><li>list3</li><li>list4</li><span>sub text</span></div></div>", result);

    delete visitor;
}