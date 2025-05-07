#include <iostream>
#include <exception>

class ArrayIndexOutOfBounds : public std::exception {
public:
    const char* what() const noexcept override {
        return "Array index out of bounds.";
    }
};

template<typename T>
class SafeArray {
    T* arr;
    int size;

public:
    SafeArray(int s) : size(s) {
        arr = new T[size];
    }

    ~SafeArray() {
        delete[] arr;
    }

    T& operator[](int index) {
        if (index < 0 || index >= size)
            throw ArrayIndexOutOfBounds();
        return arr[index];
    }

    int getSize() const {
        return size;
    }
};

int main() {
    try {
        SafeArray<int> sa(5);
        sa[2] = 10;
        std::cout << "Element at index 2: " << sa[2] << "\n";
        std::cout << "Accessing out of bounds: " << sa[10] << "\n";
    } catch (const std::exception& e) {
        std::cerr << "Caught: " << e.what() << "\n";
    }
    return 0;
}
