#include <iostream>
#include "ArrayGenerator.h"
#include "HeapSort.h"
#include "SortingHelper.h"

using namespace std;

template <typename T>
bool isSorted(std::vector<T> &arr) {
  for (int i = 1; i < arr.size(); ++i) {
    if (arr[i - 1] > arr[i]) return false;
  }
  return true;
}

int main() {
  int n = 1000000;

  cout << "Random Array : " << endl;

  int *arr = ArrayGenerator::generateRandomArray(n, n);
  int *arr2 = new int[n];

  std::copy(arr, arr + n, arr2);

  SortingHelper::sortTest("HeapSort", HeapSort::sort, arr, n);
  SortingHelper::sortTest("HeapSort", HeapSort::sort2, arr2, n);

  delete[] arr;
  delete[] arr2;

  return 0;
}
