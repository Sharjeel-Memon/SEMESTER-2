// ./6 row1 col1 row2 col2 elements elements elements ........
// ./6 2 2 2 2 1 2 3 4 5 6 7 8
#include <iostream>
#include <cstdlib>

using namespace std;

class Matrix {
private:
    int rows, cols;
    int mat[10][10];  // Fixed-size array

public:
    // Constructor
    Matrix(int r = 0, int c = 0) {
        this->rows = r;
        this->cols = c;
    }

    // Set element at position (i,j)
    void setElement(int i, int j, int value) {
        mat[i][j] = value;
    }

    // Get element at (i,j)
    int getElement(int i, int j) {
        return mat[i][j];
    }

    // Getters
    int getRows() { return rows; }
    int getCols() { return cols; }

    // Display Matrix
    void displayMatrix() {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                cout << mat[i][j] << " ";
            }
            cout << endl;
        }
    }

    // Add Matrices
    Matrix add(Matrix m) {
        if (rows != m.getRows() || cols != m.getCols()) {
            cout << "Matrices cannot be added (different dimensions)!" << endl;
            return Matrix();
        }
        
        Matrix result(rows, cols);
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                result.setElement(i, j, mat[i][j] + m.getElement(i, j));
            }
        }
        return result;
    }

    // Multiply Matrices
    Matrix multiply(Matrix m) {
        if (cols != m.getRows()) {
            cout << "Matrices cannot be multiplied (incompatible dimensions)!" << endl;
            return Matrix();
        }
        
        Matrix result(rows, m.getCols());
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < m.getCols(); j++) {
                int sum = 0;
                for (int k = 0; k < cols; k++) {
                    sum += mat[i][k] * m.getElement(k, j);
                }
                result.setElement(i, j, sum);
            }
        }
        return result;
    }
};

int main(int argc, char* argv[]) {
    if (argc < 5) {
        cout << "Not enough arguments! Provide matrix dimensions and elements." << endl;
        return 1;
    }

    int rows1 = atoi(argv[1]);
    int cols1 = atoi(argv[2]);
    int rows2 = atoi(argv[3]);
    int cols2 = atoi(argv[4]);

    if (argc < (5 + (rows1 * cols1) + (rows2 * cols2))) {
        cout << "Not enough elements provided!" << endl;
        return 1;
    }

    Matrix mat1(rows1, cols1);
    Matrix mat2(rows2, cols2);

    int index = 5;
    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols1; j++) {
            mat1.setElement(i, j, atoi(argv[index++]));
        }
    }

    for (int i = 0; i < rows2; i++) {
        for (int j = 0; j < cols2; j++) {
            mat2.setElement(i, j, atoi(argv[index++]));
        }
    }

    // Output
    cout << "\nMatrix 1:" << endl;
    mat1.displayMatrix();
    cout << "\nMatrix 2:" << endl;
    mat2.displayMatrix();

    if (rows1 == rows2 && cols1 == cols2) {
        cout << "\nSum of Matrices:" << endl;
        Matrix sum = mat1.add(mat2);
        sum.displayMatrix();
    } else {
        cout << "\nAddition not possible (different dimensions)." << endl;
    }

    if (cols1 == rows2) {
        cout << "\nProduct of Matrices:" << endl;
        Matrix product = mat1.multiply(mat2);
        product.displayMatrix();
    } else {
        cout << "\nMultiplication not possible (different dimensions)." << endl;
    }

    return 0;
}