#include <stdexcept>
#include <iostream>
#include "vector.h"


Vector::Vector(int capacity): _size(0), _capacity(capacity) {
    this->data = (Fraction*) malloc(capacity * sizeof(Fraction));
}

Vector::Vector(const Vector &v): _capacity(v._capacity), _size(v._size) {
    this->data = (Fraction*) malloc(  v._capacity * sizeof(Fraction));

    for(int i=0; i<this->_capacity; i++)
        this->data[i] = v.data[i];

}

Vector::Vector(Vector &&v): data(v.data), _capacity(v._capacity), _size(v._size) {
    v.data = NULL;
    v._capacity = 0;
    v._size = 0;
}

Vector& Vector::operator=(const Vector &v) {
    if (this != &v) {
        this->data = (Fraction*) realloc(  this->data, v._capacity * sizeof(Fraction));
        this->_capacity = v._capacity;
        this->_size = v._size;

        for(int i=0; i<this->_capacity; i++)
            this->data[i] = v.data[i];
    }
    return *this;
}

Vector& Vector::operator=(Vector &&v) {
    if(this != &v) {
        delete[] this->data;
        this->data = v.data;
        this->_capacity = v._capacity;
        this->_size = v._size;
        v.data = NULL;
        v._capacity = 0;
        v._size = 0;
    }

    return *this;
}

void Vector::push_back(Fraction fraction) {
    if(this->_capacity==this->_size) {
        this->_capacity++;
        this->data = (Fraction *) realloc(this->data, this->_capacity * sizeof(Fraction));
    }
    this->data[this->_size++] = fraction;
}

Fraction Vector::operator[](size_t index) const{
    if(index<0 || index>=this->_capacity)
        throw(std::out_of_range("Niepoprawny index"));

    return this->data[index];
}


