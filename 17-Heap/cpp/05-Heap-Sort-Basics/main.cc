#include <iostream>
#include "ArrayGenerator.h"
#include "HeapSort.h"
#include "MergeSort.h"
#include "QuickSort.h"
#include "SortingHelper.h"

using namespace std;

int main() {
  int n = 1000000;

  cout << "Random Array : " << endl;

  int *arr = ArrayGenerator::generateRandomArray(n, n);
  int *arr2 = new int[n];
  int *arr3 = new int[n];
  std::copy(arr, arr + n, arr2);
  std::copy(arr, arr + n, arr3);

  SortingHelper::sortTest("MergeSort", MergeSort::sort, arr, n);
  SortingHelper::sortTest("QuickSort", QuickSort::sort, arr2, n);
  SortingHelper::sortTest("HeapSort", HeapSort::sort, arr3, n);

  delete[] arr;
  delete[] arr2;
  delete[] arr3;

  return 0;
}
