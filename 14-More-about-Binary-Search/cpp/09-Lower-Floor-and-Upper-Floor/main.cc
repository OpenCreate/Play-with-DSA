#include <iostream>
#include "BinarySearch.h"
using namespace std;

int main() {
  int arr[] = {1, 1, 3, 3, 5, 5};
  for (int i = 0; i <= 6; ++i) {
    cout << BinarySearch::upper(arr, 6, i) << " ";
  }
  cout << endl;

  for (int i = 0; i <= 6; ++i) {
    cout << BinarySearch::ceil(arr, 6, i) << " ";
  }
  cout << endl;

  for (int i = 0; i <= 6; ++i) {
    cout << BinarySearch::lower_ceil(arr, 6, i) << " ";
  }
  cout << endl;

  for (int i = 0; i <= 6; ++i) {
    cout << BinarySearch::lower_ceil2(arr, 6, i) << " ";
  }
  cout << endl;

  for (int i = 0; i <= 6; ++i) {
    cout << BinarySearch::lower(arr, 6, i) << " ";
  }
  cout << endl;

  for (int i = 0; i <= 6; ++i) {
    cout << BinarySearch::lower_floor(arr, 6, i) << " ";
  }
  cout << endl;

  for (int i = 0; i <= 6; ++i) {
    cout << BinarySearch::uppper_floor(arr, 6, i) << " ";
  }
  cout << endl;
  return 0;
}
