#include <iostream>

namespace {
void selectionSort(int arr[], int length) {
  for (int i = 0; i < length; ++i) {
    //寻找在arr[i,n)最小值所对应的索引
    int minIndex = i;
    for (int j = i; j < length; ++j) {
      if (arr[j] < arr[minIndex]) minIndex = j;
    }
    std::swap(arr[i], arr[minIndex]);
  }
}
}  // namespace

int main() {
  int data[] = {7, 4, 3, 5, 2, 1, 6};
  selectionSort(data, sizeof(data) / sizeof(int));
  for (auto e : data) std::cout << e << " ";
  return 0;
}
