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
        cout << "Enter " << S << " Elements:" << endl;
        for (int i = 0; i < S; i++) {
            cout << "Element " << i + 1 << ": ";
            cin >> *(arr + i);
        }
    }
}

double CalculateSum(double *arr, int S) {
    double sum = 0;
    for (int i = 0; i < S; i++) {
        sum += *(arr + i);
    }
    return sum;
}

int main(int argc, char *argv[]) {
    int size = (argc > 1) ? argc - 1 : 0;  
    int flag = (argc < 2) ? 1 : 0;

    if (size == 0) {
        cout << "Enter the number of elements: ";
        cin >> size;
        if (size <= 0) {
            cout << "Invalid size!" << endl;
            return 1;
        }
    }

    double arr[size]; 
    AssignData(arr, size, flag, argv, argc);
	//Output
    cout << fixed << setprecision(2);
    cout << "The sum of elements is: " << CalculateSum(arr, size) << endl;

    return 0;
}
