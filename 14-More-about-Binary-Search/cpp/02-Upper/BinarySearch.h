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

  // > target的最小值的索引
  template <typename T>
  static int upper(T arr[], int n, T target) {
    //在arr[l,r]中求解，当l == r时已经求解出了结果
    int l = 0, r = n;
    while (l < r) {
      int mid = l + (r - l) / 2;
      if (target >= arr[mid])
        l = mid + 1;
      else
        r = mid;
    }

    return l;
  }
};
