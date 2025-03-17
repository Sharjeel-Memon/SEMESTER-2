#include <iostream>
#include <string>

using namespace std;

// Base class: Student
class Student {
protected:
    int id;
    string name;

public:
    Student(int i, string n) : id(i), name(n) {}

    void displayStudentDetails() {
        cout << "Student ID: " << id << "\n";
        cout << "Student Name: " << name << "\n";
    }
};

// Derived class: Marks
class Marks : public Student {
protected:
    int marks_oop, marks_pf, marks_ds, marks_db;

public:
    Marks(int i, string n, int oop, int pf, int ds, int db) 
        : Student(i, n), marks_oop(oop), marks_pf(pf), marks_ds(ds), marks_db(db) {}

    void displayMarks() {
        cout << "Marks Obtained:\n";
        cout << "OOP: " << marks_oop << "\n";
        cout << "PF: " << marks_pf << "\n";
        cout << "DS: " << marks_ds << "\n";
        cout << "DB: " << marks_db << "\n";
    }
};

// Derived class: Result
class Result : public Marks {
public:
    Result(int i, string n, int oop, int pf, int ds, int db) 
        : Marks(i, n, oop, pf, ds, db) {}

    int calculateTotalMarks() {
        return marks_oop + marks_pf + marks_ds + marks_db;
    }

    double calculateAverageMarks() {
        return calculateTotalMarks() / 4.0;
    }

    void displayResult() {
        cout << "Total Marks: " << calculateTotalMarks() << "\n";
        cout << "Average Marks: " << calculateAverageMarks() << "\n";
    }
};

int main() {
    // Creating an object of Result class
    Result student1(101, "Sharjeel M.", 85, 90, 78, 88);
    
    // Displaying student details
    cout << "---- Student Details ----\n";
    student1.displayStudentDetails();
    
    // Displaying marks
    cout << "\n---- Marks Details ----\n";
    student1.displayMarks();
    
    // Displaying total and average marks
    cout << "\n---- Result ----\n";
    student1.displayResult();
    
    return 0;
}
