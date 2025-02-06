#include <iostream>
#include <cstdlib>

// ./1 5 10 10 10 10 10 8

using namespace std;

void* AddElements(void* arr, int size, int add_value) {
    int* int_arr = static_cast<int*>(arr);
    for (int i = 0; i < size; i++) {
        int_arr[i] += add_value;
    }
    return arr;
}

int main(int argc, char* argv[]) {
    if (argc < 4) {
        cout << "Insufficient arguments. Provide the array size, values, and the add value." << endl;
        return 1;
    }

    int size = atoi(argv[1]);  // First argument is the size
    if (size <= 0) {
        cout << "Invalid size!" << endl;
        return 1;
    }

    if (argc != size + 3) {
        cout << "Number of elements does not match the provided size!" << endl;
        return 1;
    }

    int add_value = atoi(argv[argc - 1]); // Last argument is the value to add

    int* arr = new int[size];

    for (int i = 0; i < size; i++) {
        arr[i] = atoi(argv[i + 2]); // Starting from the second argument to fill array
    }

    cout << "Original array: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    AddElements(arr, size, add_value);

    cout << "Modified array: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    delete[] arr;
    return 0;
}
