#pragma once

#include <string>

class Text; 
class ListItem; 
class Paragraph;

class ArticleVisitor {
public:
    virtual void visitListItem(ListItem* li) = 0;
    virtual void visitText(Text* t) = 0;
    virtual void visitParagraph(Paragraph* p) = 0;
    virtual std::string getResult() const = 0;

protected:
    ArticleVisitor() {}
};