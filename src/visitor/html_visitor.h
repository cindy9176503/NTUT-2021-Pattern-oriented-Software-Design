#pragma once

#include <sstream>
#include <iostream>

#include "../list_item.h"
#include "../text.h"
#include "../paragraph.h"
#include "article_visitor.h"

class HtmlVisitor : public ArticleVisitor {
public:
    void visitListItem(ListItem* li) override { 
        _result += "<li>" + li->getText() + "</li>"; 
    };

    void visitText(Text* t) override {
        _result += "<span>" + t->getText() + "</span>"; 
    }

    void visitParagraph(Paragraph* p) override {
        std::stringstream stream1;
        std::string tag;

        _result += "<div>";
        stream1 << p->getLevel();
        tag = stream1.str();

        _result = _result + "<h" + tag + ">" + p->getText() + "</h" + tag + ">";

        Iterator* it = p->createIterator();
        for (it->first(); !it->isDone(); it->next()) {
            it->currentItem()->accept(this);
        }

        _result += "</div>";

        delete it;
    }

    std::string getResult() const override { 
        // std::cout << _result << std::endl;
        return _result; 
    }

private:
    std::string _result = "";  
};