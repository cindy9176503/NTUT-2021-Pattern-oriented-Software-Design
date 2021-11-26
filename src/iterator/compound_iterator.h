#pragma once

#include <string>

#include "./iterator.h"

template <class ForwardIterator>
class CompoundIterator : public Iterator {
   public:
    CompoundIterator(ForwardIterator begin, ForwardIterator end)
        : _begin(begin), _end(end) {}
    void first() override {}
    Shape* currentItem() const override {}
    void next() override {}
    bool isDone() const override {}

   private:
    ForwardIterator _current;
    ForwardIterator _begin;
    ForwardIterator _end;
};