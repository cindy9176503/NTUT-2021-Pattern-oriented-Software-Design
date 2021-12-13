#pragma once

#include <string>
#include "./iterator.h"

template <class ForwardIterator>
class CompoundIterator : public Iterator {
public:
    CompoundIterator(ForwardIterator begin, ForwardIterator end): _begin(begin), _end(end), _current(begin) {}

    void first() override { _current = _begin;}

    Shape* currentItem() const override { 
        if(isDone()) { throw("is done"); }
        else { return *_current; }
    }

    void next() override {
        if(isDone()) { throw("is done"); }
        else { ++ _current; }
    }

    bool isDone() const override { return _current == _end; }

private:
    ForwardIterator _current;
    ForwardIterator _begin;
    ForwardIterator _end;
};