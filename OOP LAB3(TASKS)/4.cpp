#include <iostream>
#include <string>
#include <cstdlib>

// ./4 Sharjeel Memon 2000 Waqas HS 2500

using namespace std;

class Employee {
    string firstName;
    string lastName;
    double salary;

public:
    void setFirstName(string firstName) {
        this->firstName = firstName;
    }

    void setLastName(string lastName) {
        this->lastName = lastName;
    }

    void setSalary(double salary) {
    	//Checking salary
        if (salary < 0) {
            this->salary = 0;
        } else {
            this->salary = salary;
        }
    }

    string getFirstName() {
    	//outputing first name
        return firstName;
    }

    string getLastName() {
    	//outputing last name
        return lastName; 
    }

    double getSalary() {
    	//outputing yearly salary
        return salary * 12;
    }

    void salaryRaise() {
	// Raising Salary by 10%
        salary *= 1.1; 
    }
};

int main(int argc, char* argv[]) {
    //Checking amount of arguments
	if (argc < 7) {
        cout << "Insufficient arguments. Please provide first name, last name, and salary for both employees." << endl;
        return 1; 
    }

    Employee staff[2];
    staff[0].setFirstName(argv[1]);
    staff[0].setLastName(argv[2]);
    staff[0].setSalary(stod(argv[3]));
    
    staff[1].setFirstName(argv[4]);
    staff[1].setLastName(argv[5]);
    staff[1].setSalary(stod(argv[6]));

    // Outputing Salaries before the raise
    cout << "The Salary of the First Staff (" << staff[0].getFirstName() << " " << staff[0].getLastName() << ") is: " << staff[0].getSalary() << endl;
    cout << "The Salary of the Second Staff (" << staff[1].getFirstName() << " " << staff[1].getLastName() << ") is: " << staff[1].getSalary() << endl;
	//Raising Salaries
    staff[0].salaryRaise();
    staff[1].salaryRaise();
	//Outputing Salaries after the raise
    cout << "After Raise, the Salaries are..." << endl;
    cout << "The Salary of the First Staff after raise is: " << staff[0].getSalary() << endl;
    cout << "The Salary of the Second Staff after raise is: " << staff[1].getSalary() << endl;
    
	return 0;
}
