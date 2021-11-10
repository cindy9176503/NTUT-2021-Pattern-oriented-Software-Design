#pragma once

#include "../text.h"
#include "../list_item.h"
#include "../paragraph.h"

class ArticleVisitor {
public:
    // virtual void visitListItem(ListItem* li) = 0;
    virtual void visitText(Text* t) = 0;
    // virtual void visitParagraph(Paragraph* p) = 0;
    // virtual std::string getResult() const = 0;

protected:
    ArticleVisitor() {}
};