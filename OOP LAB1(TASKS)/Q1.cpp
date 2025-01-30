#include <iostream>
#include <iomanip>

using namespace std;

void AssignData(double *arr, int S, int F, char* argv[], int argc) {
    if (F == 0) { 
	// Command-line Argument Mode
        for (int i = 1; i < argc; i++) {
            *(arr + i - 1) = atof(argv[i]);
        }
    } else { 
	// Interactive Input Mode
        cout << "Enter 20 Elements to find the Second Largest:" << endl;
        for (int i = 0; i < S; i++) {
            cout << "Element " << i + 1 << ": ";
            cin >> *(arr + i);
        }
    }
}

void BubbleSort(double *arr, int S) {
    for (int i = 0; i < S - 1; i++) {
        for (int j = 0; j < S - i - 1; j++) {
            if (*(arr + j) > *(arr + j + 1)) {
                double temp = *(arr + j);
                *(arr + j) = *(arr + j + 1);
                *(arr + j + 1) = temp;
            }
        }
    }
}

double SecondLargest(double *arr, int S) {
    BubbleSort(arr, S);
    return *(arr + S - 2);
}

int main(int argc, char *argv[]) {
    int size = 20;
    int flag = (argc < 2) ? 1 : 0;

    if (argc > 2 && argc < 21) {
        cout << "The amount of elements should be exactly 20." << endl;
        return 1;
    }

    double num[20];
    double *ptr = num;

    AssignData(ptr, size, flag, argv, argc);
	//Output
	cout << fixed << setprecision(5);
    cout << "The Second Largest Number is: " << SecondLargest(ptr, size) << endl;
    return 0;
}
