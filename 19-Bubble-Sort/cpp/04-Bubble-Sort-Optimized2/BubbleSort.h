#pragma once

class BubbleSort {
 public:
  BubbleSort() = delete;

  template <typename T>
  static void sort(T arr[], int n) {
    for (int i = 0; i < n - 1; ++i) {
      //循环不变量：arr[n-i,n)已经排好序
      //通过冒泡在 arr[n-i-1] 位置放上合适的元素
      for (int j = 0; j < n - 1 - i; j++) {
        if (arr[j] > arr[j + 1]) std::swap(arr[j], arr[j + 1]);
      }
    }
  }

  template <typename T>
  static void sort2(T arr[], int n) {
    for (int i = 0; i < n - 1; ++i) {
      //循环不变量：arr[n-i,n)已经排好序
      //通过冒泡在 arr[n-i-1] 位置放上合适的元素
      bool isSwapped = false;
      for (int j = 0; j < n - 1 - i; j++) {
        if (arr[j] > arr[j + 1]) {
          std::swap(arr[j], arr[j + 1]);
          isSwapped = true;
        }
      }

      if (!isSwapped) break;  //已经有序了
    }
  }

  template <typename T>
  static void sort3(T arr[], int n) {
    for (int i = 0; i < n - 1;) {
      //循环不变量：arr[n-i,n)已经排好序
      //通过冒泡在 arr[n-i-1] 位置放上合适的元素
      int lastSwappedIndex = 0;
      for (int j = 0; j < n - 1 - i; j++) {
        if (arr[j] > arr[j + 1]) {
          std::swap(arr[j], arr[j + 1]);
          lastSwappedIndex = j + 1;
        }
      }
      i = n - lastSwappedIndex;  // i表示有多少元素已经排好序了
    }
  }
};