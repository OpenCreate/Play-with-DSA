#include <chrono>
#include <iostream>
#include "Array.h"
#include "LinkedList.h"

using namespace std;
int main() {
  Array<int> *array = new Array<int>();
  LinkedList<int> *list = new LinkedList<int>();

  // 对于 1000 万规模的数据
  int n = 10000000;
  cout << "n = " << n << endl;

  // 计时，看将 1000 万个元素放入数组中，时间是多少
  auto startTime = chrono::steady_clock::now();
  // 对于数组，我们使用 addLast，每一次操作时间复杂度都是 O(1) 的
  for (int i = 0; i < n; i++) array->addLast(i);
  auto endTime = chrono::steady_clock::now();
  chrono::duration<double> time = endTime - startTime;
  cout << "Array : " << time.count() << " s" << endl;

  // 计时，看将 1000 万个元素放入链表中，时间是多少
  startTime = chrono::steady_clock::now();
  // 对于链表，我们使用 addFirst，每一次操作时间复杂度都是 O(1) 的
  for (int i = 0; i < n; i++) list->addFirst(i);
  endTime = chrono::steady_clock::now();
  time = endTime - startTime;
  cout << "LinkedList : " << time.count() << " s" << endl;

  return 0;
}