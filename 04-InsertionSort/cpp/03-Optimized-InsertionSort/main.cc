#include <cstring>
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

template <typename T>
void insertionSort2(T arr[], int length) {
  for (int i = 0; i < length; ++i) {
    // arr[0,i)有序  arr[i,n)无序， 将arr[i] 插入到合适的位置去
    T t = arr[i];
    int j;  //应该插入的位置,使用直接赋值替换交换
    for (j = i; j - 1 >= 0 && t < arr[j - 1]; --j) {
      arr[j] = arr[j - 1];
    }
    arr[j] = t;
  }
}
}  // namespace

int main() {
  int dataSize[] = {10000, 50000};
  for (auto n : dataSize) {
    int *data = ArrayGenerator::generateRandomArray(n, n);
    int *data2 = new int[n];
    memcpy(data2, data, sizeof(int) * n);

    SortingHelper::sortTest("insertionSort", insertionSort, data, n);
    SortingHelper::sortTest("insertionSort2", insertionSort2, data2, n);

    delete[] data;
    delete[] data2;
  }

  return 0;
}
