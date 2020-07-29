#include "ArrayGenerator.h"
#include "SortingHelper.h"

namespace {
template <typename T>
void insertionSort(T arr[], int length) {
  for (int i = 0; i < length; ++i) {
    // arr[0,i)有序  arr[i,n)无序， 将arr[i] 插入到合适的位置去
    for (int j = i; j - 1 >= 0; --j) {
      if (arr[j] < arr[j - 1])
        std::swap(arr[j], arr[j - 1]);
      else
        break;
    }
    //简化为下述写法
    // for(int j = i; j - 1 >= 0 && arr[j] < arr[j-1]; --j)
    //    std::swap(arr[j], arr[j-1]);
  }
}
}  // namespace

int main() {
  int dataSize[] = {10000, 100000};
  for (auto n : dataSize) {
    int *data = ArrayGenerator::generateRandomArray(n, n);
    SortingHelper::sortTest("insertionSort", insertionSort, data, n);
    delete[] data;
  }

  return 0;
}
