#include <iostream>
#include <string>
using namespace std;

class Bus;

class Student {
    static int student_no;
    int id;
    string name;
    bool transport_card;
    string pick_up;
    Bus *assignedBus;
    int attendance[30];

public:
    Student() : id(0), transport_card(false), assignedBus(nullptr) {
        for (int &day : attendance) {
            day = 0;
        }
    }

    void payForTransportation() { transport_card = true; }
    
    void setValue() {
        cout << "\n--- Registering a New Student ---\n";
        cout << "Enter Student ID: ";
        cin >> id;
        cout << "Enter Student Name: ";
        cin >> name;
        cout << "Enter Your Pick-up Location: ";
        cin >> pick_up;
        cout << "Student Registered Successfully!\n";
    }
    
    void setBus(Bus &b) { assignedBus = &b; }
    
    int getId() const { return id; }
    bool hasTransportCard() const { return transport_card; }
    string getPickUp() const { return pick_up; }
    Bus *getBus() const { return assignedBus; }
    
    int getAttendance() const;
    void markAttendance();
    
    ~Student() {} // No need to delete assignedBus (aggregation)
};

class Bus {
    static int day;
    string *stops;
    int numberOfStops;

public:
    Bus() : stops(nullptr), numberOfStops(0) {}
    
    Bus(int size, string *ptr) : numberOfStops(size) {
        stops = new string[size];
        for (int i = 0; i < size; i++) {
            stops[i] = ptr[i];
        }
    }
    
    bool tapCard() { return true; }
    int getSize() const { return numberOfStops; }
    string *getStops() const { return stops; }
    
    void incrementDay() { day++; }
    int getDay() const { return day; }
    
    ~Bus() { delete[] stops; }
};

void Student::markAttendance() {
    if (assignedBus) {
        attendance[assignedBus->getDay()] = 1;
    }
}

int Student::getAttendance() const {
    return assignedBus ? attendance[assignedBus->getDay()] : 0;
}

int Bus::day = 0;

int main() {
    int total_students = 0;
    Student students[100]; // Fixed-size array to avoid dynamic allocation issues
    Bus buses[3];
    
    string r1[7] = {"University", "Hasan square", "Liaqtabad", "Nazimabad", "Johar more", "Dalmia", "Natha Khan"};
    string r2[7] = {"University", "Shaheedemillat", "Guru mandir", "Garden", "Tariq route", "Baloch pull", "Jamat Khana"};
    string r3[8] = {"University", "Korangi", "Landhi", "Akhtar colony", "Askari 3", "Kala pull", "Teen talwar", "Kpt bridge"};

    buses[0] = Bus(7, r1);
    buses[1] = Bus(7, r2);
    buses[2] = Bus(8, r3);

    int choice;
    while (true) {
        cout << "\n--- FAST Transport System ---\n";
        cout << "1. Register New Student\n";
        cout << "2. Mark Attendance\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            if (total_students < 100) {
                students[total_students].setValue();
                total_students++;
            } else {
                cout << "Error: Maximum student limit reached!\n";
            }
        } 
        else if (choice == 2) {
            cout << "Enter Student ID: ";
            int id;
            cin >> id;
            
            int i;
            for (i = 0; i < total_students; i++) {
                if (id == students[i].getId()) break;
            }

            if (i < total_students) {
                if (students[i].hasTransportCard()) {
                    int a;
                    cout << "Tap your transport card to mark attendance (Press any number): ";
                    cin >> a;
                    
                    if (!students[i].getAttendance()) {
                        buses[i % 3].incrementDay(); // Ensures days are updated
                    }
                    students[i].markAttendance();
                    cout << "Attendance Marked Successfully!\n";
                } else {
                    cout << "\nYour transport card is inactive. Please pay your transport fees.\n";
                    cout << "Enter '1' to Pay Now: ";
                    int pay;
                    cin >> pay;
                    
                    if (pay == 1) {
                        students[i].payForTransportation();
                        
                        bool assigned = false;
                        for (int k = 0; k < 3 && !assigned; k++) {
                            for (int j = 0; j < buses[k].getSize() && !assigned; j++) {
                                if (students[i].getPickUp() == buses[k].getStops()[j]) {
                                    students[i].setBus(buses[k]);
                                    assigned = true;
                                }
                            }
                        }
                        
                        if (assigned) {
                            cout << "Transport Card Activated! Bus Assigned Successfully.\n";
                        } else {
                            cout << "Error: Invalid Bus Stop Entered!\n";
                        }
                    }
                }
            } else {
                cout << "Error: Invalid Student ID! Please try again.\n";
            }
        } 
        else if (choice == 3) {
            cout << "Exiting... Thank you!\n";
            break;
        } 
        else {
            cout << "Invalid option! Please try again.\n";
        }
    }
    return 0;
}
