#include <iostream>
#include "PriorityQueue.h"

int main() {
  PriorityQueue<int> priorityQueue;
  int n = 20;
  srand(time(0));
  for (int i = 0; i < n; ++i) {
    priorityQueue.enqueue(rand() % 999);
  }

  while (!priorityQueue.isEmpty()) {
    std::cout << priorityQueue.getFront() << " ";
    priorityQueue.dequeue();
  }

  std::cout << "\nHello, World!" << std::endl;
  return 0;
}
