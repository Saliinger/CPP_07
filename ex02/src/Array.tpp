#include "../include/Array.hpp"

template <typename T>
Array<T>::Array() {}

template <typename T>
Array<T>::Array(const Array &src) {

}

template <typename T>
Array<T>& Array<T>::operator=(const Array<T> &src) {

}

template <typename T>
Array<T>::~Array() {}

// constructors
template <typename T>
Array<T>::Array(size_t n) {
    _array = new()
}