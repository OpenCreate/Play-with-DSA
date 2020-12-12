// https://leetcode-cn.com/problems/kth-largest-element-in-an-array/

class Solution {
 public:
  int findKthLargest(vector<int>& nums, int k) {
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < k; ++i) pq.push(nums[i]);

    for (int i = k; i < nums.size(); ++i) {
      if (!pq.empty() && pq.top() < nums[i]) {
        pq.pop();
        pq.push(nums[i]);
      }
    }

    return pq.top();
  }
};