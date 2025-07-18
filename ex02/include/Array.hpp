#pragma once

#include <iostream>

template <typename T>
class Array {
 private:
  size_t _size;
  T *_array;

 public:
  // orthodox cannonical form
  Array();
  Array(const Array &src);
  Array &operator=(const Array &src);
  ~Array();

  // constructors
  Array(size_t n);

  // operator
  int &operator[](int index);

  // function
  size_t size() const;

  // exception
  class OutOfBondException : public std::exception {
   public:
    virtual const char *what(void) const throw();
  }
};

#include "../src/Array.tpp"