#include <iostream>

using namespace std;

#include "matrix.h"

using namespace std;

// TODO:
TwoDimensionMatrix::TwoDimensionMatrix(){
    this->elements = new MatrixElement * [this->size];
    for(int i=0; i<this->size; i++) {
        this->elements[i] = new MatrixElement[this->size];
        for (int j = 0; j < this->size; j++)
            this->elements[i][j] = 0;
    }
}
TwoDimensionMatrix::TwoDimensionMatrix(const TwoDimensionMatrix &tdmatrix){
    this->elements = new MatrixElement * [this->size];
    for(int i=0; i<this->size; i++) {
        this->elements[i] = new MatrixElement[this->size];
        for (int j = 0; j < this->size; j++)
            this->elements[i][j] = tdmatrix.elements[i][j];
    }
}
TwoDimensionMatrix::TwoDimensionMatrix(const MatrixElement matrix[size][size]){
    this->elements = new MatrixElement * [this->size];
    for(int i=0; i<this->size; i++) {
        this->elements[i] = new MatrixElement[this->size];
        for (int j = 0; j < this->size; j++)
            this->elements[i][j] = matrix[i][j];
    }
}
ostream & operator << (ostream &os, const TwoDimensionMatrix &matrix){
    for(int i=0; i<matrix.getSize(); i++){
        for(int j=0; j<matrix.getSize(); j++)
            os<<matrix.elements[i][j]<<" ";
        os<<endl;
    }
    return os;
}

TwoDimensionMatrix operator+(const TwoDimensionMatrix &matrix1, const TwoDimensionMatrix &matrix2) {
    TwoDimensionMatrix result;
    for(int i=0; i<result.getSize(); i++){
        for(int j=0; j<result.getSize(); j++)
            result.elements[i][j]=matrix1.elements[i][j]+matrix2.elements[i][j];
    }
    return result;
}

TwoDimensionMatrix &TwoDimensionMatrix::operator*=(MatrixElement number) {
    for(int i=0; i<size; i++){
        for(int j=0; j<size; j++)
            this->elements[i][j]*=number;
    }
    return *this;
}

TwoDimensionMatrix TwoDimensionMatrix::operator&&(const TwoDimensionMatrix &matrix) const{
    for(int i=0; i<size; i++){
        for(int j=0; j<size; j++)
            this->elements[i][j]=this->elements[i][j] && matrix.get(i,j);
    }
    return *this;
}

MatrixElement *TwoDimensionMatrix::operator[](size_t i) {
    return this->elements[i];
}

TwoDimensionMatrix::operator size_t() const {
    const size_t result = static_cast<size_t>(this->getSize());
    return result;
}
