#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>

//./program 105 "Anna Smith" 103 "Mike Jordan" 102 "John Doe" 104 "Alice Brown" 101 "James White"

using namespace std;

struct Student {
    int id;
    string name;
};

void sortStudents(vector<Student>& students) {
    for (size_t i = 0; i < students.size(); i++) {
        for (size_t j = i + 1; j < students.size(); j++) {
            if (students[i].id > students[j].id) {
                swap(students[i], students[j]);
            }
            else if (students[i].id == students[j].id) {
                if (students[i].name[0] > students[j].name[0]) {
                    swap(students[i], students[j]);
                }
            }
        }
    }
}

int main(int argc, char *argv[]) {
    int N = (argc - 1) / 2;
    vector<Student> students(N);

    int argIndex = 1;
    for (int i = 0; i < N; i++) {
        students[i].id = atoi(argv[argIndex++]);
        students[i].name = argv[argIndex++];
    }

    cout << "Before Sorting:" << endl;
    for (const auto& student : students) {
        cout << "ID: " << student.id << ", Name: " << student.name << endl;
    }

    sortStudents(students);

    cout << "\nAfter Sorting:" << endl;
    for (const auto& student : students) {
        cout << "ID: " << student.id << ", Name: " << student.name << endl;
    }

    return 0;
}
