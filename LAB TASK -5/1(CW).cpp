#include <iostream>

using namespace std;


class Engine {
private:
    bool isRunning;
public:
    Engine() : isRunning(false) {
        cout << "Engine created" << endl;
    }
    ~Engine() {
        cout << "Engine destroyed" << endl;
    }
    void start() {
        if (isRunning) {
            cout << "Engine is already running" << std::endl;
        } else {
            isRunning = true;
            cout << "Engine started" << endl;
        }
    }
    void stop() {
        if (!isRunning) {
            cout << "Engine is already stopped" << endl;
        } else {
            isRunning = false;
            cout << "Engine stopped" << endl;
        }
    }
};

class Car {
private:
    Engine engine; // Composition: Engine is a part of Car
public:
    Car() {
        cout << "Car created" << endl;
    }
    ~Car() {
        cout << "Car destroyed" << endl;
    }
    void startCar() {
        engine.start();
    }
    void stopCar() {
        engine.stop();
    }
};

int main() {
    cout << "Creating car object..." << endl;
    Car myCar;
    myCar.startCar();
    myCar.startCar(); // Check if already running
    myCar.stopCar();
    myCar.stopCar(); // Check if already stopped
    return 0;
}
