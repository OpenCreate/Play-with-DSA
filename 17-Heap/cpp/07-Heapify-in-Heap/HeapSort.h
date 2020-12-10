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
};