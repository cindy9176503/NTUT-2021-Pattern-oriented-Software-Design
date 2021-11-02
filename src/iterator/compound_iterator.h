// you should define a template class or type `ForwardIterator`

#pragma once

#include "../shape.h"
#include "./iterator.h"

template<class ForwardIterator>

class CompoundIterator : public Iterator{
public:
    CompoundIterator(ForwardIterator begin, ForwardIterator end):_begin(begin), _end(end) { 
        
    }

    void first() override { throw("method not allowed"); }

    Shape* currentItem() const override { throw("method not allowed"); }

    void next() override { throw("method not allowed"); }

    bool isDone() const override { return true; }
private:
    ForwardIterator _begin, _end;
};