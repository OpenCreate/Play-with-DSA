#pragma once

class InsertionSort {
 public:
  InsertionSort() = delete;

  template <typename T>
  static void sort(T arr[], int l, int r) {
    for (int i = l; i <= r; ++i) {
      T t = arr[i];
      int j;  //应该插入的位置,使用直接赋值替换交换
      for (j = i; j - 1 >= 0 && t < arr[j - 1]; --j) {
        arr[j] = arr[j - 1];
      }
      arr[j] = t;
    }
  }
};
