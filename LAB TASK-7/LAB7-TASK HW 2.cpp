#include <iostream>
using namespace std;

class Shape {
private:
    double area;

public:
    Shape(double a = 0) : area(a) {}

    void display() const {
        cout << "Area: " << area << endl;
    }

    double Area() const {
        return area;
    }

    Shape operator+(const Shape& other) const {
        return Shape(this->area + other.area);
    }
};

int main() {
    Shape shape1(20.5);
    Shape shape2(30.5);
    
    Shape totalArea = shape1 + shape2;
    cout << "Total Area: "<<endl;
	 totalArea.display();
    
    return 0;
}
