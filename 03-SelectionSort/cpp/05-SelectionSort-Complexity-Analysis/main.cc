#include "ArrayGenerator.h"
#include "SortingHelper.h"

namespace {
template <typename T>
void selectionSort(T arr[], int length) {
  for (int i = 0; i < length; ++i) {
    //寻找在arr[i,n)最小值所对应的索引
    int minIndex = i;
    for (int j = i; j < length; ++j) {
      if (arr[j] < arr[minIndex]) minIndex = j;
    }
    std::swap(arr[i], arr[minIndex]);
  }
}
}  // namespace

int main() {
  int dataSize[] = {10000, 100000};
  for (auto n : dataSize) {
    int *data = ArrayGenerator::generateRandomArray(n, n);
    SortingHelper::sortTest("selectionSort", selectionSort, data, n);
    delete[] data;
  }

  return 0;
}
