#pragma once

#include <string>

class Circle; 
class Rectangle; 
class Triangle; 
class CompoundShape; 

class ShapeVisitor {
public:
    virtual ~ShapeVisitor() {}
    virtual void visitCircle(Circle* c) = 0;
    virtual void visitRectangle(Rectangle* r) = 0;   
    virtual void visitTriangle(Triangle* t) = 0;   
    virtual void visitCompoundShape(CompoundShape* cs) = 0;

protected:
    ShapeVisitor() {}

};

class ShapeInfoVisitor: public ShapeVisitor {
public:
    void visitCircle(Circle* c);
    void visitRectangle(Rectangle* r);
    void visitTriangle(Triangle* t);   
    void visitCompoundShape(CompoundShape* cs);
    int infoLabel = 0;
    std::string getResult();

private:
    std::string _result;
    int _currentInfoLabel = 0;
};
