#include "Matrix.h"
#include <iostream>
#include <vector>

using namespace std;

Matrix::Matrix(){
    row = 0;
    col = 0;
    data = nullptr;
}

Matrix::Matrix(int row, int col){
    this->row = row;
    this->col = col;
    data = new double *[row];
    for(int i = 0; i < row; i++){
        data[i] = new double[col];
    }
    
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            data[i][j] = 0;
        }
    }
}

Matrix::Matrix(int row, int col, double** arr2D){
    this->row = row;
    this->col = col;

    data = new double *[row];
    for(int i = 0; i < row; i++){
        data[i] = new double[col];
    }

    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            data[i][j] = arr2D[i][j];
        }
    }
}

Matrix::Matrix(const Matrix& matrix){
    row = matrix.row;
    col = matrix.col;

    data = new double *[row];
    for(int i = 0; i < row; i++){
        data[i] = new double[col];
    }

    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            this->data[i][j] = matrix.data[i][j];
        }
    }
}

Matrix::~Matrix(){
    for(int i = 0; i < row; i++){
        delete []data[i];
    }
    delete []data;
    data = nullptr;
}

void Matrix::setValue(int rowIdx, int colIdx, double value){
    data[rowIdx][colIdx] = value;
}

double Matrix::getValue(int rowIdx, int colIdx) const{
    return data[rowIdx][colIdx];
}

Matrix Matrix::transpose()const{
    Matrix ret(col, row);

    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            ret.data[j][i] = data[i][j];
        }
    }

    return ret;
}

ostream& operator<<(ostream & out, const Matrix & M){
    for(int i = 0; i < M.row; i++){
        for(int j = 0; j < M.col; j++){
            out << M.data[i][j] << " ";
        }
        out << endl;
    }
    return out;
}

//addition
Matrix Matrix::operator+(const Matrix& M){
    Matrix ret(row, col, data);

    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            ret.data[i][j] += M.data[i][j];
        }
    }

    return ret;
}

Matrix Matrix::operator-(const Matrix& M){
    Matrix ret(row, col, data);

    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            ret.data[i][j] -= M.data[i][j];
        }
    }

    return ret;
}

Matrix Matrix::operator+() const{
    Matrix ret(row, col);

    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            ret.data[i][j] = data[i][j];
        }
    }

    return ret;
}

Matrix Matrix::operator-() const{
    Matrix ret(row, col);

    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            ret.data[i][j] = -data[i][j];
        }
    }

    return ret;
}

void Matrix::operator=(const Matrix& M){
    if(data != nullptr){
        for(int i = 0; i < row; i++){
            delete[] data[i];
        }
        delete []data;
    }

    row = M.row;
    col = M.col;

    data = new double *[row];
    for(int i = 0; i < row; i++){
        data[i] = new double[col];
    }
    
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            data[i][j] = M.data[i][j];
        }
    }
}

Matrix& Matrix::operator+=(const Matrix& M){
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            data[i][j] += M.data[i][j];
        }
    }

    return *this;
}

Matrix& Matrix::operator-=(const Matrix& M){
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            data[i][j] -= M.data[i][j];
        }
    }
    return *this;
}

bool Matrix::operator==(const Matrix& M) const{
    if(row != M.row || col != M.col) return false;
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            if(data[i][j] != M.data[i][j]) return false;
        }
    }
    return true;
}

bool Matrix::operator!=(const Matrix& M) const{
    if(row != M.row || col != M.col) return true;
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            if(data[i][j] != M.data[i][j]) return true;
        }
    }
    return false;
}

Matrix Matrix::operator*(const Matrix& M) const{
    Matrix ret = Matrix(row, M.col);

    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < M.col; ++j) {
            for (int k = 0; k < col; ++k) {
                ret.data[i][j] += data[i][k] * M.data[k][j];
            }
        }
    }

    return ret;
}

Matrix Matrix::operator*(double c) const{
    Matrix ret = Matrix(row, col);

    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            ret.data[i][j] = data[i][j] * c;
        }
    }

    return ret;
}

Matrix operator*(double c, const Matrix& M){
    Matrix ret(M.row, M.col); 
    for (int i = 0; i < M.row; ++i) {
        for (int j = 0; j < M.col; ++j) {
            ret.data[i][j] = c * M.data[i][j];
        }
    }
    return ret;
}

Matrix& Matrix::operator*=(const Matrix& M){

    Matrix ret(row, M.col); // Create a new matrix to store the result
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < M.col; ++j) {
            for (int k = 0; k < col; ++k) {
                ret.data[i][j] += data[i][k] * M.data[k][j]; // Perform matrix multiplication
            }
        }
    }
    
    *this = ret;
    return *this;
}

Matrix& Matrix::operator*=(double c){
    Matrix ret(row, col); // Create a new matrix to store the result
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            ret.data[i][j] += data[i][j] * c; // Perform matrix multiplication
        }
    }
    
    *this = ret;
    return *this;
}