class Circle : public Shape {
public:
    Circle(double radius) {}

    double area() const override { }

    double perimeter() const override { }

    std::string info() const override { }

    Iterator* createIterator() override { }
};