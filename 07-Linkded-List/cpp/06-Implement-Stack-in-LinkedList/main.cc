#include <chrono>
#include <cstdlib>
#include <iostream>
#include <limits>
#include "ArrayStack.h"
#include "LinkedListStack.h"

using namespace std;


double testStack(ArrayStack<int> &stack, int opCount) {
  auto startTime = std::chrono::steady_clock::now();
  for (int i = 0; i < opCount; ++i) {
    stack.push(rand() % INT32_MAX);
  }

  for (int i = 0; i < opCount; ++i) {
    stack.pop();
  }

  auto endTime = std::chrono::steady_clock::now();
  std::chrono::duration<double> time = endTime - startTime;
  return time.count();
}

//注意：此处需要使用引用，否则造成浅拷贝，导致内存释放两次
double testStack(LinkedListStack<int> &stack, int opCount) {
  auto startTime = std::chrono::steady_clock::now();
  for (int i = 0; i < opCount; ++i) {
    stack.push(rand() % INT32_MAX);
  }

  for (int i = 0; i < opCount; ++i) {
    stack.pop();
  }

  auto endTime = std::chrono::steady_clock::now();
  std::chrono::duration<double> time = endTime - startTime;
  return time.count();
}

int main() {
  int opCount = 1000000;

  ArrayStack<int> arrayStack;
  double time1 = testStack(arrayStack, opCount);
  cout << "ArrayStack, time: " << time1 << " s" << endl;

  LinkedListStack<int> linkedListStack;
  double time2 = testStack(linkedListStack, opCount);
  cout << "LinkedListStack, time: " << time2 << " s" << endl;

  return 0;
}