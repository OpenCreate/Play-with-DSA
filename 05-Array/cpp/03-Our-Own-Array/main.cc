#include <iostream>
#include "Array.h"

int main() {
  Array array;
  std::cout << array.getSize() << " " << array.getCapacity() << " "
            << array.isEmpty() << std::endl;

  return 0;
}
