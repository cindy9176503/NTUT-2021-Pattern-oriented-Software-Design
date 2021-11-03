// you should define a template class or type `ForwardIterator`

#pragma once

#include "../shape.h"
#include "./iterator.h"

#include <list>

template<class ForwardIterator>

class CompoundIterator : public Iterator{
public:
    CompoundIterator(ForwardIterator begin, ForwardIterator end):_begin(begin), _end(end) {         
        first();
    }

    void first() override { _current = _begin;}

    Shape* currentItem() const override { 
        if(isDone()) { throw("is done"); return NULL;}
        else { return *_current; }
    }

    void next() override {
        if(isDone()) { throw("is done"); }
        else { ++ _current; }
    }

    bool isDone() const override { return _current == _end; }
private:
    ForwardIterator _begin, _end, _current;
};
