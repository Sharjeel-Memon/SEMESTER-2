#include <iostream>
#include <string>
#include <cstdlib>

// ./2 1000 3 1 2000 3 2 4000 2 2500 3

using namespace std;

class Account {
private:
    double balance;

public:
    // Constructor
    Account(double initialBalance) {
        if (initialBalance >= 0)
            balance = initialBalance;
        else {
            balance = 0;
            cout << "Invalid initial balance. Setting balance to 0." << endl;
        }
    }

    // Credit function
    void credit(double amount) {
        balance += amount;
        cout << "Amount credited: " << amount << endl;
    }

    // Debit function
    void debit(double amount) {
        if (amount > balance)
            cout << "Debit amount exceeded account balance." << endl;
        else {
            balance -= amount;
            cout << "Amount debited: " << amount << endl;
        }
    }

    // Get balance function
    double getBalance() const {
        return balance;
    }
};

int main(int argc, char* argv[]) {
    if (argc < 2) {
        cout << "Invalid Amount of Arguments!" << endl;
        return 1;
    }
    
    double initialBalance = stod(argv[1]);
    Account acc(initialBalance);
    
    for (int i = 2; i < argc; i++) {
        int choice = stoi(argv[i]);
        
        switch (choice) {
            case 1: 
			// Credit
                if (i + 1 < argc) {
                    double amount = stod(argv[++i]);
                    acc.credit(amount);
                } else {
                    cout << "Missing amount for credit operation." << endl;
                }
                break;
            case 2: 
			// Debit
                if (i + 1 < argc) {
                    double amount = stod(argv[++i]);
                    acc.debit(amount);
                } else {
                    cout << "Missing amount for debit operation." << endl;
                }
                break;
            case 3: 
			// Check Balance
                cout << "Current Balance: " << acc.getBalance() << endl;
                break;
            default:
                cout << "Invalid operation code: " << choice << endl;
        }
    }
    
    return 0;
}
