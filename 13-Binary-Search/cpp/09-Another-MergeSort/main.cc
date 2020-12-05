#include <algorithm>
#include <iostream>
#include "ArrayGenerator.h"
#include "MergeSort.h"
#include "SortingHelper.h"

using namespace std;

int main() {
  int n = 5000000;

  cout << "Random Array : " << endl;

  int* arr = ArrayGenerator::generateRandomArray(n, n);

  SortingHelper::sortTest("MergeSort", MergeSort::sort, arr, n);

  delete[] arr;

  return 0;
}