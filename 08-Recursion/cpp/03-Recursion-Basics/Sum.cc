#include <iostream>

using namespace std;

class Sum {
 public:
  static int sum(int arr[], int n) { return sum(arr, n, 0); }

  // 计算arr[l...n)这个区间内所有数字的和
  static int sum(int arr[], int n, int l) {
    if (l == n) {
      return 0;
    }
    return arr[l] + sum(arr, n, l + 1);
  }
};

int main() {
  int arr[] = {1, 2, 3};
  cout << Sum::sum(arr, sizeof(arr) / sizeof(int)) << endl;
  return 0;
}