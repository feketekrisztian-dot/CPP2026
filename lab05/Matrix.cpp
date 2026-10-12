//
// Created by fkris on 10/12/2026.
//

#include "Matrix.h"

#include <random>

Matrix::Matrix(int rows, int cols)
    : mRows{rows}, mCols {cols}
{
    this->mElements.resize(rows * cols);
}

Matrix::Matrix(const Matrix &other) {
    this->mRows = other.mRows;
    this->mCols = other.mCols;
    this->mElements.resize(this->mRows * this->mCols);
    this->mElements=other.mElements;
}

Matrix::Matrix(Matrix &&other) noexcept{
    this->mElements=std::move(other.mElements);
    this->mRows=other.mRows;
    this->mCols=other.mCols;
}

Matrix & Matrix::operator=(const Matrix &other) {
    if (this != &other) {
        this->mRows = other.mRows;
        this->mCols = other.mCols;
        this->mElements = other.mElements;
    }
    return *this;
}

Matrix & Matrix::operator=(Matrix &&other) noexcept {
    if (this != &other) {
        this->mElements=std::move(other.mElements);
        this->mRows=other.mRows;
        this->mCols=other.mCols;

    }
    return *this;
}

void Matrix::fillMatrix(double value) {
    this->mElements.assign(this->mRows * this->mCols, value);
}

void Matrix::randomMatrix(int a, int b) {
    std::random_device rd; // seed the random number generator named rd
    std::mt19937 mt(rd()); // Mersenne Twister algorithm to generate random numbers
    std::uniform_real_distribution<> dist(a, b); // return a number in the given range

    this->mElements.assign(this->mRows * this->mCols, 0);
    for( int i=0; i<this->mRows * this->mCols; ++i ){
        mElements[i] = dist(mt);
    }
}

void Matrix::printMatrix(std::ostream &os) const {
    for( int i=0; i<this->mRows; ++i ){
        for (int j=0; j<this->mCols; ++j )
            os<<this->mElements[i * mCols +j]<<" ";
        os<<std::endl;
    }
}



Matrix operator+(const Matrix &x, const Matrix &y) {
    if (x.getCols()!=y.getCols() || x.getRows()!=y.getRows()) {
        throw std::out_of_range("Rossz a matrix dimenzioja az osszeadashoz");
    }
    Matrix x1(x.mRows, x.mCols);
    for (int i=0;i<x.mElements.size();i++) {
        x1.mElements[i] = x.mElements[i] + y.mElements[i];
    }
    return x1;
}

Matrix operator*(const Matrix &x, const Matrix &y) {
    if (x.getCols()!=y.getRows()) {
        throw std::out_of_range("Rossz a matrix dimenzioja a szorzashoz");
    }
    Matrix x1(x.getRows(),y.getCols());
    for (int i=0;i<x1.getCols();++i)
        for (int j=0;j<x1.getRows();++j)
            for (int k=0;k<x.getCols();++k)
                x1(i,j) += x(i,k) * y(k,i);
    return x1;
}

std::istream & operator>>(std::istream &is, Matrix &mat) {
    is>>mat.mRows>>mat.mCols;
    for (int i=0;i<mat.mRows*mat.mCols;++i)
        is>>mat.mElements[i];
    return is;
}

std::ostream & operator<<(std::ostream &os, const Matrix &mat) {
    mat.printMatrix(os);
    return os;
}


double * Matrix::operator[](int row) {
    return mElements.data() + row*mCols;
}

const double * Matrix::operator[](int row) const {
    return mElements.data() + row*mCols;
}

double & Matrix::operator()(int row, int col) {
    if (row<0 || row>=this->mRows || col<0 || col>=this->mCols)
        throw std::out_of_range("Nincs ilyen index");
    return mElements.at(row*mCols+col);
}

const double & Matrix::operator()(int row, int col) const {
    if (row<0 || row>=this->mRows || col<0 || col>=this->mCols)
        throw std::out_of_range("Nincs ilyen index");
    return mElements.at(row*mCols+col);
}
