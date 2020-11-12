#include <iostream>
#include "LinkedList.h"

int main() {
  LinkedList<int> list;
  for (int i = 0; i < 5; i++) {
    list.addFirst(i);
    std::cout << list.toString() << std::endl;
  }

  list.add(3, 88);
  std::cout << list.toString() << std::endl;

  list.set(3, 888);
  std::cout << list.toString() << std::endl;
  return 0;
}
