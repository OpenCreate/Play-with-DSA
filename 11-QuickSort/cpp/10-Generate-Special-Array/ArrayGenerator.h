#pragma once

#include <cstdlib>
#include <ctime>
class ArrayGenerator {
 public:
  ArrayGenerator() = delete;

  static int *generateOrderedArray(int n);

  static int *generateRandomArray(int n, int bound);

  static int *generateSpecialArray(int n);

 private:
  static void generateSpecialArray(int arr[], int l, int r, int value);
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

int *ArrayGenerator::generateSpecialArray(int n) {
  int *arr = new int[n];
  //生成arr[0...n-1]的测试用例，其中最小值是0
  generateSpecialArray(arr, 0, n, 0);
  return arr;
}

void ArrayGenerator::generateSpecialArray(int arr[], int l, int r, int value) {
  if (l >= r) return;
  int mid = l + (r - l) / 2;
  arr[mid] = value;
  //模拟partition过程
  std::swap(arr[l], arr[mid]);
  generateSpecialArray(arr, l + 1, r, value + 1);
  //处理好后交换回来
  std::swap(arr[l], arr[mid]);
}
