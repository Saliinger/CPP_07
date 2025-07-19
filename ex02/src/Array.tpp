#include "../include/Array.hpp"

// orthodox cannonical form
template <typename T>
Array<T>::Array() : _size(0), _array(NULL) {}

template <typename T>
Array<T>::Array(const Array &src) {
  _size = src._size;
  _array = new T[_size];
  for (unsigned int i = 0; i < _size; i++) _array[i] = src._array[i];
}

template <typename T>
Array<T> &Array<T>::operator=(const Array<T> &src) {
  if (this != &src) {
    _size = src._size;
    if (_array) delete[] _array;
    _array = new T[_size];
    for (unsigned int i = 0; i < _size; i++) _array[i] = src._array[i];
  }
  return *this;
}

template <typename T>
Array<T>::~Array() {
  if (_array) delete[] _array;
}

// constructors
template <typename T>
Array<T>::Array(unsigned int n) : _size(n) {
  _array = new T[n]();
}

// operator
template <typename T>
T &Array<T>::operator[](unsigned int index) {
  if (index < _size)
    return _array[index];
  else
    throw Array<T>::OutOfBoundsException();
}

// function
template <typename T>
size_t Array<T>::size() const {
  return _size;
}

// exception
template <typename T>
const char *Array<T>::OutOfBoundsException::what() const throw() {
  return "Error: the element accessed is out of bounds\n";
}