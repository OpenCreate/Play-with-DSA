// https://leetcode-cn.com/problems/binary-search/
class Solution {
 public:
  int search(vector<int>& nums, int target) {
    int l = 0, r = nums.size();
    //循环不变量 arr[l,r)
    while (l < r) {
      int mid = l + (r - l) / 2;
      if (nums[mid] == target)
        return mid;
      else if (nums[mid] < target)
        l = mid + 1;
      else
        r = mid;  // arr[l,mid)
    }

    return -1;
  }
};
