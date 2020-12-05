#pragma once

class BinarySearch {
 public:
  BinarySearch() = delete;

  template <typename T>
  static int search(T arr[], int n, T target) {
    int l = 0, r = n - 1;
    //循环不变量  在arr[l,r]中查找target
    while (l <= r) {
      int mid = l + (r - l) / 2;
      if (arr[mid] == target)
        return mid;
      else if (arr[mid] < target) {
        l = mid + 1;
      } else {
        r = mid - 1;
      }
    }

    return -1;
  }

  template <typename T>
  static int searchR(T arr[], int n, T target) {
    return search(arr, n, 0, n - 1, target);
  }

 private:
  template <typename T>
  static int searchR(T arr[], int l, int r, T target) {
    if (l > r) return -1;
    int mid = l + (r - l) / 2;

    if (arr[mid] == target) return mid;
    if (arr[mid] > target) return search(arr, l, mid - 1, target);
    return search(arr, mid + 1, r, target);
  }
};
