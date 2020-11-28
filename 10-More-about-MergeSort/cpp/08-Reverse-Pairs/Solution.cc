#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int reversePairs(vector<int>& nums) {
    int res = 0;
    for (int i = 0; i < nums.size(); ++i) {
      for (int j = i + 1; j < n; ++j) {
        if (nums[i] > nums[j]) res++;
      }
    }

    return res;
  }
};



int main(){
  clock_t startTime = clock();

  long n = 50000;
  for (long i = 0; i < n * n; ++i) int k = 1 + 1;

  clock_t endTime = clock();
  double time = static_cast<double>(endTime - startTime) / CLOCKS_PER_SEC;

  cout << time << "s" << endl;
  return 0;
}