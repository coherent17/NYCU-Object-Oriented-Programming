#ifndef _MATRIX_H_
#define _MATRIX_H_

#include <iostream>

using namespace std;

// Matrix.h
class Matrix {
   private:
    double** data;
    int row;
    int col;

   public:
    // Level 1
    // Constructors and destructor
    Matrix();                                  // Set row and col to 0, data to nullptr
    Matrix(int row, int col);                  // Create a zero matrix
    Matrix(int row, int col, double** arr2D);  // Copy from array
    Matrix(const Matrix& matrix);              // Copy from another matrix
    ~Matrix();                                 // Delete data

    // Setters and Getters
    // Set the value of the given row and col
    void setValue(int rowIdx, int colIdx, double value);
    // Get the value of the given row and col
    double getValue(int rowIdx, int colIdx) const;

    friend ostream& operator<<(ostream &, const Matrix &);
    // Transpose
    Matrix transpose()const;  // Return a new transposed matrix

    // Operator Overload
    Matrix operator+(const Matrix&);     //addition
    Matrix operator-(const Matrix&);

    Matrix operator+() const;              //positive
    Matrix operator-() const;

    void operator=(const Matrix&);
    Matrix& operator+=(const Matrix&);
    Matrix& operator-=(const Matrix&);

    bool operator==(const Matrix&) const;
    bool operator!=(const Matrix&) const;

    Matrix operator*(const Matrix&) const;    // Matrix and Matrix multiplication
    Matrix operator*(double) const;   // Matrix and double multiplication
    friend Matrix operator*(double c, const Matrix& M);// double and Matrix multiplication


    Matrix& operator*=(const Matrix&);
    Matrix& operator*=(double);


    // Level 3
    double determinant() const{
        return calculateDeterminant(data, row);
    } 

    private:
        double calculateDeterminant(double** mat, int n) const {
        // Base case: if matrix size is 1x1, return the single element as the determinant
        if (n == 1) {
            return mat[0][0];
        }

        double determinant = 0;

        // Loop through the first row of the matrix and recursively calculate the determinant
        // by expanding along the first row using cofactor expansion
        for (int i = 0; i < n; ++i) {
            double** submat = new double*[n - 1];
            for (int j = 0; j < n - 1; ++j) {
                submat[j] = new double[n - 1];
            }

            for (int j = 1; j < n; ++j) {
                int col = 0;
                for (int k = 0; k < n; ++k) {
                    if (k != i) {
                        submat[j - 1][col++] = mat[j][k];
                    }
                }
            }

            double cofactor = (i % 2 == 0 ? 1 : -1) * mat[0][i];
            determinant += cofactor * calculateDeterminant(submat, n - 1);

            for (int j = 0; j < n - 1; ++j) {
                delete[] submat[j];
            }
            delete[] submat;
        }

        return determinant;
    }
};

#endif