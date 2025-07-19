# Array Template Class - Error Analysis

## Critical Errors Found

### 1. **Wrong Return Type in operator[]**

**Location:** `Array.tpp` - operator[] implementation
**Issue:** The operator returns `int&` instead of `T&`

```cpp
// WRONG:
int &Array<T>::operator[](int index)

// CORRECT:
T &Array<T>::operator[](unsigned int index)
```

**Impact:** This makes the template only work for `int` type, defeating the purpose of templates.

### 2. **Incorrect Bounds Checking Logic**

**Location:** `Array.tpp` - operator[] implementation
**Issue:** The condition excludes index 0 (which is valid)

```cpp
// WRONG:
if (index > 0 && index < _size)  // excludes index 0!

// CORRECT:
if (index >= 0 && index < _size)  // or just: if (index < _size) for unsigned
```

**Impact:** You cannot access the first element of the array.

### 3. **Dangerous Copy Constructor**

**Location:** `Array.tpp` - copy constructor
**Issue:** Calls assignment operator before initializing members

```cpp
// WRONG:
Array<T>::Array(const Array &src) {
  *this = src;  // _array is uninitialized!
}

// CORRECT:
Array<T>::Array(const Array &src) : _size(src._size) {
  _array = new T[_size];
  for (unsigned int i = 0; i < _size; i++) {
    _array[i] = src._array[i];
  }
}
```

**Impact:** Undefined behavior due to accessing uninitialized `_array`.

### 4. **Double Free Error in Assignment Operator**

**Location:** `Array.tpp` - assignment operator (line 18)
**Issue:** Incorrectly using `new T()` for array elements

```cpp
// WRONG - CAUSES DOUBLE FREE:
_array[i] = new T(src._array[i]);  // Assigning pointer to object!

// CORRECT:
_array[i] = src._array[i];  // Simple value assignment
```

**Explanation:**

- You allocate an array of `T` objects with `new T[_size]()`
- Then you try to assign pointers (`new T(...)`) to array elements
- This creates a type mismatch and memory management confusion
- The destructor tries to `delete[]` an array containing pointers, causing double free

**Impact:** Runtime crash due to double free error.

### 5. **Invalid Comparison in Assignment Operator**

**Location:** `Array.tpp` - assignment operator
**Issue:** Using `!=` operator that doesn't exist

```cpp
// WRONG:
if (*this != src)  // no != operator defined!

// CORRECT:
if (this != &src)  // compare addresses
```

**Impact:** Compilation error.

### 6. **Memory Allocation Issue in Default Constructor**

**Location:** `Array.tpp` - default constructor
**Issue:** Allocating 0-sized array

```cpp
// PROBLEMATIC:
Array<T>::Array() : _size(0) {
    _array = new T[0];  // implementation-defined behavior
}

// BETTER:
Array<T>::Array() : _size(0), _array(NULL) {
}
```

**Impact:** Potential undefined behavior.

## Minor Issues

### 7. **Typo in Exception Name**

**Location:** `Array.hpp` - exception class name
**Issue:** `OutOfBondException` should be `OutOfBoundsException`

### 8. **Missing const operator[]**

**Location:** `Array.hpp` - operator[] declaration
**Issue:** No const version of operator[] for const Array objects

```cpp
// ADD:
const T &operator[](unsigned int index) const;
```

### 8. **Parameter Type Inconsistency**

**Location:** Various locations
**Issue:** Mix of `int`, `unsigned int`, and `size_t`
**Recommendation:** Use `unsigned int` consistently for indices to match the size type.

### 9. **No Value Initialization**

**Location:** `Array.tpp` - parameterized constructor
**Issue:** Array elements are not initialized

```cpp
// CURRENT:
_array = new T[n];

// BETTER:
_array = new T[n]();  // value-initialize elements
```

### 10. **Incomplete Main Function**

**Location:** `main.cpp`
**Issue:** The main function doesn't test the Array functionality
**Impact:** Cannot verify the implementation works correctly.

## Subject Compliance Check

Based on typical C++ Module 07 ex02 requirements, your implementation should have:

✅ **Template class**
✅ **Orthodox Canonical Form** (constructors, destructor, assignment)
✅ **Parameterized constructor**
✅ **operator[] with bounds checking**
✅ **size() member function**
✅ **Exception for out-of-bounds access**
❌ **Proper template implementation** (current has type errors)
❌ **Working test program**

## Recommended Fixes Priority

1. **CRITICAL:** Fix double free error in assignment operator (line 18)
2. **HIGH PRIORITY:** Fix operator[] return type (`T&` not `int&`)
3. **HIGH PRIORITY:** Fix bounds checking logic
4. **HIGH PRIORITY:** Fix copy constructor implementation
5. **HIGH PRIORITY:** Fix assignment operator comparison
6. **MEDIUM PRIORITY:** Fix default constructor memory allocation
7. **LOW PRIORITY:** Fix exception name typo
8. **LOW PRIORITY:** Add comprehensive tests to main.cpp

## Testing Recommendations

Your `main.cpp` should test:

- Default constructor
- Parameterized constructor with different sizes
- Copy constructor (deep copy verification)
- Assignment operator (deep copy verification)
- Element access and modification
- Out-of-bounds exception throwing
- Different template types (int, string, custom classes)
- Const correctness

## Compilation Test

After fixing these issues, your code should compile with:

```bash
make
```

And run without errors:

```bash
./whatever
```
