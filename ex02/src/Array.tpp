#include "../include/Array.hpp"

// orthodox cannonical form
template <typename T>
Array<T>::Array() {
  _size = 0;
  _array = new T[0];
}

template <typename T>
Array<T>::Array(const Array &src) {
  *this = src
}

template <typename T>
Array<T> &Array<T>::operator=(const Array<T> &src) {
  if (*this != src) {
    delete[] _array;
    _size = src._size;
    _array = new T[src._size];
    for (size_t i = 0; i < src._size; i++;) {
      _array[i] = src._array[i];
    }
  }
  return *this;
}

template <typename T>
Array<T>::~Array() {
  delete[] _array;
}

// constructors
template <typename T>
Array<T>::Array(size_t n) {
  _size = n;
  _array = new T[n];
}

// functions
template <typename T>
size_t Array<T>::size() {
  return _size;
}

template <typename T>
Array<T> &Array<T>::operator[]() {
  
}