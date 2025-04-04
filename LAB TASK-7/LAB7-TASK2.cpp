#include <iostream>
using namespace std;

class Polynomial {
private:
    int coefficients[100]; // Fixed-size array
    int degree;

    void trim() {
        while (degree > 0 && coefficients[degree] == 0) {
            degree--;
        }
    }

public:
    Polynomial() : degree(0) {
        for (int i = 0; i < 100; i++) coefficients[i] = 0;
    }
    
    Polynomial(int coeffs[], int deg) : degree(deg) {
        for (int i = 0; i <= degree; i++) coefficients[i] = coeffs[i];
        for (int i = degree + 1; i < 100; i++) coefficients[i] = 0;
        trim();
    }

    friend ostream& operator<<(ostream& os, const Polynomial& p) {
        if (p.degree == 0 && p.coefficients[0] == 0) {
            os << "0";
            return os;
        }
        for (int i = p.degree; i >= 0; i--) {
            if (p.coefficients[i] != 0) {
                if (i != p.degree && p.coefficients[i] > 0) os << " + ";
                if (p.coefficients[i] < 0) os << " - ";
                if (abs(p.coefficients[i]) != 1 || i == 0) os << abs(p.coefficients[i]);
                if (i > 0) os << "x";
                if (i > 1) os << "^" << i;
            }
        }
        return os;
    }

    Polynomial operator+(const Polynomial& other) const {
        int maxDegree = max(degree, other.degree);
        int resultCoeffs[100] = {0};
        for (int i = 0; i <= maxDegree; i++) {
            resultCoeffs[i] = coefficients[i] + other.coefficients[i];
        }
        return Polynomial(resultCoeffs, maxDegree);
    }
    
    Polynomial operator-(const Polynomial& other) const {
        int maxDegree = max(degree, other.degree);
        int resultCoeffs[100] = {0};
        for (int i = 0; i <= maxDegree; i++) {
            resultCoeffs[i] = coefficients[i] - other.coefficients[i];
        }
        return Polynomial(resultCoeffs, maxDegree);
    }
    
    Polynomial operator*(const Polynomial& other) const {
        int resultCoeffs[100] = {0};
        int newDegree = degree + other.degree;
        for (int i = 0; i <= degree; i++) {
            for (int j = 0; j <= other.degree; j++) {
                resultCoeffs[i + j] += coefficients[i] * other.coefficients[j];
            }
        }
        return Polynomial(resultCoeffs, newDegree);
    }

    friend class PolynomialUtils;
};

class PolynomialUtils {
public:
    static int evaluate(const Polynomial& p, int x) {
        int result = 0, power = 1;
        for (int i = 0; i <= p.degree; i++) {
            result += p.coefficients[i] * power;
            power *= x;
        }
        return result;
    }
    
    static Polynomial derivative(const Polynomial& p) {
        if (p.degree == 0) return Polynomial();
        int derivCoeffs[100] = {0};
        for (int i = 1; i <= p.degree; i++) {
            derivCoeffs[i - 1] = p.coefficients[i] * i;
        }
        return Polynomial(derivCoeffs, p.degree - 1);
    }
};

int main() {
    int coeffs1[] = {3, 2, 1}; // 3 + 2x + x^2
    int coeffs2[] = {1, -1};   // 1 - x
    Polynomial p1(coeffs1, 2);
    Polynomial p2(coeffs2, 1);
    cout << "p1: " << p1 << endl;
    cout << "p2: " << p2 << endl;
    cout << "p1 + p2: " << (p1 + p2) << endl;
    cout << "p1 - p2: " << (p1 - p2) << endl;
    cout << "p1 * p2: " << (p1 * p2) << endl;
    cout << "p1 evaluated at x=2: " << PolynomialUtils::evaluate(p1, 2) << endl;
    cout << "Derivative of p1: " << PolynomialUtils::derivative(p1) << endl;
    return 0;
}
