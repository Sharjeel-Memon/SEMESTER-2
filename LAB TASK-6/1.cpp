#include <iostream>
#include <string>
using namespace std;

class BankAccount {
protected:
    string account_number;
    double balance;

public:
    BankAccount(string account_number, double balance)
        : account_number(account_number), balance(balance) {}

    virtual ~BankAccount() {}

    virtual void deposit(double amount) {
        balance += amount;
    }

    virtual void withdraw(double amount) {
        if (amount > balance) {
            cout << "Insufficient funds" << endl;
        } else {
            balance -= amount;
        }
    }

    double getBalance() const {
        return balance;
    }

    string getAccountNumber() const {
        return account_number;
    }

    virtual void print() const {
        cout << "Account " << account_number << " has balance " << balance << endl;
    }
};

class SavingsAccount : public BankAccount {
private:
    double interest_rate;

public:
    SavingsAccount(string account_number, double balance, double interest_rate)
        : BankAccount(account_number, balance), interest_rate(interest_rate) {}

    void applyInterest() {
        balance += balance * interest_rate;
    }

    void print() const override {
        cout << "Savings Account " << account_number << " has balance " << balance << endl;
    }
};

class CheckingAccount : public BankAccount {
private:
    double overdraft_limit;

public:
    CheckingAccount(string account_number, double balance, double overdraft_limit)
        : BankAccount(account_number, balance), overdraft_limit(overdraft_limit) {}

    void withdraw(double amount) override {
        if (amount > balance + overdraft_limit) {
            cout << "Overdraft limit exceeded" << endl;
        } else {
            balance -= amount;
            if (balance < 0) {
                cout << "Overdraft limit reached" << endl;
            }
        }
    }

    void print() const override {
        cout << "Checking Account " << account_number << " has balance " << balance << endl;
    }
};

class BusinessAccount : public BankAccount {
private:
    double corporate_tax_rate;

public:
    BusinessAccount(string account_number, double balance, double corporate_tax_rate)
        : BankAccount(account_number, balance), corporate_tax_rate(corporate_tax_rate) {}

    void deposit(double amount) override {
        double tax = amount * corporate_tax_rate;
        balance += (amount - tax);
    }

    void print() const override {
        cout << "Business Account " << account_number << " has balance " << balance << endl;
    }
};

class UserRole {
protected:
    string name;

public:
    UserRole(string name) : name(name) {}

    virtual void performAction(BankAccount* account, const string& action, double amount = 0) = 0;

    string getName() const {
        return name;
    }
};

class Customer : public UserRole {
public:
    Customer() : UserRole("Customer") {}

    void performAction(BankAccount* account, const string& action, double amount = 0) override {
        if (action == "deposit") {
            account->deposit(amount);
        } else if (action == "withdraw") {
            account->withdraw(amount);
        }
    }
};

class Employee : public UserRole {
public:
    Employee(string name) : UserRole(name) {}
};

class Teller : public Employee {
public:
    Teller() : Employee("Teller") {}

    void performAction(BankAccount* account, const string& action, double amount = 0) override {
        if (action == "deposit") {
            account->deposit(amount);
        } else if (action == "withdraw") {
            account->withdraw(amount);
        } else if (action == "freeze") {
            cout << "Account " << account->getAccountNumber() << " has been frozen." << endl;
        }
    }
};

class Manager : public Employee {
public:
    Manager() : Employee("Manager") {}

    void performAction(BankAccount* account, const string& action, double amount = 0) override {
        if (action == "deposit") {
            account->deposit(amount);
        } else if (action == "withdraw") {
            account->withdraw(amount);
        } else if (action == "freeze") {
            cout << "Account " << account->getAccountNumber() << " has been frozen." << endl;
        } else if (action == "adjust_limits") {
            cout << "Account " << account->getAccountNumber() << " limits adjusted." << endl;
        }
    }
};

void performOperations(BankAccount* accounts[], int accountCount, UserRole* users[], int userCount) {
    for (int i = 0; i < accountCount; ++i) {
        for (int j = 0; j < userCount; ++j) {
            cout << users[j]->getName() << " performing actions on Account " << accounts[i]->getAccountNumber() << ":" << endl;
            users[j]->performAction(accounts[i], "deposit", 100);
            users[j]->performAction(accounts[i], "withdraw", 50);

            if (SavingsAccount* sa = dynamic_cast<SavingsAccount*>(accounts[i])) {
                sa->applyInterest();
            }

            accounts[i]->print();
        }
    }
}

int main() {
    BankAccount* accounts[] = {
        new SavingsAccount("S123", 1000, 0.05),
        new CheckingAccount("C123", 500, 100),
        new BusinessAccount("B123", 10000, 0.02)
    };

    UserRole* users[] = {
        new Customer(),
        new Teller(),
        new Manager()
    };

    performOperations(accounts, 3, users, 3);

    // Cleanup dynamically allocated memory
    for (int i = 0; i < 3; ++i) {
        delete accounts[i];
        delete users[i];
    }

    return 0;
}

