// you don't need to modify the class

#pragma once

#include "../shape.h"

class Iterator {
public:
    virtual ~Iterator() {}

    virtual void first() = 0;

    virtual Shape* currentItem() const = 0;

    virtual void next() = 0;

    virtual bool isDone() const = 0;
};