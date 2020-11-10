#include <iostream>
#include "Queue.h"

int main() {
  Queue<int> queue;
  for (int i = 0; i < 10; ++i) {
    queue.enqueue(i);
    std::cout << queue.toString() << std::endl;
    if (i % 3 == 2) {
      queue.dequeue();
      std::cout << queue.toString() << std::endl;
    }
  }

  return 0;
}
