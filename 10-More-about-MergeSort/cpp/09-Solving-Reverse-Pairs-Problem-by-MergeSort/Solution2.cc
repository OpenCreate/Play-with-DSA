#include <iostream>
#include <vector>

using namespace std;

class Solution2 {
 public:
  int reversePairs(vector<int> &nums) {
    int res = 0;
    vector<int> temp(nums);
    res = sort(nums, 0, nums.size() - 1, temp);
    return res;
  }

 private:
  int sort(vector<int> &nums, int l, int r, vector<int> &temp) {
    if (l >= r) return 0;
    int mid = l + (r - l) / 2;
    int res = 0;
    res += sort(nums, l, mid, temp);
    res += sort(nums, mid + 1, r, temp);
    if (nums[mid] > nums[mid + 1]) res += merge(nums, l, mid, r, temp);

    return res;
  }

  int merge(vector<int> &nums, int l, int mid, int r, vector<int> &temp) {
    copy(nums.begin() + l, nums.begin() + r + 1, temp.begin() + l);
    int i = l, j = mid + 1;
    int res = 0;
    for (int k = l; k <= r; k++) {
      if (i > mid) {
        nums[k] = temp[j];
        j++;
      } else if (j > r) {
        nums[k] = temp[i];
        i++;
      } else if (temp[i] > temp[j]) {
        res += mid - i + 1;
        nums[k] = temp[j];
        j++;
      } else {
        nums[k] = temp[i];
        i++;
      }
    }

    return res;
  }
};

int main() {
  vector<int> vec{7, 5, 6, 4};
  cout << Solution2().reversePairs(vec) << endl;

  return 0;
}