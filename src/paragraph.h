#ifndef PARAGRAPH_H
#define PARAGRAPH_H

#include <vector>

class Paragraph : public Article {
public:
    Paragraph(int level, std::string text):_level(level) {
        if(_level < 1 || _level > 6) { throw "Out of range, 1 <= level <= 6"; }

        for(int i = 0; i < _level; i ++) {
            _text += "#";
        }
        _text = _text + " " + text;

        _content.push_back(new Text(_text));
    }

    ~Paragraph() { }

    std::string getText() const override { 
        std::string str;
        for(int i = 0; i < _content.size(); i ++) {
            str += _content[i] -> getText();
            if(i < _content.size()-1) {
                str += "\n";
            }
        }

        return str;
    }

    int getLevel() const override { return _level; }

    void add(Article* content) override {
        _content.push_back(content); 
    }

private:
    int _level;
    std::string _text;
    std::vector<Article*> _content;
};

#endif