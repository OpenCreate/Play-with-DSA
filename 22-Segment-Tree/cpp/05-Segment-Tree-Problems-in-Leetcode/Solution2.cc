// https://leetcode-cn.com/problems/range-sum-query-mutable/

class NumArray {
 public:
  NumArray(vector<int>& nums) {
    sum.resize(nums.size() + 1);  // sum[i] 存储nums[0....i-1]的和
    sum[0] = 0;
    data = nums;
    for (int i = 1; i < sum.size(); ++i) sum[i] = sum[i - 1] + nums[i - 1];
  }

  void update(int i, int val) {
    data[i] = val;
    for (int k = i + 1; k < sum.size(); ++k) {
      sum[k] = sum[k - 1] + data[k - 1];
    }
  }

  int sumRange(int i, int j) { return sum[j + 1] - sum[i]; }

 private:
  vector<int> sum;
  vector<int> data;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(i,val);
 * int param_2 = obj->sumRange(i,j);
 */