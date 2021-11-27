#pragma once

#include <string>

#include "../circle.h"
#include "../compound_shape.h"
#include "../rectangle.h"
#include "../triangle.h"
#include "./shape_visitor.h"

class ShapeInfoVisitor : public ShapeVisitor {
public:
    void visitCircle(Circle* circle) {
        int spaceNum = this->_depth * 2;
        for(int i = 0; i<spaceNum; i++) { _result += " "; }
        _result = _result + circle->info() + "\n";
    }

    void visitRectangle(Rectangle* rectangle) {
        int spaceNum = this->_depth * 2;
        for(int i = 0; i<spaceNum; i++) { _result += " "; }
        _result = _result + rectangle->info() + "\n";
    }

    void visitTriangle(Triangle* triangle) {
        int spaceNum = this->_depth * 2;
        for(int i = 0; i<spaceNum; i++) { _result += " "; }
        _result = _result + triangle->info() + "\n";
    }

    void visitCompoundShape(CompoundShape* compoundShape) {
        int spaceNum = this->_depth * 2;
        std::string space = "";

        for(int i = 0; i < spaceNum; i ++) { space += " "; }

        _result = _result + space + "CompoundShape{\n";
        _depth ++;

        Iterator* it = compoundShape->createIterator();
        for (it->first(); !it->isDone(); it->next()) {
            it->currentItem()->accept(this);
        }
        _depth --;

        _result = _result + space + "}\n";

        delete it;
    }
    
    std::string getResult() {
        return _result;
    }

private:
    int _depth = 0;
    std::string _result = "";
};