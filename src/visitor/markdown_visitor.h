#pragma once

#include "../iterator/iterator.h"

class MarkdownVisitor : public ArticleVisitor {
public:
    void visitListItem(ListItem* li) override { _result += "- " + li->getText() + "\n"; };

    void visitText(Text* t) override { _result += t->getText() + "\n"; }

    void visitParagraph(Paragraph* p) override {
        for(int i=0; i<p->getLevel(); i++) {
            _result += "#";
        }
        _result += " " + p->getText() + "\n";

        Iterator* it = p->createIterator();
        for (it->first(); !it->isDone(); it->next()) {
            it->currentItem()->accept(this);
        }

        delete it;
    }

    std::string getResult() const override {
        // std::cout << _result << std::endl;
        return _result; 
    }

private:
    std::string _result = "";
};