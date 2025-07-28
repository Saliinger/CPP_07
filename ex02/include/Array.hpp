#pragma once

#include <iostream>

template <typename T>
class Array {
 private:
  unsigned int _size;
  T *_array;

 public:
  // orthodox cannonical form
  Array();
  Array(const Array &src);
  Array &operator=(const Array<T> &src);
  ~Array();

  // constructors
  Array(unsigned int n);

  // operator
  T &operator[](unsigned int index);

  // function
  size_t size() const;

  // exception
  class OutOfBoundsException : public std::exception {
   public:
    virtual const char *what(void) const throw();
  };
};

#include "../src/Array.tpp"