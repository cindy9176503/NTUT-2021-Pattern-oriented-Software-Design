#pragma once

#include <string>
#include <vector>

class Scanner {
   public:
    Scanner(std::string input) : _input(input) {}

    std::string next() {}

    double nextDouble() {}

    bool isDone() {}

   private:
    const std::vector<std::string> tokenList = {
        "Circle", "Rectangle", "Triangle", "CompoundShape", "(", ")", "[", "]",
        "{",      "}",         ","};

    void skipWhiteSpace() {}
};