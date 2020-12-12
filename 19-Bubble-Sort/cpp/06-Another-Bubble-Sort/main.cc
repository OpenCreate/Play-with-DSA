#include <iostream>
#include "ArrayGenerator.h"
#include "BubbleSort.h"
#include "SortingHelper.h"

int main() {
  int n = 10000;
  int *data = ArrayGenerator::generateRandomArray(n, n);
  int *data2 = new int[n];
  int *data3 = new int[n];
  std::copy(data, data + n, data2);
  std::copy(data, data + n, data3);
  SortingHelper::sortTest("BubbleSort", BubbleSort::sort, data, n);
  SortingHelper::sortTest("BubbleSort2", BubbleSort::sort2, data2, n);
  SortingHelper::sortTest("BubbleSort3", BubbleSort::sort3, data3, n);
  delete[] data;
  delete[] data2;
  delete[] data3;

  data = ArrayGenerator::generateOrderedArray(n);
  data2 = new int[n];
  data3 = new int[n];
  std::copy(data, data + n, data2);
  std::copy(data, data + n, data3);
  SortingHelper::sortTest("BubbleSort", BubbleSort::sort, data, n);
  SortingHelper::sortTest("BubbleSort2", BubbleSort::sort2, data2, n);
  SortingHelper::sortTest("BubbleSort3", BubbleSort::sort3, data3, n);
  delete[] data;
  delete[] data2;
  delete[] data3;

  return 0;
}
