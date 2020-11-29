#include <algorithm>
#include <iostream>
#include "ArrayGenerator.h"
#include "MergeSort.h"
#include "QuickSort.h"
#include "SortingHelper.h"

using namespace std;

int main() {
  int n = 1000000;

  cout << "Random Array : " << endl;

  int* arr = ArrayGenerator::generateRandomArray(n, n);
  int* arr2 = new int[n];
  std::copy(arr, arr + n, arr2);

  SortingHelper::sortTest("MergeSort", MergeSort::sort, arr, n);
  SortingHelper::sortTest("QuickSort", QuickSort::sort, arr2, n);

  delete[] arr;
  delete[] arr2;

  return 0;
}