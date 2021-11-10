#include "../../src/text.h"
#include "../../src/list_item.h"
#include "../../src/paragraph.h"
#include "../../src/visitor/html_visitor.h"

TEST(CaseHtmlVisitor, TextInfo) {
    Text t("text");

    HtmlVisitor* visitor = new HtmlVisitor();
    t.accept(visitor);
    std::string result = visitor->getResult();

    ASSERT_TRUE("<span>text</span>" == result);

    delete visitor;
}