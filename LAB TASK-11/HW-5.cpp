#include <iostream>
#include <stdexcept>

// Custom exception
class StackUnderflowException : public std::exception {
public:
    const char* what() const noexcept override {
        return "Stack underflow: No elements in stack.";
    }
};

template<typename T>
class Stack {
private:
    T* data;
    int capacity;
    int topIndex;

    void resize() {
        int newCapacity = capacity * 2;
        T* newData = new T[newCapacity];
        for (int i = 0; i < topIndex; ++i)
            newData[i] = data[i];

        delete[] data;
        data = newData;
        capacity = newCapacity;
    }

public:
    Stack(int initialSize = 10) : capacity(initialSize), topIndex(0) {
        data = new T[capacity];
    }

    ~Stack() {
        delete[] data;
    }

    void push(const T& value) {
        if (topIndex == capacity)
            resize();
        data[topIndex++] = value;
    }

    void pop() {
        if (isEmpty())
            throw StackUnderflowException();
        --topIndex;
    }

    T top() const {
        if (isEmpty())
            throw StackUnderflowException();
        return data[topIndex - 1];
    }

    bool isEmpty() const {
        return topIndex == 0;
    }

    int size() const {
        return topIndex;
    }
};


nt main() {
    try {
        Stack<int> s;

        s.push(10);
        s.push(20);
        s.push(30);

        std::cout << "Top element: " << s.top() << "\n"; 
        s.pop();
        std::cout << "Top after pop: " << s.top() << "\n"; 

        while (!s.isEmpty()) {
            std::cout << "Popping: " << s.top() << "\n";
            s.pop();
        }

        s.pop();

    } catch (const StackUnderflowException& e) {
        std::cerr << "Caught exception: " << e.what() << "\n";
    }

    return 0;
}