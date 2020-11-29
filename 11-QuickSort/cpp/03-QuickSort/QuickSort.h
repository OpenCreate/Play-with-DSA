#pragma once

#include <algorithm>

class QuickSort {
 public:
  QuickSort() = delete;

  template <typename T>
  static void sort(T arr[], int n) {
    quickSort(arr, 0, n - 1);
  }

 private:
  template <typename T>
  static void quickSort(T arr[], int l, int r) {
    if(l >= r) return;
    int p = partition(arr, l, r);
    quickSort(arr, l, p - 1);
    quickSort(arr, p + 1, r);
  }

  template <typename T>
  static int partition(T arr[], int l, int r) {
    T p = arr[l];
    // arr[l+1..j] < v   arr[j+1..i-1] >= v    循环不变量
    int j = l;
    for (int i = l + 1; i <= r; i++) {
      if (arr[i] < p) {
        j++;
        std::swap(arr[i], arr[j]);
      }
    }

    std::swap(arr[l], arr[j]);
    return j;
  }
};