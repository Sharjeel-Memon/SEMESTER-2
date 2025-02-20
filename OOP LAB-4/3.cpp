#include <iostream>
#include <cmath>
#include <cstdlib>

// ./3 5.5 "1234" "Screwdriver" 10 15.75


using namespace std;

class Invoice {
private:
    string partNumber;
    string partDescription;
    int quantity;
    double pricePerItem;

public:
    // Constructor
    Invoice(string pNum, string pDesc, int qty, double price) {
        partNumber = pNum;
        partDescription = pDesc;
        quantity = (qty > 0) ? qty : 0;
        pricePerItem = (price > 0) ? price : 0.0;
    }
    
    // Calculate Invoice Amount
    double getInvoiceAmount() const {
        return quantity * pricePerItem;
    }
    
    // Display Invoice
    void displayInvoice() const {
        cout << "Part Number: " << partNumber << endl;
        cout << "Part Description: " << partDescription << endl;
        cout << "Quantity: " << quantity << endl;
        cout << "Price per Item: " << pricePerItem << endl;
        cout << "Total Invoice Amount: " << getInvoiceAmount() << endl;
    }
};

int main(int argc, char* argv[]) {
    if (argc < 5) {
        cout << "Invalid Amount of Arguments!" << endl;
        return 1;
    }
    
    
    // Invoice Calculation
    string partNumber = argv[1];
    string partDescription = argv[2];
    int quantity = stoi(argv[3]);
    double pricePerItem = stod(argv[4]);
    
    Invoice inv(partNumber, partDescription, quantity, pricePerItem);
    cout << "\nInvoice Details:" << endl;
    inv.displayInvoice();
    
    return 0;
}
