#include <iostream>
#include <array>
#include<math.h>

using namespace std;

class Matrix3D {
private:
    array<array<double, 3>, 3> matrix;
    int increment;
    int count;

public:
    Matrix3D(const array<array<double, 3>, 3>& mat, int inc = 1)
        : matrix(mat), increment(inc < 0 ? 1 : inc), count(0) {}

    ~Matrix3D() {}

    double det() const {
        return matrix[0][0] * (matrix[1][1] * matrix[2][2] - matrix[2][1] * matrix[1][2]) -
               matrix[0][1] * (matrix[1][0] * matrix[2][2] - matrix[1][2] * matrix[2][0]) +
               matrix[0][2] * (matrix[1][0] * matrix[2][1] - matrix[1][1] * matrix[2][0]);
    }

    Matrix3D inverse() const {
        double determinant = det();
        if (determinant == 0) {
            return Matrix3D({{{0, 0, 0}, {0, 0, 0}, {0, 0, 0}}}, -1);
        }

        array<array<double, 3>, 3>  invMatrix;
        invMatrix[0][0] = (matrix[1][1] * matrix[2][2] - matrix[1][2] * matrix[2][1]) / determinant;
        invMatrix[0][1] = (matrix[0][2] * matrix[2][1] - matrix[0][1] * matrix[2][2]) / determinant;
        invMatrix[0][2] = (matrix[0][1] * matrix[1][2] - matrix[0][2] * matrix[1][1]) / determinant;
        invMatrix[1][0] = (matrix[1][2] * matrix[2][0] - matrix[1][0] * matrix[2][2]) / determinant;
        invMatrix[1][1] = (matrix[0][0] * matrix[2][2] - matrix[0][2] * matrix[2][0]) / determinant;
        invMatrix[1][2] = (matrix[0][2] * matrix[1][0] - matrix[0][0] * matrix[1][2]) / determinant;
        invMatrix[2][0] = (matrix[1][0] * matrix[2][1] - matrix[1][1] * matrix[2][0]) / determinant;
        invMatrix[2][1] = (matrix[0][1] * matrix[2][0] - matrix[0][0] * matrix[2][1]) / determinant;
        invMatrix[2][2] = (matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0]) / determinant;

        return invMatrix;
    }


    void setIncrement(int val) {
        if (count == 0) {
            if (val >= 0) {
                increment = val;
            }
        } else {
            cout << "Cannot set the increment step." <<endl;
        }
    }

    array<array<double, 3>, 3> getMatrix() const {
        return matrix;
    }


    void incrementMatrix() {
        for (auto& row : matrix) {
            for (auto& elem : row) {
                elem += increment;
            }
        }
        count++;
    }

    Matrix3D operator+(const Matrix3D& other) const {
        Matrix3D result = *this;
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                result.matrix[i][j] += other.matrix[i][j];
            }
        }
        return result;
    }

    Matrix3D operator-(const Matrix3D& other) const {
        Matrix3D result = *this;
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                result.matrix[i][j] -= other.matrix[i][j];
            }
        }
        return result;
    }

    Matrix3D operator*(const Matrix3D& other) const {
        Matrix3D result = {{{0}}};
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                for (int k = 0; k < 3; ++k) {
                    result.matrix[i][j] += matrix[i][k] * other.matrix[k][j];
                }
            }
        }
        return result;
    }


    bool operator>(const Matrix3D& other) const {
        return det() > other.det();
    }

    bool operator<(const Matrix3D& other) const {
        return det() < other.det();
    }

    bool operator>=(const Matrix3D& other) const {
        return det() >= other.det();
    }

    bool operator<=(const Matrix3D& other) const {
        return det() <= other.det();
    }

    bool operator==(const Matrix3D& other) const {
        return det() == other.det();
    }

    bool operator!=(const Matrix3D& other) const {
        return det() != other.det();
    }

    void display() const {
        for (const auto& row : matrix) {
            for (const auto& elem : row) {
                cout << elem << " ";
            }
            cout << endl;
        }
    }
};


int main() {
    Matrix3D mat1({{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}}}, 2);
    Matrix3D mat2({{{2, 4, 1}, {6, 5, 9}, {8, 3, 7}}}, 2);

    mat1.incrementMatrix();
    mat2.incrementMatrix();

    cout << "Matrix 1:\n";
    mat1.display();
    cout << "Matrix 2:\n";
    mat2.display();

    Matrix3D result = mat1 + mat2;
    cout << "Result of Addition:\n";
    result.display();

    result = mat1 - mat2;
    cout << "Result of subtraction:\n";
    result.display();

    result = mat1 * mat2;
    cout << "Result of Multiplication:\n";
    result.display();

    if(mat1.det()>mat2.det()){
        cout<<"The higher magnitude matrix:\n";
        mat1.display();
    }
    else
        cout<<"The higher magnitude matrix:\n";
        mat2.display();

    return 0;
}
