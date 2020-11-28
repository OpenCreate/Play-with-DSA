#pragma once

class SelectionSort {
 public:
  SelectionSort() = delete;

  template <typename T>
  static void sort(T arr[], int length) {
    for (int i = 0; i < length; ++i) {
      //寻找在arr[i,n)最小值所对应的索引
      int minIndex = i;
      for (int j = i; j < length; ++j) {
        if (arr[j] < arr[minIndex]) minIndex = j;
      }
      std::swap(arr[i], arr[minIndex]);
    }
  }
};