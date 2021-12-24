#pragma once

#include <fstream>
#include <string>
#include <vector>

#include "../shape.h"
#include "scanner.h"
#include "shape_builder.h"

class ShapeParser {
   public:
    // `filePath` is a relative path of makefile
    ShapeParser(std::string filePath) {}

    ~ShapeParser() {}

    void parse() {}

    Shape* getShape() {}
};
