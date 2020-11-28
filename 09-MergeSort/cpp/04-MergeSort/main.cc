#include <cstring>
#include <iostream>
#include "ArrayGenerator.h"
#include "InsertionSort.h"
#include "MergeSort.h"
#include "SelectionSort.h"
#include "SortingHelper.h"

int main() {
  std::cout << "Hello, World!" << std::endl;

  int dataSize[] = {100000};
  for (auto n : dataSize) {
    int *data = ArrayGenerator::generateRandomArray(n, n);
    int *data2 = new int[n];
    int *data3 = new int[n];
    memcpy(data2, data, sizeof(int) * n);
    memcpy(data3, data, sizeof(int) * n);

    SortingHelper::sortTest("SelectionSort", SelectionSort::sort, data, n);
    SortingHelper::sortTest("InsertionSort", InsertionSort::sort, data2, n);
    SortingHelper::sortTest("MergeSort", MergeSort::sort, data3, n);

    delete[] data;
    delete[] data2;
    delete[] data3;
  }
  return 0;
}
