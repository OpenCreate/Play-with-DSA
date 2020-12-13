#pragma once

class ShellSort {
 public:
  ShellSort() = delete;

  template <typename T>
  static void sort(T arr[], int n) {
    int h = n / 2;
    while (h >= 1) {
      //对每个元素都进行插入排序，步长为 h
      for (int i = h; i < n; i++) {
        T t = arr[i];
        int j;
        for (j = i; j - h >= 0 && t < arr[j - h]; j -= h)
          arr[j] = arr[j - h];
        arr[j] = t;
      }

      h /= 2;
    }
  }
};