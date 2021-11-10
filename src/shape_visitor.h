#pragma once

#include <string>
#include <list>

#include "./shape.h"

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

typedef bool (*ShapeConstraint)(Shape*); // pointer to function
class SelectShapeVisitor: public ShapeVisitor {
public:
    // SelectShapeVisitor(): _result(nullptr), _constraint(nullptr) {}
    SelectShapeVisitor(ShapeConstraint constraint): _result(nullptr), _constraint(constraint) {}
    void visitCircle(Circle* c);
    void visitRectangle(Rectangle* r);
    void visitTriangle(Triangle* t);
    void visitCompoundShape(CompoundShape* cs);
    Shape* getShape();

private:
    Shape* _result;
    ShapeConstraint _constraint;
};

class SelectAllShapeVisitor: public ShapeVisitor {
public:
    ~SelectAllShapeVisitor() {
        for (auto it = _result.begin(); it != _result.end(); ++ it) {
            delete *it;
        }
    }
    // SelectShapeVisitor(): _result(nullptr), _constraint(nullptr) {}
    SelectAllShapeVisitor(ShapeConstraint constraint): _constraint(constraint) {}
    void visitCircle(Circle* c);
    void visitRectangle(Rectangle* r);
    void visitTriangle(Triangle* t);
    void visitCompoundShape(CompoundShape* cs);
    std::string getResultInfo();
    std::list<Shape*> getResult();

private:
    ShapeConstraint _constraint;
    std::string _resultInfo;
    std::list<Shape*> _result;
};