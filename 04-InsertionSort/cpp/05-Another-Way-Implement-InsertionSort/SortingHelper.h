#pragma once

#include <iostream>
#include <string>

class SortingHelper {
 public:
  SortingHelper() = delete;

  template <typename T>
  static bool isSorted(T arr[], int length);

  template <typename T>
  static void sortTest(const std::string& sortName,
                       void (*sortFunc)(T arr[], int), T arr[], int length);
};

template <typename T>
bool SortingHelper::isSorted(T arr[], int length) {
  for (int i = 1; i < length; ++i) {
    if (arr[i - 1] > arr[i]) return false;
  }
  return true;
}

template <typename T>
void SortingHelper::sortTest(const std::string& sortName,
                             void (*sortFunc)(T arr[], int), T arr[],
                             int length) {
  clock_t startTime = clock();
  sortFunc(arr, length);
  clock_t endTime = clock();
  double time = static_cast<double>(endTime - startTime) / CLOCKS_PER_SEC;
  if (!SortingHelper::isSorted(arr, length))
    throw std::runtime_error("sort faild");
  std::cout << sortName << ":" << time << "s" << std::endl;
}
