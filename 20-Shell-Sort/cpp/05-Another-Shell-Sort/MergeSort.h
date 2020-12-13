#pragma once

#include <algorithm>
#include <iostream>

class MergeSort {
 public:
  MergeSort() = delete;

  template <typename T>
  static void sort(T arr[], int n) {
    T *temp = new T[n];  //只开辟一次空间
    sort(arr, 0, n - 1, temp);
    delete[] temp;
  }

 private:
  //优化
  template <typename T>
  static void sort(T arr[], int l, int r, T temp[]) {
    if (l >= r) return;
    int mid = l + (r - l) / 2;
    sort(arr, l, mid, temp);
    sort(arr, mid + 1, r, temp);
    if (arr[mid] > arr[mid + 1]) merge(arr, l, mid, r, temp);
  }

  //合并两个有序的区间，arr[l,mid], arr[mid+1,r]
  template <typename T>
  static void merge(T arr[], int l, int mid, int r, T temp[]) {
    std::copy(arr + l, arr + r + 1, temp + l);  //左闭右开

    int i = l;
    int j = mid + 1;
    //每轮循环为 arr[k] 赋值
    for (int k = l; k <= r; k++) {
      if (i > mid) {
        arr[k] = temp[j];  // temp数组索引从0开始， arr数组索引从l开始
        j++;
      } else if (j > r) {
        arr[k] = temp[i];
        i++;
      } else if (temp[i] < temp[j]) {
        arr[k] = temp[i];
        i++;
      } else {
        arr[k] = temp[j];
        j++;
      }
    }
  }
};
