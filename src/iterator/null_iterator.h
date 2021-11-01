#pragma once

#include "./iterator.h"

class NullIterator : public Iterator {
public:
    void first() override { throw("method not allowed"); }

    // Shape* currentItem() const override { }

    void next() override { throw("method not allowed"); }

    bool isDone() const override { return true; }
};