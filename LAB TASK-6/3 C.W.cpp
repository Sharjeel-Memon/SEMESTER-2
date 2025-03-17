#include <iostream>
#include <string>
using namespace std;

class Employee {
protected:
    int id;
    string name;
public:
    Employee(int empId, string empName) : id(empId), name(empName) {}
    virtual ~Employee() {}
    virtual void displayRole() const = 0;
};

class IOrderTaker {
public:
    virtual void takeOrder(const string& order) = 0;
    virtual ~IOrderTaker() {}
};

class IOrderPreparer {
public:
    virtual void prepareOrder(const string& order) = 0;
    virtual ~IOrderPreparer() {}
};

class IBiller {
public:
    virtual void generateBill(double amount) = 0;
    virtual ~IBiller() {}
};

class Waiter : public Employee, public IOrderTaker {
public:
    Waiter(int empId, string empName) : Employee(empId, empName) {}
    void takeOrder(const string& order) override {
        cout << "Waiter " << name << " took order: " << order << endl;
    }
    void displayRole() const override {
        cout << "Waiter: " << name << endl;
    }
};

class Chef : public Employee, public IOrderPreparer {
public:
    Chef(int empId, string empName) : Employee(empId, empName) {}
    void prepareOrder(const string& order) override {
        cout << "Chef " << name << " prepared order: " << order << endl;
    }
    void displayRole() const override {
        cout << "Chef: " << name << endl;
    }
};

class Cashier : public Employee, public IBiller {
public:
    Cashier(int empId, string empName) : Employee(empId, empName) {}
    void generateBill(double amount) override {
        cout << "Cashier " << name << " generated bill: $" << amount << endl;
    }
    void displayRole() const override {
        cout << "Cashier: " << name << endl;
    }
};

class Manager : public Employee, public IOrderTaker, public IBiller {
public:
    Manager(int empId, string empName) : Employee(empId, empName) {}
    void takeOrder(const string& order) override {
        cout << "Manager " << name << " took order: " << order << endl;
    }
    void generateBill(double amount) override {
        cout << "Manager " << name << " approved bill: $" << amount << endl;
    }
    void displayRole() const override {
        cout << "Manager: " << name << endl;
    }
};

class Menu {
protected:
    string name;
    double basePrice;
public:
    Menu(string itemName, double price) : name(itemName), basePrice(price) {}
    virtual ~Menu() {}
    virtual double calculatePrice() const = 0;
    virtual void display() const {
        cout << "Menu Item: " << name << " | Base Price: $" << basePrice << endl;
    }
};

class FoodMenu : public Menu {
public:
    FoodMenu(string itemName, double price) : Menu(itemName, price) {}
    double calculatePrice() const override {
        return basePrice;
    }
};

class BeverageMenu : public Menu {
    double taxRate;
public:
    BeverageMenu(string itemName, double price, double tax) : Menu(itemName, price), taxRate(tax) {}
    double calculatePrice() const override {
        return basePrice + (basePrice * taxRate);
    }
};

int main() {
    IOrderTaker* orderTakers[] = {
        new Waiter(1, "Alice"),
        new Manager(4, "Diana")
    };

    IOrderPreparer* orderPreparers[] = {
        new Chef(2, "Bob")
    };

    IBiller* billers[] = {
        new Cashier(3, "Charlie"),
        new Manager(4, "Diana")
    };

    Menu* menus[] = {
        new FoodMenu("Burger", 5.99),
        new BeverageMenu("Cola", 2.50, 0.1)
    };

    for (int i = 0; i < 2; ++i) {
        orderTakers[i]->takeOrder("Burger and Cola");
    }
    
    for (int i = 0; i < 1; ++i) {
        orderPreparers[i]->prepareOrder("Burger and Cola");
    }

    for (int i = 0; i < 2; ++i) {
        billers[i]->generateBill(menus[0]->calculatePrice() + menus[1]->calculatePrice());
    }

    for (int i = 0; i < 2; ++i) {
        delete orderTakers[i];
    }
    
    for (int i = 0; i < 1; ++i) {
        delete orderPreparers[i];
    }

    for (int i = 0; i < 2; ++i) {
        delete billers[i];
    }

    for (int i = 0; i < 2; ++i) {
        delete menus[i];
    }

    return 0;
}

