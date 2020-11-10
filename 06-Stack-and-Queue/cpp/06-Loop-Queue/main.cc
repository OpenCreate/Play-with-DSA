#include <iostream>
#include "LoopQueue.h"

int main() {
  LoopQueue<int> queue;
  std::cout << queue.getCapacity() << "; " << queue.getSize() << std::endl;

  return 0;
}
