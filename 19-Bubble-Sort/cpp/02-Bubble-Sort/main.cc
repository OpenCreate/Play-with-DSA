#include <iostream>
#include "ArrayGenerator.h"
#include "BubbleSort.h"
#include "SortingHelper.h"

int main() {
  int dataSize[] = {10000, 20000};
  for (auto n : dataSize) {
    int *data = ArrayGenerator::generateRandomArray(n, n);
    SortingHelper::sortTest("BubbleSort", BubbleSort::sort, data, n);
    delete[] data;
  }
  return 0;
}
