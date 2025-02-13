#include <iostream>
#include <cstdlib>

// ./2 11 9 2003

using namespace std;

class Date {
    int month;
    int day;
    int year;

public:
    // Parameterized Constructor
    Date(int month, int day, int year) {
        if (month < 1 || month > 12) {
        	//Checking Month
            cout << "Invalid month!" << endl;
            exit(1);
        }
        if (day < 1 || day > 31) {
        	//Checking Date
            cout << "Invalid day!" << endl;
            exit(1);
        }
        if (year < 1) {
        	//Checking Year
            cout << "Invalid year!" << endl;
            exit(1);
        }

        //Checking Leap year for February month....
        if (month == 2) {
        	//bool or if-else??
            bool isLeap = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
            //correct condition?
            if (day > 29 || (day == 29 && !isLeap)) {
                cout << "Invalid day for February!" << endl;
                exit(1);
            }
        }

        //Month with 30 days...
        if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30) {
            cout << "Invalid day for the given month!" << endl;
            exit(1);
        }
		//this keyword let u use the same name of the object as the parameter
        this->month = month;
        this->day = day;
        this->year = year;
    }

    //Display function
    void displayDate() {
        cout << "The given date is: " << month << "/" << day << "/" << year << endl;
    }
};

int main(int argc, char* argv[]) {
    if (argc != 4) {  
	//Checking number of arguments
        cout << "Invalid amount of arguments!" << endl;
        return 1;
    }
    
    // Creating Object....
    Date myDate(atoi(argv[1]), atoi(argv[2]), atoi(argv[3]));
    
    //Output
    myDate.displayDate();

    return 0;
}
