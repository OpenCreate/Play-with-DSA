#include "LinkedList.h"
#include <iostream>

int main(){

  LinkedList<int> list;
  list.add(0, 66);
  list.add(1, 77);

  std::cout << list.getSize() << std::endl;

  return 0;
}

