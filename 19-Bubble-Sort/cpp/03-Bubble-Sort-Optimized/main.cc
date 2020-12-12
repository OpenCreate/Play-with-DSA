#include <iostream>
#include "ArrayGenerator.h"
#include "BubbleSort.h"
#include "SortingHelper.h"

int main() {
  int n = 20000;
  int *data = ArrayGenerator::generateRandomArray(n, n);
  int *data2 = new int[n];
  std::copy(data, data + n, data2);
  SortingHelper::sortTest("BubbleSort", BubbleSort::sort, data, n);
  SortingHelper::sortTest("BubbleSort2", BubbleSort::sort2, data2, n);
  delete[] data;
  delete[] data2;

  data = ArrayGenerator::generateOrderedArray(n);
  data2 = new int[n];
  std::copy(data, data + n, data2);
  SortingHelper::sortTest("BubbleSort", BubbleSort::sort, data, n);
  SortingHelper::sortTest("BubbleSort2", BubbleSort::sort2, data2, n);
  delete[] data;
  delete[] data2;

  return 0;
}
