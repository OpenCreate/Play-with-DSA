#pragma once

class ArrayGenerator {
 public:
  ArrayGenerator() = delete;

  static int *generateOrderedArray(int n);
};

int *ArrayGenerator::generateOrderedArray(int n) {
  int *data_ = new int[n];
  for (int i = 0; i < n; ++i) data_[i] = i;
  return data_;
}