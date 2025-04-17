#include <iostream>
#include <string>
using namespace std;

class Car {
protected:
    string model;
    double price;

public:
    Car(string m, double p) : model(m), price(p) {}

    string getModel() const { return model; }
    double getPrice() const { return price; }
    virtual void setPrice(double p) = 0;
    virtual ~Car() {}
};

class Color : public Car {
private:
    string color;

public:
    Color(string m, double p, string c) : Car(m, p), color(c) {}

    void setPrice(double p) override {
        price = p;
        cout << "Price set for " << color << " " << model << endl;
    }

    string getColor() const { return color; }
};

class Company : public Car {
private:
    string company;

public:
    Company(string m, double p, string comp) : Car(m, p), company(comp) {}

    void setPrice(double p) override {
        price = p;
        cout << "Price set for " << company << " " << model << endl;
    }

    string getCompany() const { return company; }
};

int main() {
    Car* cars[2];
    cars[0] = new Color("Sedan", 25000, "Red");
    cars[1] = new Company("SUV", 35000, "Toyota");

    cout << "Model: " << cars[0]->getModel() << ", Price: $" << cars[0]->getPrice() << endl;
    cout << "Model: " << cars[1]->getModel() << ", Price: $" << cars[1]->getPrice() << endl;

    cars[0]->setPrice(26000);
    cars[1]->setPrice(36000);

    delete cars[0];
    delete cars[1];

    return 0;
}