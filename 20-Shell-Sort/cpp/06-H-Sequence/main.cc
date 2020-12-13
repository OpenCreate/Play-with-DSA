#include <iostream>
#include "ArrayGenerator.h"
#include "ShellSort.h"
#include "SortingHelper.h"

int main() {
  int n = 5000000;
  int *arr = ArrayGenerator::generateRandomArray(n, n);
  int *arr2 = new int[n];

  std::copy(arr, arr + n, arr2);

  SortingHelper::sortTest("ShellSort", ShellSort::sort, arr, n);
  SortingHelper::sortTest("ShellSort2", ShellSort::sort2, arr2, n);

  delete[] arr;
  delete[] arr2;

  return 0;
}
