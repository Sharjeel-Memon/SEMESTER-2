#include <iostream>
using namespace std;

class Person {
protected:
    int employeeID;
public:
    void getData() {
        cout << "Enter Employee ID: ";
        cin >> employeeID;
    }
    void displayData() const {
        cout << "Employee ID: " << employeeID << endl;
    }
};

class Admin : public Person {
protected:
    string name;
    double monthlyIncome;
public:
    void getData() {
        Person::getData();
        cout << "Enter Name: ";
        cin >> name;
        cout << "Enter Monthly Income: ";
        cin >> monthlyIncome;
    }
    void displayData() const {
        Person::displayData();
        cout << "Name: " << name << endl;
        cout << "Monthly Income: " << monthlyIncome << endl;
        cout << "Annual Bonus: " << bonus() << endl;
    }
    double bonus() const {
        return monthlyIncome * 0.05 * 12;
    }
};

class Accounts : public Person {
protected:
    string name;
    double monthlyIncome;
public:
    void getData() {
        Person::getData();
        cout << "Enter Name: ";
        cin >> name;
        cout << "Enter Monthly Income: ";
        cin >> monthlyIncome;
    }
    void displayData() const {
        Person::displayData();
        cout << "Name: " << name << endl;
        cout << "Monthly Income: " << monthlyIncome << endl;
        cout << "Annual Bonus: " << bonus() << endl;
    }
    double bonus() const {
        return monthlyIncome * 0.05 * 12;
    }
};

int main() {
    Admin adminEmployee;
    Accounts accountsEmployee;
    
    cout << "Enter Admin Employee Details:\n";
    adminEmployee.getData();
    
    cout << "\nEnter Accounts Employee Details:\n";
    accountsEmployee.getData();
    
    cout << "\nAdmin Employee Information:\n";
    adminEmployee.displayData();
    
    cout << "\nAccounts Employee Information:\n";
    accountsEmployee.displayData();
    
    return 0;
}
