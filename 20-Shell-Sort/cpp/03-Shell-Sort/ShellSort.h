#pragma once

class ShellSort {
 public:
  ShellSort() = delete;

  template <typename T>
  static void sort(T arr[], int n) {
    int h = n / 2;
    while (h >= 1) {
      //对每组的元素进行插入排序
      for (int start = 0; start < h; start++) {
        //对arr[start, start+h, start+2h, start+3h...]进行插入排序
        for (int i = start + h; i < n; i += h) {
          T t = arr[i];
          int j;
          for (j = i; j - h >= 0 && t < arr[j - h]; j -= h) {
            arr[j] = arr[j - h];
          }
          arr[j] = t;
        }
      }

      h /= 2;
    }
  }
};