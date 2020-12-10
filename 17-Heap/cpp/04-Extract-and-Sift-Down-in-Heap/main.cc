#include <exception>
#include <iostream>
#include <vector>
#include "MaxHeap.h"

using namespace std;

int main() {
  int n = 1000000;

  MaxHeap<int> maxHeap;
  srand((unsigned int)time(0));
  for (int i = 0; i < n; ++i) {
    maxHeap.add(rand() % INT32_MAX);
  }
  vector<int> vec;
  for (int i = 0; i < n; ++i) vec.push_back(maxHeap.extractMax());

  for (int i = 1; i < n; ++i) {
    if (vec[i - 1] < vec[i]) throw std::invalid_argument("Error");
  }
  return 0;
}
