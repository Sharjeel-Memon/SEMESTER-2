#include <iostream>
#include <string>
#include <cstdlib>

// ./program "Linus" 127 2567.89 "FAST" 100567

using namespace std;

struct Employee {
    int employee_id;
    string employee_name;
    double employee_salary;
};

struct Organization {
    string organization_name;
    int organization_number;
    struct Employee emp;
};

int main(int argc, char *argv[]) {
    Organization Org;
    if (argc < 6) {
    	cout<<"Invalid Arguments!We Will Use Terminal for Input!"<<endl;
        // For Interactive Mode 
        cout << "====Employee Details====" << endl;
        cout << "Enter Employee Name: ";
        getline(cin, Org.emp.employee_name);
        cout << endl;

        cout << "Enter Employee Id: ";
        cin >> Org.emp.employee_id;
        cout << endl;

        cout << "Enter Employee Salary: ";
        cin >> Org.emp.employee_salary;
        cout << endl;
        cin.ignore();

        cout << "Enter Organization Name: ";
        getline(cin, Org.organization_name);
        cout << endl;

        cout << "Enter Organization Number: ";
        cin >> Org.organization_number;
        cout << endl;
    } else if (argc == 6) {
        // For Command-Line Argument Mode
        Org.emp.employee_name = argv[1];
        Org.emp.employee_id = atoi(argv[2]);
        Org.emp.employee_salary = stod(argv[3]);
        Org.organization_name = argv[4];
        Org.organization_number = atoi(argv[5]);
    } else {
        cout << "Invalid number of arguments. It should be equal to 6." << endl;
        return 1;
    }

    // Output
    cout << "====Employee Details====" << endl;
    cout << "Size of structure Organization: " << sizeof(Organization) << " bytes" << endl;
    cout << "Organization Name: " << Org.organization_name << endl;
    cout << "Organization Number: " << Org.organization_number << endl;
    cout << "Employee Id: " << Org.emp.employee_id << endl;
    cout << "Employee Name: " << Org.emp.employee_name << endl;
    cout << "Employee Salary: " << Org.emp.employee_salary << endl;

    return 0;
}
