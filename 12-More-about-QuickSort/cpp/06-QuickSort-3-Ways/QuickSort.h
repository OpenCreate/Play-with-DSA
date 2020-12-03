#pragma once

#include <algorithm>

class QuickSort {
 public:
  QuickSort() = delete;

  template <typename T>
  static void sort(T arr[], int n) {
    quickSort(arr, 0, n - 1);
  }

  template <typename T>
  static void sort3Ways(T arr[], int n) {
    quickSort3Ways(arr, 0, n - 1);
  }

 private:
  template <typename T>
  static void quickSort(T arr[], int l, int r) {
    if (l >= r) return;
    int p = partition(arr, l, r);
    quickSort(arr, l, p - 1);
    quickSort(arr, p + 1, r);
  }

  template <typename T>
  static void quickSort3Ways(T arr[], int l, int r) {
    if (l >= r) return;
    int p = l + rand() % (r - l + 1);
    std::swap(arr[l], arr[p]);
    //不再进行partition操作，因为需要返回两个标定点的值来将区间分为三段
    // arr[l+1...lt] < v   arr[lt+1..i-1] = v  arr[gt...r] > v
    int lt = l, gt = r + 1, i = l + 1;
    while (i < gt) {
      if (arr[i] < arr[l]) {
        lt++;
        std::swap(arr[i], arr[lt]);
        i++;
      } else if (arr[i] > arr[l]) {
        gt--;
        std::swap(arr[i], arr[gt]);
      } else {
        i++;
      }
    }
    std::swap(arr[l], arr[lt]);  //枢纽归位

    quickSort3Ways(arr, l, lt - 1);
    quickSort3Ways(arr, gt, r);
  }

  template <typename T>
  static int partition(T arr[], int l, int r) {
    int index = rand() % (r - l + 1) + l;
    std::swap(arr[l], arr[index]);
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