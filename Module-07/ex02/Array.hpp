#pragma once

template<typename T>
class Array {
public:
    Array();
    Array(unsigned int );
    Array(const Array& copy);
    ~Array();
    Array &operator=(const Array& copy);
    T &operator[](const int location);
    unsigned int size() const;
private:
    T *mArray;
    unsigned int _size;
};

#include "Array.tpp"
