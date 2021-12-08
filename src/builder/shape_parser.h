#pragma once

#include "./scanner.h"
#include "./shape_builder.h"
#include "../shape.h"

#include <string>
#include <fstream>

class ShapeParser{
public:
    // `filePath` is a relative path of makefile
    ShapeParser(std::string filePath) {
        std::ifstream ifs(filePath);

        if(ifs) {
            ifs.read(_buffer, sizeof(_buffer));
            ifs.close();
        }
        
        _scanner = new Scanner(_buffer);
        parse();
    }

    ~ShapeParser() {
        // delete _builder;
        // delete _scanner;
    }

    void parse() {
        _builder = new ShapeBuilder();
        
        while(!_scanner->isDone()){
            std::string token = _scanner->next();
            if(token == "Circle"){
                _builder->buildCircle(_scanner->nextDouble());
            }else if(token == "Rectangle"){
                _builder->buildRectangle(_scanner->nextDouble(), _scanner->nextDouble());
            }else if(token == "Triangle"){
                _builder->buildTriangle(_scanner->nextDouble(), _scanner->nextDouble(), _scanner->nextDouble(), _scanner->nextDouble());
            }else if(token == "CompoundShape"){
                _scanner->next(); // ignore {
                _builder->buildCompoundBegin();
            }else if(token == "}"){
                _builder->buildCompoundEnd();
            }
        }
    }

    Shape* getShape() {
        return _builder->getShape();
    }

private:
    ShapeBuilder* _builder;
    Scanner* _scanner;
    char _buffer[256] = {0};
};
