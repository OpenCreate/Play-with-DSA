#pragma once

#include "MaxHeap.h"

class HeapSort {
 public:
  HeapSort() = delete;

  template <typename T>
  static void sort(T arr[], int n) {
    MaxHeap<T> maxHeap;
    for (int i = 0; i < n; ++i) {
      maxHeap.add(arr[i]);
    }

    for (int i = n - 1; i >= 0; i--) {
      arr[i] = maxHeap.extractMax();
    }
  }

  template <typename T>
  static void sort2(T arr[], int n) {
    MaxHeap<T> maxHeap(arr, n);
    for (int i = n - 1; i >= 0; i--) {
      arr[i] = maxHeap.extractMax();
    }
  }

  template <typename T>
  static void sort3(T arr[], int n) {
    if (n <= 1) return;
    // heapify
    for (int i = (n - 2) / 2; i >= 0; --i) siftDown(arr, i, n);
    //堆排序
    for(int i = n - 1; i >= 0; --i){
      std::swap(arr[i], arr[0]);
      siftDown(arr, 0, i);
    }
  }

  template <typename T>
  static void siftDown(T arr[], int k, int n) {
    while (2 * k + 1 < n) {
      int j = 2 * k + 1;
      if (j + 1 < n && arr[j] < arr[j + 1]) j++;
      if (arr[k] >= arr[j]) break;
      std::swap(arr[k], arr[j]);
      k = j;
    }
  }
};