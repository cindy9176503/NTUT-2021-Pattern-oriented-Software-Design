#pragma once

#include <fstream>
#include <string>
#include <vector>

#include "../shape.h"
#include "scanner.h"
#include "shape_builder.h"

class ShapeParser{
public:
    // `filePath` is a relative path of makefile
    ShapeParser(std::string filePath) {
        std::ifstream ifs(filePath);
        char _buffer[256] = {0};

        if(ifs) {
            ifs.read(_buffer, sizeof(_buffer));
            ifs.close();
        }
        
        _scanner = new Scanner(_buffer);
        _builder = ShapeBuilder::getInstance();
        parse();
    }

    ~ShapeParser() {
        delete _builder;
        delete _scanner;
        delete _result;
    }

    void parse() {
        _builder->buildCircle(1.0);
        /*while(!_scanner->isDone()){
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
        }*/
    }

    Shape* getShape() {
        _result = _builder->getShape();
        _builder->reset();
        return _result;
    }

private:
    ShapeBuilder* _builder;
    Scanner* _scanner;
    Shape* _result;
};