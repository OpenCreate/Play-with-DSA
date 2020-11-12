#include <chrono>
#include <cstdlib>
#include <iostream>
#include <limits>
#include "ArrayQueue.h"
#include "LinkedListQueue.h"
#include "LoopQueue.h"

using namespace std;

double testQueue(ArrayQueue<int> &q, int opCount) {
  auto startTime = std::chrono::steady_clock::now();

  for (int i = 0; i < opCount; ++i) {
    q.enqueue(rand() % INT32_MAX);
  }
  for (int i = 0; i < opCount; ++i) {
    q.dequeue();
  }

  auto endTime = std::chrono::steady_clock::now();
  std::chrono::duration<double> time = endTime - startTime;

  return time.count();
}

double testQueue(LoopQueue<int> &q, int opCount) {
  auto startTime = std::chrono::steady_clock::now();

  for (int i = 0; i < opCount; ++i) {
    q.enqueue(rand() % INT32_MAX);
  }
  for (int i = 0; i < opCount; ++i) {
    q.dequeue();
  }

  auto endTime = std::chrono::steady_clock::now();
  std::chrono::duration<double> time = endTime - startTime;

  return time.count();
}

double testQueue(LinkedListQueue<int> &q, int opCount) {
  auto startTime = std::chrono::steady_clock::now();

  for (int i = 0; i < opCount; ++i) {
    q.enqueue(rand() % INT32_MAX);
  }
  for (int i = 0; i < opCount; ++i) {
    q.dequeue();
  }

  auto endTime = std::chrono::steady_clock::now();
  std::chrono::duration<double> time = endTime - startTime;

  return time.count();
}

int main() {
  int opCount = 100000;

  ArrayQueue<int> arrayQueue;
  double time1 = testQueue(arrayQueue, opCount);
  cout << "ArrayQueue, time: " << time1 << " s" << endl;

  LoopQueue<int> loopQueue;
  double time2 = testQueue(loopQueue, opCount);
  cout << "LoopQueue, time: " << time2 << " s" << endl;

  LinkedListQueue<int> linkedListQueue;
  double time3 = testQueue(linkedListQueue, opCount);
  cout << "LinkedListQueue, time: " << time3 << " s" << endl;

  return 0;
}