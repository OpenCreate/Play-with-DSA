#include <iostream>
#include "Array.h"

int main() {
  Array array(20);
  array.addFirst(-1);
  for (int i = 0; i < 10; ++i) {
    array.addLast(i + 1);
  }
  std::cout << array.toString() << std::endl;

  array.set(0, 99);
  array[1] = 100;
  std::cout << array.get(0) << " " << array.get(1) << std::endl;
  return 0;
}
