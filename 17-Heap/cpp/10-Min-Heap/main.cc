#include <iostream>
#include "ArrayGenerator.h"
#include "MinHeap.h"
#include "SortingHelper.h"

using namespace std;

int main() {
  //使用最小堆进行堆排序比最大堆要复杂，且用时久
  int n = 100000;
  MinHeap<int> minHeap;
  srand(time(0));
  for (int i = 0; i < n; ++i) minHeap.add(rand() % INT32_MAX);
  int *arr2 = new int[n];
  for (int i = 0; i < n; ++i) arr2[i] = minHeap.extractMin();

  for (int i = 1; i < n; ++i) {
    if (arr2[i - 1] > arr2[i]) throw std::invalid_argument("Error");
  }

  std::cout << "MinHeap is OK\n";

  return 0;
}
