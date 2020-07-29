#include <cstring>
#include <iostream>
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

template <typename T>
void insertionSort(T arr[], int length) {
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
  int dataSize[] = {10000, 100000};
  for (auto n : dataSize) {
    int *data = ArrayGenerator::generateRandomArray(n, n);
    int *data2 = new int[n];
    memcpy(data2, data, sizeof(int) * n);
    std::cout << "Random arry\n";
    SortingHelper::sortTest("selectionSort", selectionSort, data, n);
    SortingHelper::sortTest("insertionSort", insertionSort, data2, n);

    delete[] data;
    delete[] data2;

    int *data3 = ArrayGenerator::generateOrderedArray(n);
    int *data4 = new int[n];
    memcpy(data4, data3, sizeof(int) * n);
    std::cout << "Ordered arry\n";
    SortingHelper::sortTest("selectionSort", selectionSort, data3, n);
    SortingHelper::sortTest("insertionSort", insertionSort, data4, n);

    delete[] data3;
    delete[] data4;
  }

  return 0;
}
