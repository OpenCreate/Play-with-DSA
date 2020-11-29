#include <algorithm>
#include <iostream>
#include "ArrayGenerator.h"
#include "QuickSort.h"
#include "SortingHelper.h"

using namespace std;

int main() {
  int n = 50000;

  cout << "Random Array : " << endl;

  int* arr = ArrayGenerator::generateRandomArray(n, n);
  int* arr2 = new int[n];
  std::copy(arr, arr + n, arr2);

  SortingHelper::sortTest("QuickSort", QuickSort::sort, arr, n);
  SortingHelper::sortTest("QuickSort2", QuickSort::sort2, arr2, n);

  delete[] arr;
  delete[] arr2;

  cout << "Ordered Array : " << endl;

  int* arr3 = ArrayGenerator::generateOrderedArray(n);
  int* arr4 = new int[n];
  std::copy(arr3, arr3 + n, arr4);

  SortingHelper::sortTest("QuickSort", QuickSort::sort, arr3, n);
  SortingHelper::sortTest("QuickSort2", QuickSort::sort2, arr4, n);

  delete[] arr3;
  delete[] arr4;

  return 0;
}