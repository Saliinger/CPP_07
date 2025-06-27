#pragma once

#include <iostream>

template <typename T>
class Array {
 private:
  T *_array;

 public:
  // orthodox cannonical form
  Array();
  Array(const Array &src);
  Array &operator=(const Array &src);
  ~Array();

  // constructors
  Array(size_t n);
};

#include "../src/Array.tpp"