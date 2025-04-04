#include <iostream>
using namespace std;

class BigInteger {
private:
    string value;
    bool isNegative;

    void removeLeadingZeros() {
        size_t nonZero = 0;
        while (nonZero < value.size() && value[nonZero] == '0') {
            nonZero++;
        }
        value = (nonZero == value.size()) ? "0" : value.substr(nonZero);
    }

public:
    BigInteger(string num) {
        isNegative = (num[0] == '-');
        value = isNegative ? num.substr(1) : num;
        removeLeadingZeros();
    }

    friend ostream& operator<<(ostream& os, const BigInteger& num) {
        if (num.isNegative && num.value != "0") os << "-";
        os << num.value;
        return os;
    }

    BigInteger operator+(const BigInteger& other) const {
        if (isNegative == other.isNegative) {
            BigInteger result = addMagnitude(*this, other);
            result.isNegative = isNegative;
            return result;
        }
        return isNegative ? other.subtractMagnitude(other, *this) : subtractMagnitude(*this, other);
    }

private:
    static BigInteger addMagnitude(const BigInteger& a, const BigInteger& b) {
        string result = "";
        int carry = 0, sum;
        int i = a.value.size() - 1, j = b.value.size() - 1;
        while (i >= 0 || j >= 0 || carry) {
            sum = carry + (i >= 0 ? a.value[i--] - '0' : 0) + (j >= 0 ? b.value[j--] - '0' : 0);
            result = char(sum % 10 + '0') + result;
            carry = sum / 10;
        }
        return BigInteger(result);
    }

    static BigInteger subtractMagnitude(const BigInteger& a, const BigInteger& b) {
        string result = "";
        int borrow = 0, diff;
        int i = a.value.size() - 1, j = b.value.size() - 1;
        while (i >= 0) {
            diff = (a.value[i] - '0') - borrow - (j >= 0 ? b.value[j] - '0' : 0);
            borrow = (diff < 0);
            if (borrow) diff += 10;
            result = char(diff + '0') + result;
            i--; j--;
        }
        BigInteger res(result);
        res.removeLeadingZeros();
        return res;
    }
};

int main() {
    BigInteger num1("12345678901234567890");
    BigInteger num2("98765432109876543210");
    cout << "Sum: " << (num1 + num2) << endl;
    return 0;
}
