class Triangle: public Shape {
public:
    Triangle(TwoDimensionalVector vec1, TwoDimensionalVector vec2) { }

    double area() const override { }

    double perimeter() const override { }

    std::string info() const override { }

    Iterator* createIterator() override { }
};
