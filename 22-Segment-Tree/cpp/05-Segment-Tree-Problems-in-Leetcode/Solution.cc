// https://leetcode-cn.com/problems/range-sum-query-immutable/

class NumArray {
 public:
  NumArray(vector<int>& nums) {
    // sum[i]存储前i个元素的和，nums[0....i-1]这个区间的和
    sum.resize(nums.size() + 1);
    sum[0] = 0;
    for (int i = 1; i < sum.size(); ++i) {
      sum[i] = sum[i - 1] + nums[i - 1];
    }
  }

  int sumRange(int i, int j) { return sum[j + 1] - sum[i]; }

 private:
  vector<int> sum;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(i,j);
 */