#include <iostream>
#include <cstdlib>

// ./program 10 10 10 10 10 10 10

using namespace std;

void resizeArray(int*& arr, int& current_size) {
    int* new_arr = new int[current_size * 2];  // Double the size
    for (int i = 0; i < current_size; i++) {
        new_arr[i] = arr[i];
    }
    delete[] arr;
    arr = new_arr;
    current_size *= 2;
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        cout << "Please provide at least one element as a command-line argument!" << endl;
        return 1;
    }

    int initial_size = 5;  // Start with an array of size 5
    int* arr = new int[initial_size];
    int current_size = initial_size;
    int count = 0;

    // command-line arguments
    for (int i = 1; i < argc; i++) {
        if (count == current_size) {
            // Resize if count exceeds current size
            resizeArray(arr, current_size);
        }
        arr[count] = atoi(argv[i]);  // Converting
        count++;
    }

    // Output the final array
    cout << "Final array elements: ";
    for (int i = 0; i < count; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    delete[] arr;
    return 0;
}
