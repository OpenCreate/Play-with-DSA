#include "ArrayGenerator.h"
#include "SortingHelper.h"

namespace {
template <typename T>
void selectionSort(T arr[], int length) {
  for (int i = length - 1; i >= 0; --i) {
    //寻找在arr[0,i)最大值所对应的索引
    int maxIndex = i;
    for (int j = i; j >= 0; --j) {
      if (arr[j] > arr[maxIndex]) maxIndex = j;
    }
    std::swap(arr[i], arr[maxIndex]);
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
