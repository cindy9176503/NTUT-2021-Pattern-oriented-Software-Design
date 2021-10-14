#ifndef TEXT_H
#define TEXT_H

#include "article.h"

class Text : public Article {
public:
    Text(std::string text):_text(text) {}

    ~Text() {}
    
    std::string getText() const override { return _text; }

private:
    std::string _text;

};

#endif