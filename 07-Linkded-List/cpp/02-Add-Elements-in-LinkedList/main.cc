#include "LinkedList.h"
#include <iostream>

int main(){

  LinkedList<int> list;
  list.addFirst(1);
  list.addFirst(2);
  list.add(2, 3);
  std::cout << list.getSize() << ", " << list.isEmpty() << std::endl;

  return 0;
}

