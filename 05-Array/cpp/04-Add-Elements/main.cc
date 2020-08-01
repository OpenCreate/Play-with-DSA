#include <iostream>
#include "Array.h"

int main() {
  Array array;
  std::cout << array.getSize() << " " << array.getCapacity() << " "
            << array.isEmpty() << std::endl;
  array.addLast(1);
  array.addLast(2);
  std::cout << array.getSize() << std::endl;
  return 0;
}
