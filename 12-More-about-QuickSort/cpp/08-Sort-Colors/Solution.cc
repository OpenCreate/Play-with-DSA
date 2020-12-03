// Leetcode 75
//给定一个包含红色、白色和蓝色，一共 n
//个元素的数组，原地对它们进行排序，使得相同颜色的元素相邻，并按照红色、白色、蓝色顺序排列。
//此题中，我们使用整数 0、 1 和 2 分别表示红色、白色和蓝色。

class Solution {
 public:
  void sortColors(vector<int>& nums) {
    // a[0..zero] = 0, a[zero+1..i] = 1, a[two..n-1] = 2;
    int zero = -1;
    int i = 0;
    int two = nums.size();
    while (i < two) {
      if (nums[i] == 0) {
        zero++;
        swap(nums[zero], nums[i]);
        i++;
      } else if (nums[i] == 2) {
        two--;
        std::swap(nums[i], nums[two]);
      } else {
        // nums[i] == 1;
        i++;
      }
    }
  }
};