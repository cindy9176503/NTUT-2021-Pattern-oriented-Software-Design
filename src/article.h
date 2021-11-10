#pragma once

class Iterator;


class Article {
   public:
    virtual ~Article(){};

    virtual std::string getText() const = 0;

    virtual int getLevel() const { return 0; }

    virtual Iterator* createIterator() = 0;

    //virtual void accept(ArticleVisitor* visitor) = 0;

    virtual void add(Article* dpFormat){ throw("method not allowed"); }
};