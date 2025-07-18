#include "../include/Array.hpp"

// orthodox cannonical form
template <typename T>
Array<T>::Array(): _size(0) {}

template <typename T>
Array<T>::Array(const Array &src) {
    *this = src;
}

template <typename T>
Array<T>& Array<T>::operator=(const Array<T> &src) {
    if (*this != src) {
        _size = src._size;
        delete(_array);
        _array = new T[_size];
        for (size_t i = 0; i < _size; i++)
            _array[i] = src._array[i];
    }
    return *this;
}

template <typename T>
Array<T>::~Array() {
    delete(_array);
}

// constructors
template <typename T>
Array<T>::Array(size_t n): _size(n) {
    _array = new T[n];
}

// operator
template <typename T>
int &Array<T>::operator[](int index) {
    if (index > 0 && index < _size)
        return _array[index];
    else
        throw Array<T>::OutOfBondException();
}

// function
template <typename T>
size_t Array<T>::size() const {
    return _size;
}

// exception
template <typename T>
 const char *Array<T>::OutOfBondException::what() const throw() {
    return "Error: the element accessed is out of bound\n";
 }