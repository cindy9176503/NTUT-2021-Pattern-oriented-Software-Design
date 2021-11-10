#pragma once

#include "../list_item.h"
#include "../text.h"
#include "../paragraph.h"
#include "article_visitor.h"

class HtmlVisitor : public ArticleVisitor {
public:
    void visitListItem(ListItem* li) override { _result = "<li>" + li->getText() + "</li>"; };

    void visitText(Text* t) override { _result = "<span>" + t->getText() + "</span>"; }

    void visitParagraph(Paragraph* p) override { _result = p->getText() + "\n"; }

    std::string getResult() const override { return _result; }

private:
    std::string _result;    
};