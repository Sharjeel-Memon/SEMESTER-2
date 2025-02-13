#include <iostream>
#include <string>
#include <cstdlib>

// ./3 1 50 1 70 2 1 80 3

using namespace std;

class Glass {
public:
    int LiquidLevel;

    // Constructor
    Glass() {
        LiquidLevel = 200;
    }

    // Drink method
    void Drink(int x) {
        if (x < 0) {
            cout << "Invalid Amount!" << endl;
        } else if (LiquidLevel >= x) {
            LiquidLevel -= x;
            cout << "Remaining liquid: " << LiquidLevel << " ml" << endl;
        } else {
            cout << "Not enough liquid! Please refill." << endl;
        }
        // Refilling automatically if below 100....
        if (LiquidLevel < 100) {
            Refill();
        }
    }

    // Refill method
    void Refill() {
		if(LiquidLevel==200){
    	cout<<"Its Already Full!."<<endl;
	}
		else {
        LiquidLevel = 200;
        cout << "Glass refilled to 200 ml!" << endl;
    	}
   }
};

int main(int argc, char* argv[]) {
	Glass water;
    int choice = 0;
    int amount = 0;

    //command-line arguments mode
    if (argc > 1) {
        for (int i = 1; i < argc; i++) {
            choice = atoi(argv[i]); 
            
            switch (choice) {
                case 1:
                    if (i + 1 < argc) {
                        amount = atoi(argv[++i]);
                        water.Drink(amount);
                    } else {
                        cout << "Please provide the amount to drink!" << endl;
                        return 1;
                    }
                    break;
                case 2:
                    water.Refill();
                    break;
                case 3:
                    cout << "Exiting program..." << endl;
                    return 0;
                default:
                    cout << "Invalid choice, please try again!" << endl;
                    return 1;
            }
        }
    }
    // Interactive mode
    else {
        while (choice != 3) {
            //Options
            cout << "\n1. Drink" << endl;
            cout << "2. Refill" << endl;
            cout << "3. Exit" << endl;
            cout << "Enter your choice: ";
            cin >> choice;

            switch (choice) {
                case 1:
                    // Calling Drink method
                    cout << "Enter the amount to drink (in ml): ";
                    cin >> amount;
                    water.Drink(amount);
                    break;
                case 2:
                    // Calling Refill method
                    water.Refill();
                    break;
                case 3:
                    cout << "Exiting program..." << endl;
                    return 0;
                default:
                    cout << "Invalid choice, please try again!" << endl;
            }
        }
    }

    return 0;
}
