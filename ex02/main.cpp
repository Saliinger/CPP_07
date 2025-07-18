#include <iostream>

#include "include/Array.hpp"

int main() {
  std::cout << "=== Testing Array Template Class ===" << std::endl;

  try {
    // Test 1: Default constructor
    std::cout << "\n1. Testing default constructor:" << std::endl;
    Array<int> empty;
    std::cout << "Empty array size: " << empty.size() << std::endl;

    // Test 2: Parameterized constructor
    std::cout << "\n2. Testing parameterized constructor:" << std::endl;
    Array<int> arr(5);
    std::cout << "Array size: " << arr.size() << std::endl;

    // Test 3: Fill array and access elements
    std::cout << "\n3. Testing element access and assignment:" << std::endl;
    for (unsigned int i = 0; i < arr.size(); i++) {
      arr[i] = i * 10;
    }

    for (unsigned int i = 0; i < arr.size(); i++) {
      std::cout << "arr[" << i << "] = " << arr[i] << std::endl;
    }

    // Test 4: Copy constructor
    std::cout << "\n4. Testing copy constructor:" << std::endl;
    Array<int> copy(arr);
    std::cout << "Copy size: " << copy.size() << std::endl;
    std::cout << "Copy contents: ";
    for (unsigned int i = 0; i < copy.size(); i++) {
      std::cout << copy[i] << " ";
    }
    std::cout << std::endl;

    // Test 5: Assignment operator
    std::cout << "\n5. Testing assignment operator:" << std::endl;
    Array<int> assigned;
    assigned = arr;
    std::cout << "Assigned size: " << assigned.size() << std::endl;

    // Test 6: Modify original and check independence
    std::cout << "\n6. Testing deep copy (independence):" << std::endl;
    arr[0] = 999;
    std::cout << "Original arr[0]: " << arr[0] << std::endl;
    std::cout << "Copy arr[0]: " << copy[0] << std::endl;
    std::cout << "Assigned arr[0]: " << assigned[0] << std::endl;

    // Test 7: Different types
    std::cout << "\n7. Testing with different types:" << std::endl;
    Array<std::string> strArr(3);
    strArr[0] = "Hello";
    strArr[1] = "World";
    strArr[2] = "!";

    for (unsigned int i = 0; i < strArr.size(); i++) {
      std::cout << "strArr[" << i << "] = " << strArr[i] << std::endl;
    }

    // Test 8: Out of bounds access
    std::cout << "\n8. Testing out of bounds exception:" << std::endl;
    try {
      std::cout << arr[100] << std::endl;
    } catch (const std::exception& e) {
      std::cout << "Caught exception: " << e.what() << std::endl;
    }

  } catch (const std::exception& e) {
    std::cerr << "Unexpected exception: " << e.what() << std::endl;
    return 1;
  }

  std::cout << "\n=== All tests completed ===" << std::endl;
  return 0;
}