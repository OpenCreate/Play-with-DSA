#include "MergeSort.h"
#include "SortingHelper.h"

int main() {
  int arr[] = {7, 1, 4, 2, 8, 3, 6, 5};
  SortingHelper::sortTest("MergeSort", MergeSort::sort, arr,
                          sizeof(arr) / sizeof(int));

  return 0;
}
