#pragma once

class LinearSearch {
 public:
  LinearSearch() = delete;

  static int search(int data[], int length, int target);
};

int LinearSearch::search(int data[], int length, int target) {
  for (int i = 0; i < length; ++i) {
    if (data[i] == target) return i;
  }
  return -1;
}
