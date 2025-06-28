#pragma once

#include <iostream>

template <typename T>
class Array {
 private:
  size_t size;
  T *_array;

 public:
  // orthodox cannonical form
  Array();
  Array(const Array &src);
  Array &operator=(const Array &src);
  ~Array();

  // constructors
  Array(size_t n);

  // function
  size_t size();

  // operator
  Array<T> &operator[]()
};

#include "../src/Array.tpp"