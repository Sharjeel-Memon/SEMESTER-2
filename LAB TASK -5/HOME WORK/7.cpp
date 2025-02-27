#include <iostream>

using namespace std;

class Student {
private:
    const int roll_no;
public:
    // Constructor uses initialization list when using const attributes...
    Student(int roll) : roll_no(roll) {
        cout << "Student object created with Roll No: " << roll_no << endl;
    }
    
    void display() const {
        cout << "Student Roll No: " << roll_no << endl;
    }
};

int main() {
    int roll;
    //Taking input at run-time
    cout << "Enter student roll number: ";
    cin >> roll;
    Student s(roll);
    //Display
    s.display();
    
    return 0;
}
