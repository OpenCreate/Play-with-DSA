#pragma once

#include <algorithm>
#include <iostream>

class MergeSort {
 public:
  MergeSort() = delete;

  template <typename T>
  static void sort(T arr[], int n) {
    sort(arr, 0, n - 1);
  }

  template <typename T>
  static void sort2(T arr[], int n) {
    sort2(arr, 0, n - 1);
  }

 private:
  template <typename T>
  static void sort(T arr[], int l, int r) {
    if (l >= r) return;
    int mid = l + (r - l) / 2;
    sort(arr, l, mid);
    sort(arr, mid + 1, r);
    merge(arr, l, mid, r);
  }

  //优化
  template <typename T>
  static void sort2(T arr[], int l, int r) {
    if (l >= r) return;
    int mid = l + (r - l) / 2;
    sort2(arr, l, mid);
    sort2(arr, mid + 1, r);
    if (arr[mid] > arr[mid + 1]) merge(arr, l, mid, r);
  }
  //合并两个有序的区间，arr[l,mid], arr[mid+1,r]
  template <typename T>
  static void merge(T arr[], int l, int mid, int r) {
    int n = r - l + 1;
    T *temp = new T[n];
    std::copy(arr + l, arr + r + 1, temp);  //左闭右开

    int i = l;
    int j = mid + 1;
    //每轮循环为 arr[k] 赋值
    for (int k = l; k <= r; k++) {
      if (i > mid) {
        arr[k] = temp[j - l];  // temp数组索引从0开始， arr数组索引从l开始
        j++;
      } else if (j > r) {
        arr[k] = temp[i - l];
        i++;
      } else if (temp[i - l] < temp[j - l]) {
        arr[k] = temp[i - l];
        i++;
      } else {
        arr[k] = temp[j - l];
        j++;
      }
    }
    delete[] temp;
  }
};
