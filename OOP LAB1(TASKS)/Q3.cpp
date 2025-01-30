#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

float unitcalculator(int N, float &rate) {
    if (N < 199) {
        rate = 16.20;
        return rate * N;
    }
    if (N >= 200 && N < 300) {
        rate = 20.10;
        return rate * N;
    }
    if (N >= 300 && N < 500) {
        rate = 27.10;
        return rate * N;
    }
    if (N >= 500) {
        rate = 35.90;
        return rate * N;
    }
    return 0;
}

int main(int argc, char *argv[]) {
    double unitsconsumed = 0;
    int cusid = 0;
    string cusname = "";
    // For command-line argument Mode
    if (argc > 1) {
        if (argc < 3) {
            cout << "Error: Incomplete Input!" << endl;
            return 0;
        }
	
        cusid = atoi(argv[1]);
        unitsconsumed = atof(argv[argc - 1]);

        if (cusid <= 0 || unitsconsumed < 0) {
            cout << "Error: Invalid Input! Customer ID and Units Consumed must be positive values." << endl;
            return 1;
        }
		// Used to ensure if customers put 2 or more words for their name....
        for (int i = 2; i < argc - 1; i++) {
             cusname += argv[i];
                    if(i!=argc-2) {
                        cusname +=" ";
                }
			}
	}
	// For Interactive Input Mode
	else {
        cout << "\n--- Enter Customer Details ---" << endl;
        cout << "Customer ID: ";
        cin >> cusid;

        if (cusid <= 0) {
            cout << "Error: Invalid Input! Customer ID must be a positive number." << endl;
            return 1;
        }
		// Used to ignore newline buffer
        cin.ignore();

        cout << "Customer Name: ";
        getline(cin, cusname);

        cout << "Units Consumed: ";
        cin >> unitsconsumed;

        if (unitsconsumed < 0) {
            cout << "Error: Invalid Input! Units Consumed must be a non-negative value." << endl;
            return 1;
        }
    }

	//// Calculating Amount Charges and Surplus using unitcalculator function
    float ratePerUnit = 0;
    float AmountCharges = unitcalculator(unitsconsumed, ratePerUnit);
    float surplus = (AmountCharges > 18000) ? AmountCharges * 0.15 : 0;
    float netamount = AmountCharges + surplus;

    // Output
    cout << "\n--- Bill Summary ---" << endl;
    cout << fixed << setprecision(2);
    cout << "Customer ID        : " << cusid << endl;
    cout << "Customer Name      : " << cusname << endl;
    cout << "Units Consumed     : " << unitsconsumed << endl;
    cout << "Amount Charges     : $" << AmountCharges << " @ " << ratePerUnit << " per unit" << endl;
    cout << "Surplus            : $" << surplus << endl;
    cout << "Net Amount         : $" << netamount << endl;

    return 0;
}
