#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Car {
public:
    string name;
    int id;

    Car(string n, int i) : name(n), id(i) {
        cout << "Car Created: " << name << " (ID: " << id << ")\n";
    }
    
    ~Car() {
        cout << "Car Destroyed: " << name << " (ID: " << id << ")\n";
    }
};

class Garage {
private:
    vector<Car*> cars;
public:
    Garage() {
        cout << "Garage Created\n";
    }
    
    ~Garage() {
        cout << "Garage Destroyed\n";
    }

    void parkCar(Car* car) {
        cars.push_back(car);
        cout << "Car Parked: " << car->name << " (ID: " << car->id << ")\n";
    }
    
    void listCars() {
        if (cars.empty()) {
            cout << "No cars in the garage.\n";
        } else {
            cout << "Cars in garage:\n";
            for (Car* car : cars) {
                cout << " " << car->name << " (ID: " << car->id << ")\n";
            }
        }
    }
};

int main() {
    Car car1("Toyota", 101);
    Car car2("Honda", 102);
    Car car3("Ford", 103);

    Garage garage;

    garage.parkCar(&car1);
    garage.parkCar(&car2);
    garage.parkCar(&car3);
    
    garage.listCars();
    
    {
        Car car4("BMW", 104);
        garage.parkCar(&car4);
    } // car4 goes out of scope and is destroyed
    
    garage.listCars(); // Still holds a pointer to destroyed car4
    
    return 0;
}

