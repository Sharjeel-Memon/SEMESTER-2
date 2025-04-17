#include <iostream>
#include <string>
using namespace std;

class Person {
protected:
    string name;
    double salary;

public:
    virtual void getdata() {
        cout << "Enter name: ";
        cin >> name;
        cout << "Enter salary: ";
        cin >> salary;
    }

    virtual void displaydata() {
        cout << "Name: " << name << ", Salary: " << salary << endl;
    }

    virtual double bonus() {
        return 0;
    }

    virtual ~Person() {}
};

class Admin : virtual public Person {
public:
    void getdata() override {
        Person::getdata();
    }

    double bonus() override {
        return salary * 0.10;
    }
};

class Account : virtual public Person {
public:
    void getdata() override {
        Person::getdata();
    }

    double bonus() override {
        return salary * 0.15;
    }
};

class Master : public Admin, public Account {
public:
    void getdata() override {
        Person::getdata();
    }

    void displaydata() override {
        Person::displaydata();
        cout << "Bonus: " << bonus() << endl;
    }

    double bonus() override {
        return (Admin::bonus() + Account::bonus()) / 2;
    }
};

int main() {
    Person* employees[3];
    employees[0] = new Admin;
    employees[1] = new Account;
    employees[2] = new Master;

    cout << "Enter Admin details:\n";
    employees[0]->getdata();
    cout << "\nEnter Account details:\n";
    employees[1]->getdata();
    cout << "\nEnter Master details:\n";
    employees[2]->getdata();

    cout << "\nEmployee Information:\n";
    for (int i = 0; i < 3; i++) {
        employees[i]->displaydata();
        cout << "Calculated Bonus: " << employees[i]->bonus() << "\n\n";
        delete employees[i];
    }

    return 0;
}