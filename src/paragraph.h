#pragma once

#include <vector>

#include "article.h"
#include "text.h"
#include "iterator/iterator.h"
#include "iterator/compound_iterator.h"

class Paragraph : public Article {
public:
    Paragraph(int level, std::string text):_level(level) {
        if(_level < 1 || _level > 6) { throw "Out of range, 1 <= level <= 6"; }

        for(int i = 0; i < _level; i ++) {
            _text += "#";
        }
        _text = _text + " " + text + "\n";

        _content.push_back(new Text(_text));
    }

    ~Paragraph() {}

    std::string getText() const override { 
        std::string str;

        str += _content[0] -> getText();
        
        for(int i = 1; i < _content.size(); i ++) {
            str += _content[i] -> getText();
            if(typeid(_content[i]) != typeid(Paragraph) && i != _content.size() - 1) { str += "\n"; }
        }
        
        return str;
    }

    int getLevel() const override { return _level; }

    Iterator* createIterator() override { return new CompoundIterator<std::vector<Article*>::iterator>(_content.begin(), _content.end()); }

    void add(Article* content) override {
        if(typeid(*content) == typeid(Paragraph) && content -> getLevel() <= _level) { throw "Add lower or equal level paragraph"; }
        _content.push_back(content);
    }

    // void accept(ArticleVisitor* visitor) override { visitor->visitParagraph(this); }

private:
    int _level;
    std::string _text;
    std::vector<Article*> _content;

};