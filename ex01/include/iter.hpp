#pragma once

#include <iostream>

template <typename T>
void iter(T *array, size_t length, void (*f)(T &));

template <typename T>
void iter(T *array, size_t length, void (*f)(const T &));

#include "../src/iter.tpp"