#pragma once

#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

class MergeSort {
 public:
  MergeSort() = delete;

  template <typename T>
  static void sort(T arr[], int n) {
    sort(arr, 0, n - 1, 0, n);
  }

 private:
  template <typename T>
  static void sort(T arr[], int l, int r, int depth, int n) {
    // 生成深度字符串
    string depthString = generateDepthString(depth);

    // 打印当前 sort 处理的数组区间信息
    cout << depthString;
    char buf[64];
    snprintf(buf, sizeof(buf), "mergesort arr[%d, %d]", l, r);
    cout << buf << endl;

    if (l >= r) return;
    int mid = l + (r - l) / 2;
    sort(arr, l, mid, depth + 1, n);
    sort(arr, mid + 1, r, depth + 1, n);

    cout << depthString;
    snprintf(buf, sizeof(buf), "merge arr[%d, %d] and arr[%d, %d]", l, mid,
             mid + 1, r);
    cout << buf << endl;

    merge(arr, l, mid, r);

    // 打印 merge 后的数组
    cout << depthString;
    snprintf(buf, sizeof(buf), "after mergesort arr[%d, %d] :", l, r);
    cout << buf << endl;

    for (int i = l; i < r; i++) cout << arr[i] << " ";
    cout << endl;
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

  static string generateDepthString(int depth) {
    string s;
    for (int i = 0; i < depth; i++) s += "--";
    return s;
  }
};
