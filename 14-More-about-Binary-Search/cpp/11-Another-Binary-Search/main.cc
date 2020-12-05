#include <iostream>
#include "BinarySearch.h"
using namespace std;

int main() {
  int arr[] = {1, 1, 3, 3, 5, 5};
  for (int i = 0; i <= 6; ++i) {
    cout << BinarySearch::search2(arr, 6, i) << " ";
  }
  cout << endl;

 
  return 0;
}
