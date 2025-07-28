#include "./include/iter.hpp"

template <typename T>
void add(T &src) {
  src++;
}

int main() {
  int l[] = {1, 2, 3, 4};

  std::cout << "before iter:" << std::endl;
  for (int i = 0; i < 4; i++) std::cout << l[i] << std::endl;
  iter<int>(l, 4, add<int>);
  std::cout << "after iter:" << std::endl;
  for (int i = 0; i < 4; i++) std::cout << l[i] << std::endl;
  return 0;
}