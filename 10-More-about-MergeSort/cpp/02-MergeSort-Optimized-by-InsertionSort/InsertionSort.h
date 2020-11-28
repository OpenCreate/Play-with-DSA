#pragma once

class InsertionSort {
 public:
  InsertionSort() = delete;

  template <typename T>
  static void sort(T arr[], int length) {
    for (int i = 0; i < length; ++i) {
      // arr[0,i)有序  arr[i,n)无序， 将arr[i] 插入到合适的位置去
      T t = arr[i];
      int j;  //应该插入的位置,使用直接赋值替换交换
      for (j = i; j - 1 >= 0 && t < arr[j - 1]; --j) {
        arr[j] = arr[j - 1];
      }
      arr[j] = t;
    }
  }
};
