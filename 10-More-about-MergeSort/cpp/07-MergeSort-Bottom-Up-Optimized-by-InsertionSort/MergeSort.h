#pragma once

#include <algorithm>
#include <iostream>
#include "InsertionSort.h"

class MergeSort {
 public:
  MergeSort() = delete;

  template <typename T>
  static void sort(T arr[], int n) {
    T *temp = new T[n];  //只开辟一次空间
    std::copy(arr, arr + n, temp);
    sort(arr, 0, n - 1, temp);
    delete[] temp;
  }

  template <typename T>
  static void sort(T arr[], int l, int r, T temp[]) {
    if (l >= r) return;
    int mid = l + (r - l) / 2;
    sort(arr, l, mid, temp);
    sort(arr, mid + 1, r, temp);
    if (arr[mid] > arr[mid + 1]) merge(arr, l, mid, r, temp);
  }

  template <typename T>
  static void sortBU(T arr[], int n) {
    T *temp = new T[n];  //只开辟一次空间
    std::copy(arr, arr + n, temp);

    //对arr[i, i + 15]这个区间的元素使用插入排序优化
    for (int i = 0; i < n; i += 16) {
      InsertionSort::sort(arr, i, std::min(n - 1, i + 15));
    }
    for (int sz = 16; sz < n; sz += sz) {
      //遍历合并区间的两个起始位置
      //合并arr[i, i + sz - 1]和arr[i + sz, min(i + sz + sz - 1, n - 1)]区间
      for (int i = 0; i + sz < n; i += sz + sz) {
        if (arr[i + sz - 1] > arr[i + sz])
          merge(arr, i, i + sz - 1, std::min(i + sz + sz - 1, n - 1), temp);
      }
    }
    delete[] temp;
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
        arr[k] = temp[j];  // temp数组索引从l开始， arr数组索引从l开始
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
