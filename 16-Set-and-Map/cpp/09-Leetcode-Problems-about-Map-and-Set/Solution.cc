// https://leetcode-cn.com/problems/intersection-of-two-arrays/

class Solution {
 public:
  vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
    set<int> s(nums1.begin(), nums1.end());
    vector<int> res;
    for (auto e : nums2) {
      auto it = s.find(e);
      if (it != s.end()) {
        res.push_back(e);
        s.erase(e);
      }
    }

    return res;
  }
};