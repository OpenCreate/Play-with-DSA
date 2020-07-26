#pragma once

class LinearSearch {
 public:
  LinearSearch() = delete;

  template <typename T>
  static int search(T data[], int length, T target);
};

template <typename T>
int LinearSearch::search(T data[], int length, T target) {
  for (int i = 0; i < length; ++i) {
    if (data[i] == target)  // c++ has operator overloading
      return i;
  }
  return -1;
}
