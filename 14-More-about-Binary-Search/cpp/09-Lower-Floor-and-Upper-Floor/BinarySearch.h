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

  // <= target的最大索引
  template <typename T>
  static int uppper_floor(T arr[], int n, T target) {
    int l = -1, r = n - 1;
    //在arr[l,r]中求解
    while (l < r) {
      int mid = l + (r - l + 1) / 2;  //需要采用向上取整的方法，思考为什么？
      if (arr[mid] <= target)
        l = mid;
      else  // arr[mid] > target
        r = mid - 1;
    }
    return l;
  }

  // == target,返回最小索引
  // < target,返回最大值索引
  template <typename T>
  static int lower_floor(T arr[], int n, T target) {
    int l = lower(arr, n, target);
    if (l + 1 < n && arr[l + 1] == target) return l + 1;
    return l;
  }

  // < target的最大索引
  template <typename T>
  static int lower(T arr[], int n, T target) {
    int l = -1, r = n - 1;
    while (l < r) {
      int mid = l + (r - l + 1) / 2;  //  (r-l)/2，当l,r相邻时 (r-l)/2 == 0,
                                      //  左边界一直未发生改变，导致死循环。
      if (arr[mid] >= target)
        r = mid - 1;
      else  // arr[mid] < target
        l = mid;
    }
    return l;
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

  // == target,返回最大的索引
  // > target,返回最小值的索引
  template <typename T>
  static int ceil(T arr[], int n, T target) {
    int u = upper(arr, n, target);
    if (u - 1 >= 0 && arr[u - 1] == target) return u - 1;
    return u;
  }

  // == target,返回最大的索引
  // > target, 返回最小值的索引
  template <typename T>
  static int upper_ceil(T arr[], int n, T target) {
    int u = upper(arr, n, target);
    if (u - 1 >= 0 && arr[u - 1] == target) return u - 1;
    return u;
  }

  // == target,返回最小的索引
  // > taret,返回最小值索引
  // >= target 的最小值索引
  template <typename T>
  static int lower_ceil(T arr[], int n, T target) {
    int l = 0, r = n;
    while (l < r) {
      int mid = l + (r - l) / 2;
      if (arr[mid] < target)
        l = mid + 1;
      else  // arr[mid] >= target
        r = mid;
    }
    return l;
  }

  // == target,返回最小索引
  // 不存在返回upper
  template <typename T>
  static int lower_ceil2(T arr[], int n, T target) {
    int u = upper(arr, n, target);
    while (true) {
      if (u - 1 >= 0 && arr[u - 1] == target)
        u--;
      else
        return u;
    }
  }
};
