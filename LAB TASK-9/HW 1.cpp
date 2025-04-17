#include <iostream>
using namespace std;

class Shape {
public:
    virtual double getArea() const = 0;
    virtual ~Shape() {}
};

class Rectangle : public Shape {
private:
    double width;
    double height;

public:
    Rectangle(double w, double h) : width(w), height(h) {}

    double getArea() const override {
        return width * height;
    }
};

class Triangle : public Shape {
private:
    double base;
    double height;

public:
    Triangle(double b, double h) : base(b), height(h) {}

    double getArea() const override {
        return 0.5 * base * height;
    }
};

int main() {
    Shape* shapes[2];
    shapes[0] = new Rectangle(5, 4);
    shapes[1] = new Triangle(3, 6);

    cout << "Rectangle area: " << shapes[0]->getArea() << endl;
    cout << "Triangle area: " << shapes[1]->getArea() << endl;

    delete shapes[0];
    delete shapes[1];

    return 0;
}