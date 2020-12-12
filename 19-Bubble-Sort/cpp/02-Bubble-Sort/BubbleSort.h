#pragma once

class BubbleSort {
 public:
  BubbleSort() = delete;

  template <typename T>
  static void sort(T arr[], int n) {
    for (int i = 0; i < n - 1; ++i) {
      //循环不变量: arr[n-i, n) 已经排好序
      //通过冒泡在 arr[n-i-1] 位置上放上合适的元素
      for (int j = 0; j < n - i - 1; ++j) {
        if (arr[j] > arr[j + 1]) std::swap(arr[j], arr[j + 1]);
      }
    }
  }
};