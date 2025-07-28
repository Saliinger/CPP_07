#pragma once

#include <iostream>

template <typename T>
void iter(T *array, size_t length, void(*f)(T &));

#include "../src/iter.tpp"