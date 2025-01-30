#include <iostream>
#include <string>


using namespace std;

int main(int argc, char *argv[]) {
    // ATTRIBUTES
    string name = "";
    double marks[5] = {0, 0, 0, 0, 0};
    double sum = 0;

    if (argc < 7) {
        // FOR INTERACTIVE MODE
        cout << "Input your name: ";
        getline(cin, name);
        cout << "==== Now enter marks for your 5 subjects ====" << endl;
        for (int i = 0; i < 5; i++) {
            cout << "Enter marks for Subject " << i + 1 << ": ";
            cin >> marks[i];
            sum += marks[i];
        }
    }
    else {
        // FOR COMMAND-LINE ARGUMENT
        
        for (int i = 1; i < argc - 5; i++) {
            name += argv[i];
            if (i != argc - 6) name += " "; // Adds space between words in name
        }

      
        for (int i = 0; i < 5; i++) {
            marks[i] = atof(argv[argc - 5 + i]);
            sum += marks[i];
        }
    }

    // CALCULATING AVERAGE
    double avg = sum / 5;

    // OUTPUT
    cout << "Student Details!" << endl;
    cout << "Student Name: " << name << endl;
    cout << "Test Scores: ";
    for (int i = 0; i < 5; i++) {
        cout << marks[i] << " ";
    }
    cout << endl;
    cout << "Average Test Score: " << avg << endl;

    return 0;
}
