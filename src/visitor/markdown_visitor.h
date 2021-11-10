#pragma once

#include <string>

#include "../text.h"
#include "../list_item.h"
#include "../paragraph.h"
#include "article_visitor.h"

class MarkdownVisitor : public ArticleVisitor {
public:
    void visitListItem(ListItem* li);

    void visitText(Text* t) override{ _result += t->getText(); }

    void visitParagraph(Paragraph* p) override{ _result += p->getText(); }

    std::string getResult() const override { return _result; }

private:
    std::string _result;
};