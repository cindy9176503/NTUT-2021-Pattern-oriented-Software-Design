#include "../../src/text.h"
#include "../../src/visitor/markdown_visitor.h"

TEST(CaseMarkdownVisitor, TextInfo) {
    Text t("text");

    MarkdownVisitor* visitor = new MarkdownVisitor();
    t.accept(visitor);
    std::string result = visitor->getResult();

    std::cout << result << std::endl;
    ASSERT_TRUE("text/n" == result);

    // delete visitor;
}
