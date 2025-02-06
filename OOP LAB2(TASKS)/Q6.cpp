#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>

// ./output 101 Math Physics Chemistry Biology English 102 History Geography Economics Science Art
using namespace std;

struct Subject {
    string subject_name;
};

struct Student {
    int id;
    Subject subjects[5];
};

void AssignData(vector<Student>& students, int N, char* argv[], int argc) {
    if (argc > 1) {
        int argIndex = 1;
        for (int i = 0; i < N; i++) {
            if (argIndex >= argc) {
                cout << "Not enough command-line arguments for student " << i + 1 << endl;
                return;
            }
            students[i].id = atoi(argv[argIndex++]);
            for (int j = 0; j < 5; j++) {
                if (argIndex >= argc) {
                    cout << "Not enough command-line arguments for subjects of student " << i + 1 << endl;
                    return;
                }
                students[i].subjects[j].subject_name = argv[argIndex++];
            }
        }
    } else {
        for (int i = 0; i < N; i++) {
            cout << "Enter ID for student " << i + 1 << ": ";
            cin >> students[i].id;

            for (int j = 0; j < 5; j++) {
                cout << "Enter subject " << j + 1 << " for student " << i + 1 << ": ";
                cin.ignore();
                getline(cin, students[i].subjects[j].subject_name);
            }
        }
    }
}

int main(int argc, char* argv[]) {
    int N;

    if (argc > 1) {
        N = (argc - 1) / 6;  // As each student has 1 ID and 5 subjects
    } else {
        cout << "Enter number of students: ";
        cin >> N;
        if (N <= 0) {
            cout << "Invalid number of students!" << endl;
            return 1;
        }
    }

    vector<Student> students(N);

    AssignData(students, N, argv, argc);

    cout << "\nDisplaying student data:" << endl;
    for (int i = 0; i < N; i++) {
        cout << "Student ID: " << students[i].id << endl;
        for (int j = 0; j < 5; j++) {
            cout << "Subject " << j + 1 << ": " << students[i].subjects[j].subject_name << endl;
        }
    }

    return 0;
}
