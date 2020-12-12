#pragma once

class BubbleSort {
 public:
  BubbleSort() = delete;

  template <typename T>
  static void sort(T arr[], int n) {
    for (int i = 0; i < n - 1; ++i) {
      // arr[0,i)已经排好序
      //通过冒泡在 arr[i] 位置放上合适的元素
      for (int j = n - 1; j > i; j--) {
        if (arr[j] < arr[j - 1]) {
          std::swap(arr[j], arr[j - 1]);
        }
      }
    }
  }

  template <typename T>
  static void sort2(T arr[], int n) {
    for (int i = 0; i < n - 1; ++i) {
      // arr[0,i)已经排好序
      //通过冒泡在 arr[i] 位置放上合适的元素
      bool isSwapped = false;
      for (int j = n - 1; j > i; j--) {
        if (arr[j] < arr[j - 1]) {
          std::swap(arr[j], arr[j - 1]);
          isSwapped = true;
        }
      }

      if (!isSwapped) break;
    }
  }

  template <typename T>
  static void sort3(T arr[], int n) {
    for (int i = 0; i < n - 1;) {
      // arr[0,i)已经排好序
      //通过冒泡在 arr[i] 位置放上合适的元素
      int lastSwappedIndex = n - 1;
      for (int j = n - 1; j > i; j--) {
        if (arr[j] < arr[j - 1]) {
          std::swap(arr[j], arr[j - 1]);
          lastSwappedIndex = j - 1;
        }
      }

      i = lastSwappedIndex + 1;  //有多少元素排好序了
    }
  }
};