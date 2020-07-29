#include <cstring>
#include <iostream>
#include "ArrayGenerator.h"
#include "SortingHelper.h"

namespace {

template <typename T>
void insertionSort(T arr[], int length) {
  for (int i = length - 1; i >= 0; --i) {
    // arr[0,i)无序  arr[i,n)有序， 将arr[i] 插入到合适的位置去
    T t = arr[i];
    int j;  //应该插入的位置,使用直接赋值替换交换
    for (j = i; j + 1 < length && t > arr[j + 1]; ++j) {
      arr[j] = arr[j + 1];
    }
    arr[j] = t;
  }
}

}  // namespace

int main() {
  int dataSize[] = {10000, 100000};
  for (auto n : dataSize) {
    int *data = ArrayGenerator::generateRandomArray(n, n);
    std::cout << "Random arry\n";
    SortingHelper::sortTest("insertionSort", insertionSort, data, n);

    delete[] data;

    int *data2 = ArrayGenerator::generateOrderedArray(n);
    std::cout << "Ordered arry\n";
    SortingHelper::sortTest("insertionSort", insertionSort, data2, n);

    delete[] data2;
  }

  return 0;
}
