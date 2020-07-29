#pragma once

#include <cstdlib>
#include <ctime>
class ArrayGenerator {
 public:
  ArrayGenerator() = delete;

  static int *generateOrderedArray(int n);

  static int *generateRandomArray(int n, int bound);
};

int *ArrayGenerator::generateOrderedArray(int n) {
  int *data = new int[n];
  for (int i = 0; i < n; ++i) data[i] = i;
  return data;
}
int *ArrayGenerator::generateRandomArray(int n, int bound) {
  srand(time(0));
  int *data = new int[n];
  for (int i = 0; i < n; ++i) data[i] = rand() % bound;
  return data;
}
