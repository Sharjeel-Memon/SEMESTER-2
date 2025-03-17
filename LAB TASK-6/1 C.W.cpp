#include <iostream>
#include <string>
using namespace std;

// Base class for BankAccount
class BankAccount {
protected:
    string accountNumber;
    double balance;

public:
    BankAccount(string accNum, double bal) : accountNumber(accNum), balance(bal) {}
    virtual ~BankAccount() {}

    virtual void deposit(double amount) {
        balance += amount;
        cout << "Deposited: " << amount << " New Balance: " << balance << endl;
    }

    virtual void withdraw(double amount) {
        if (balance >= amount) {
            balance -= amount;
            cout << "Withdrawn: " << amount << " New Balance: " << balance << endl;
        } else {
            cout << "Insufficient funds." << endl;
        }
    }

    virtual void display() const {
        cout << "Account: " << accountNumber << " Balance: " << balance << endl;
    }
};

// Derived classes for specific accounts
class SavingsAccount : public BankAccount {
    double interestRate;

public:
    SavingsAccount(string accNum, double bal, double rate) : BankAccount(accNum, bal), interestRate(rate) {}
    void applyInterest() {
        balance += balance * interestRate;
        cout << "Interest applied. New Balance: " << balance << endl;
    }
};

class CheckingAccount : public BankAccount {
    double overdraftLimit;

public:
    CheckingAccount(string accNum, double bal, double limit) : BankAccount(accNum, bal), overdraftLimit(limit) {}
    void withdraw(double amount) override {
        if (balance + overdraftLimit >= amount) {
            balance -= amount;
            cout << "Withdrawn: " << amount << " New Balance: " << balance << endl;
        } else {
            cout << "Overdraft limit exceeded!" << endl;
        }
    }
};

class BusinessAccount : public BankAccount {
    double taxRate;

public:
    BusinessAccount(string accNum, double bal, double tax) : BankAccount(accNum, bal), taxRate(tax) {}
    void deposit(double amount) override {
        double taxAmount = amount * taxRate;
        balance += (amount - taxAmount);
        cout << "Deposited: " << amount << " Tax Withheld: " << taxAmount << " New Balance: " << balance << endl;
    }
};

// Base class for user roles
class User {
protected:
    string name;
public:
    User(string n) : name(n) {}
    virtual ~User() {}
    virtual void deposit(BankAccount* acc, double amount) {
        acc->deposit(amount);
    }
    virtual void withdraw(BankAccount* acc, double amount) {
        acc->withdraw(amount);
    }
};

class Customer : public User {
public:
    Customer(string n) : User(n) {}
};

class Employee : public User {
public:
    Employee(string n) : User(n) {}
};

class Teller : public Employee {
public:
    Teller(string n) : Employee(n) {}
    void withdraw(BankAccount* acc, double amount) override {
        cout << "Teller processing withdrawal." << endl;
        acc->withdraw(amount);
    }
};

class Manager : public Employee {
public:
    Manager(string n) : Employee(n) {}
    void deposit(BankAccount* acc, double amount) override {
        cout << "Manager approving deposit." << endl;
        acc->deposit(amount);
    }
    void withdraw(BankAccount* acc, double amount) override {
        cout << "Manager approving withdrawal." << endl;
        acc->withdraw(amount);
    }
};

int main() {
    BankAccount* accounts[3];
    accounts[0] = new SavingsAccount("SA123", 1000, 0.05);
    accounts[1] = new CheckingAccount("CA456", 500, 200);
    accounts[2] = new BusinessAccount("BA789", 3000, 0.10);

    User* users[3];
    users[0] = new Customer("Alice");
    users[1] = new Teller("Bob");
    users[2] = new Manager("Charlie");

    users[0]->deposit(accounts[0], 500);
    users[0]->withdraw(accounts[0], 200);
    users[1]->deposit(accounts[1], 1000);
    users[1]->withdraw(accounts[1], 500);
    users[2]->deposit(accounts[2], 2000);
    users[2]->withdraw(accounts[2], 1000);

    for (int i = 0; i < 3; ++i) {
        accounts[i]->display();
    }

    for (int i = 0; i < 3; ++i) {
        delete accounts[i];
        delete users[i];
    }

    return 0;
}
