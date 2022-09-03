#pragma once

#include <vector>
#include <typeinfo>

#include "article.h"
#include "text.h"
#include "iterator/iterator.h"
#include "iterator/compound_iterator.h"
#include "visitor/article_visitor.h"

class Paragraph : public Article {
public:
    Paragraph(int level, std::string text):_level(level), _text(text) {
        if(_level < 1 || _level > 6) { throw "Out of range, 1 <= level <= 6"; }
    }

    ~Paragraph() {}

    std::string getText() const override { 
        return _text;
    }

    int getLevel() const override { return _level; }

    Iterator* createIterator() override { return new CompoundIterator<std::vector<Article*>::iterator>(_content.begin(), _content.end()); }

    void add(Article* content) override {
        if(typeid(*content) == typeid(Paragraph) && content -> getLevel() <= _level) { throw "Add lower or equal level paragraph"; }
        _content.push_back(content);
    }

    void accept(ArticleVisitor* visitor) override { visitor->visitParagraph(this); }

private:
    int _level;
    std::string _text;
    std::vector<Article*> _content;
};