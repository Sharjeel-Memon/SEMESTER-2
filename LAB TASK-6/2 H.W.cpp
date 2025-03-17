#include <iostream>
#include <string>

using namespace std;

class Vehicles {
protected:
    double price;
public:
    Vehicles(double x) : price(x) {}

    double getPrice() { return price; }
    void setPrice(double p) { price = p; }
};

class Car : public Vehicles {
protected:
    int seatingCapacity;
    int doors;
    string fuelType;

public:
    Car(double price, int seating, int doorCount, string fuel) 
        : Vehicles(price), seatingCapacity(seating), doors(doorCount), fuelType(fuel) {}

    int getSeatingCapacity() { return seatingCapacity; }
    int getDoors() { return doors; }
    string getFuelType() { return fuelType; }

    void setSeatingCapacity(int s) { seatingCapacity = s; }
    void setDoors(int d) { doors = d; }
    void setFuelType(string f) { fuelType = f; }
};

class Motorcycle : public Vehicles {
protected:
    int noCylinders;
    int noGears;
    int noWheels;

public:
    Motorcycle(double price, int cylinders, int gears, int wheels) 
        : Vehicles(price), noCylinders(cylinders), noGears(gears), noWheels(wheels) {}

    int getNoCylinders() { return noCylinders; }
    int getNoGears() { return noGears; }
    int getNoWheels() { return noWheels; }

    void setNoCylinders(int nc) { noCylinders = nc; }
    void setNoGears(int ng) { noGears = ng; }
    void setNoWheels(int nw) { noWheels = nw; }
};

class Audi : public Car {
    string modelType;
public:
    Audi(double price, int seating, int doors, string fuel, string model) 
        : Car(price, seating, doors, fuel), modelType(model) {}

    string getModelType() { return modelType; }
    void setModelType(string mt) { modelType = mt; }

    void display() {
        cout << "Audi Model: " << modelType << "\n";
        cout << "Price: $" << getPrice() << "\n";
        cout << "Seating Capacity: " << getSeatingCapacity() << "\n";
        cout << "Doors: " << getDoors() << "\n";
        cout << "Fuel Type: " << getFuelType() << "\n\n";
    }
};

class Yamaha : public Motorcycle {
    string makeType;
public:
    Yamaha(double price, int cylinders, int gears, int wheels, string make) 
        : Motorcycle(price, cylinders, gears, wheels), makeType(make) {}

    string getMakeType() { return makeType; }
    void setMakeType(string mt) { makeType = mt; }

    void display() {
        cout << "Yamaha Model: " << makeType << "\n";
        cout << "Price: $" << getPrice() << "\n";
        cout << "Cylinders: " << getNoCylinders() << "\n";
        cout << "Gears: " << getNoGears() << "\n";
        cout << "Wheels: " << getNoWheels() << "\n\n";
    }
};

int main() {
    Audi A(7500, 5, 4, "Petrol", "AX-1788");
    Yamaha Y(5000, 2, 6, 2, "YZF-R1");

    cout << "---- Audi Car Details ----\n";
    A.display();

    cout << "---- Yamaha Bike Details ----\n";
    Y.display();

    return 0;
}
