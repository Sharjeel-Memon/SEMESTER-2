#include <iostream>
#include <cmath>
#include <cstdlib>

// ./1 2.5

using namespace std;

class Circle {
private:
    double radius;

public:
    // Constructor
    Circle(double r) {
        radius = r;
    }
    
    // Getter for Area
    double getArea() const {
        return M_PI * radius * radius;
    }
    
    // Getter for Perimeter (Circumference)
    double getPerimeter() const {
        return 2 * M_PI * radius;
    }
};

int main(int argc, char* argv[]) {
    if (argc < 2) {
        cout << "Invalid Arguments!" << endl;
        return 1;
    }
    
    double radius = stod(argv[1]);
    Circle c(radius);
    
    cout << "The Area of the Circle is: " << c.getArea() << endl;
    cout << "The Perimeter of the Circle is: " << c.getPerimeter() << endl;
    
    return 0;
}
