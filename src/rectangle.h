class Rectangle : public Shape {
public: 
    Rectangle(double length, double width) { }

    double area() const override { }

    double perimeter() const override { }
    
    std::string info() const override { }

    Iterator* createIterator() override { }
};
