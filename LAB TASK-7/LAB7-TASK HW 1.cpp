#include <iostream>
using namespace std;

class Number {
private:
    int value;

public:
    Number(int val) : value(val) {}

    void display() const {
        cout << "Value: " << value << endl;
    }

    Number& operator--() { // Multiply by 4
        value *= 4;
        return *this;
    }

    Number operator--(int) { // Divide by 4
        Number temp = *this;
        value /= 4;
        return temp;
    }
};

int main() {
    Number num(8);
    cout << "Original: "<<endl;; num.display();
    
    --num;
    cout << "After Prefix --: "; num.display();
    
    num--;
    cout << "After Postfix --: "; num.display();
    
    return 0;
}
