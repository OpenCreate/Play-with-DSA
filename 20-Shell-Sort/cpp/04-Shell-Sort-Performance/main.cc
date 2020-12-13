#include <iostream>
#include "ArrayGenerator.h"
#include "MergeSort.h"
#include "ShellSort.h"
#include "SortingHelper.h"

int main() {
  int n = 1000000;
  int *arr = ArrayGenerator::generateRandomArray(n, n);
  int *arr2 = new int[n];

  std::copy(arr, arr + n, arr2);

  SortingHelper::sortTest("MergeSort", MergeSort::sort, arr, n);
  SortingHelper::sortTest("ShellSort", ShellSort::sort, arr2, n);

  delete[] arr;
  delete[] arr2;

  return 0;
}
