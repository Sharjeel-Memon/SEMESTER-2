#include <iostream>
#include <string>
using namespace std;

class Wallet {
private:
    double balance = 0;
    const double dailyLimit = 5000;
    double usedToday = 0;

public:
    bool deposit(double amount) {
        if (amount <= 0) {
            cout << "Invalid amount!\n";
            return false;
        }
        if (usedToday + amount > dailyLimit) {
            cout << "Daily limit exceeded!\n";
            return false;
        }
        balance += amount;
        usedToday += amount;
        cout << "Deposited: " << amount << "\n";
        return true;
    }

    bool withdraw(double amount) {
        if (amount <= 0 || amount > balance) {
            cout << "Invalid amount!\n";
            return false;
        }
        balance -= amount;
        cout << "Withdrawn: " << amount << "\n";
        return true;
    }

    double checkBalance() const {
        return balance;
    }

    void resetDaily() {
        usedToday = 0;
    }
};

class User {
private:
    string name;
    Wallet wallet;

public:
    User(string n) : name(n) {}

    void deposit(double amount) {
        wallet.deposit(amount);
    }

    void withdraw(double amount) {
        wallet.withdraw(amount);
    }

    void checkBalance() const {
        cout << name << "'s balance: " << wallet.checkBalance() << "\n";
    }
};

int main() {
    User alice("Ali");
    alice.deposit(1000);
    alice.withdraw(500);
    alice.checkBalance();
    return 0;
}