// https://leetcode-cn.com/problems/intersection-of-two-arrays-ii/

class Solution {
 public:
  vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
    map<int, int> m;
    for (auto e : nums1) m[e]++;
    vector<int> res;
    for (auto e : nums2) {
      auto it = m.find(e);
      if (it != m.end()) {
        res.push_back(e);
        if (--m[e] == 0) m.erase(e);
      }
    }
    return res;
  }
};