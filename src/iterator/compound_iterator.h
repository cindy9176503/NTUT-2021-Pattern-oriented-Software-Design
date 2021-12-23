#pragma once

#include <string>

#include "./iterator.h"

template <class ForwardIterator>
class CompoundIterator : public Iterator {
   public:
    CompoundIterator(ForwardIterator begin, ForwardIterator end) {}

    void first() override {}

    Shape* currentItem() const override {}

    void next() override {}

    bool isDone() const override {}
};