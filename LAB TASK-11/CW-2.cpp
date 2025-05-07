#include <iostream>
#include <stdexcept>

class DimensionMismatchException : public std::exception {
public:
    const char* what() const noexcept override {
        return "Matrix dimensions mismatch.";
    }
};

template<typename T>
class Matrix {
private:
    int rows, cols;
    T** data;

public:
    Matrix(int r, int c, T init = T()) : rows(r), cols(c) {
        data = new T*[rows];
        for (int i = 0; i < rows; ++i) {
            data[i] = new T[cols];
            for (int j = 0; j < cols; ++j)
                data[i][j] = init;
        }
    }

    // Copy constructor
    Matrix(const Matrix<T>& other) : rows(other.rows), cols(other.cols) {
        data = new T*[rows];
        for (int i = 0; i < rows; ++i) {
            data[i] = new T[cols];
            for (int j = 0; j < cols; ++j)
                data[i][j] = other.data[i][j];
        }
    }

    // Destructor
    ~Matrix() {
        for (int i = 0; i < rows; ++i)
            delete[] data[i];
        delete[] data;
    }

    T& at(int r, int c) {
        if (r < 0 || r >= rows || c < 0 || c >= cols)
            throw std::out_of_range("Index out of bounds.");
        return data[r][c];
    }

    const T& at(int r, int c) const {
        if (r < 0 || r >= rows || c < 0 || c >= cols)
            throw std::out_of_range("Index out of bounds.");
        return data[r][c];
    }

    Matrix<T> operator+(const Matrix<T>& other) const {
        if (rows != other.rows || cols != other.cols)
            throw DimensionMismatchException();

        Matrix<T> result(rows, cols);
        for (int i = 0; i < rows; ++i)
            for (int j = 0; j < cols; ++j)
                result.data[i][j] = data[i][j] + other.data[i][j];
        return result;
    }

    Matrix<T> operator*(const Matrix<T>& other) const {
        if (cols != other.rows)
            throw DimensionMismatchException();

        Matrix<T> result(rows, other.cols, T());
        for (int i = 0; i < rows; ++i)
            for (int j = 0; j < other.cols; ++j)
                for (int k = 0; k < cols; ++k)
                    result.data[i][j] += data[i][k] * other.data[k][j];
        return result;
    }

    void print() const {
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j)
                std::cout << data[i][j] << " ";
            std::cout << "\n";
        }
    }
};

int main() {
    try {
        Matrix<int> A(2, 2, 1);
        Matrix<int> B(2, 2, 2);

        Matrix<int> C = A + B;
        std::cout << "Matrix A + B:\n";
        C.print();

        Matrix<int> D(2, 3, 1);
        Matrix<int> E(3, 2, 2);
        Matrix<int> F = D * E;
        std::cout << "Matrix D * E:\n";
        F.print();

    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << "\n";
    }

    return 0;
}
