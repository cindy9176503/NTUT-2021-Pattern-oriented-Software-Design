class ShapeInfoVisitor : public ShapeVisitor {
   public:
    void visitCircle(Circle* circle) {}

    void visitRectangle(Rectangle* rectangle) {}

    void visitTriangle(Triangle* triangle) {}

    void visitCompoundShape(CompoundShape* compoundShape) {}
    
    std::string getResult() {}
};