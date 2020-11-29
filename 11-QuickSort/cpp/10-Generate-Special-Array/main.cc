#include <algorithm>
#include <iostream>
#include "ArrayGenerator.h"
#include "QuickSort.h"
#include "SortingHelper.h"

using namespace std;

int main() {
  int n = 100000;

  cout << "Random Array : " << endl;

  int *arr = ArrayGenerator::generateRandomArray(n, n);
  int *arr2 = new int[n];
  std::copy(arr, arr + n, arr2);

  SortingHelper::sortTest("QuickSort", QuickSort::sort, arr, n);
  SortingHelper::sortTest("QuickSort2", QuickSort::sort2, arr2, n);

  delete[] arr;
  delete[] arr2;

  cout << "Ordered Array : " << endl;

  arr = ArrayGenerator::generateOrderedArray(n);
  arr2 = new int[n];
  std::copy(arr, arr + n, arr2);

  SortingHelper::sortTest("QuickSort", QuickSort::sort, arr, n);
  SortingHelper::sortTest("QuickSort2", QuickSort::sort2, arr2, n);

  delete[] arr;
  delete[] arr2;

  cout << "Special Array : " << endl;

  arr = ArrayGenerator::generateSpecialArray(n);
  arr2 = new int[n];
  std::copy(arr, arr + n, arr2);

  SortingHelper::sortTest("QuickSort", QuickSort::sort, arr, n);
  SortingHelper::sortTest("QuickSort2", QuickSort::sort2, arr2, n);

  delete[] arr;
  delete[] arr2;

  return 0;
}