#include <iostream>
using namespace std;

class Fraction {
private:
    int numerator, denominator;
    
    void reduce() {
        int a = abs(numerator), b = abs(denominator);
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        int gcd = a;
        numerator /= gcd;
        denominator /= gcd;
        if (denominator < 0) { // Ensure denominator is always positive
            numerator = -numerator;
            denominator = -denominator;
        }
    }

public:
    Fraction(int num = 0, int den = 1) : numerator(num), denominator(den) {
        if (denominator == 0) {
            cerr << "Error: Denominator cannot be zero!" << endl;
            exit(1);
        }
        reduce();
    }
    
    friend ostream& operator<<(ostream& os, const Fraction& f) {
        os << f.numerator << "/" << f.denominator;
        return os;
    }
    
    friend istream& operator>>(istream& is, Fraction& f) {
        is >> f.numerator >> f.denominator;
        if (f.denominator == 0) {
            cerr << "Error: Denominator cannot be zero!" << endl;
            exit(1);
        }
        f.reduce();
        return is;
    }
    
    Fraction operator+(const Fraction& other) const {
        return Fraction(numerator * other.denominator + other.numerator * denominator,
                        denominator * other.denominator);
    }
    
    Fraction operator-(const Fraction& other) const {
        return Fraction(numerator * other.denominator - other.numerator * denominator,
                        denominator * other.denominator);
    }
    
    Fraction operator*(const Fraction& other) const {
        return Fraction(numerator * other.numerator, denominator * other.denominator);
    }
    
    Fraction operator/(const Fraction& other) const {
        return Fraction(numerator * other.denominator, denominator * other.numerator);
    }
    
    bool operator==(const Fraction& other) const {
        return numerator == other.numerator && denominator == other.denominator;
    }
    
    bool operator!=(const Fraction& other) const {
        return !(*this == other);
    }
    
    bool operator<(const Fraction& other) const {
        return numerator * other.denominator < other.numerator * denominator;
    }
    
    bool operator>(const Fraction& other) const {
        return numerator * other.denominator > other.numerator * denominator;
    }
    
    bool operator<=(const Fraction& other) const {
        return !(*this > other);
    }
    
    bool operator>=(const Fraction& other) const {
        return !(*this < other);
    }
};

int main() {
    Fraction f1(5, 7), f2(2, 9);
    cout << (f1 + f2) << endl; 
    return 0;
}
