#pragma once

class BinarySearch {
 public:
  BinarySearch() = delete;

  template <typename T>
  static int search(T arr[], int n, T target) {
    return search(arr, n, 0, n - 1, target);
  }

 private:
  template <typename T>
  static int search(T arr[], int l, int r, T target) {
    if (l > r) return -1;
    int mid = l + (r - l) / 2;

    if (arr[mid] == target) return mid;
    if (arr[mid] > target) return search(arr, l, mid - 1, target);
    return search(arr, mid + 1, r, target);
  }
};
