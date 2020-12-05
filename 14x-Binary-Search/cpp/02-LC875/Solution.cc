// https://leetcode-cn.com/problems/koko-eating-bananas/

class Solution {
 public:
  int minEatingSpeed(vector<int>& piles, int H) {
    //利用二分查找法的思想
    //左边界，每小时吃max(piles)根，右边界，每小时吃1根

    int l = 1;
    auto m = max_element(piles.begin(), piles.end());
    int r = *m;
    while (l < r) {
      int mid = l + (r - l) / 2;
      if (eatingTime(piles, mid) <= H) {
        r = mid;
      } else {
        // eatingTime(piles, mid) > H,如果以mid速度吃不完，则往右边找，速度更快
        l = mid + 1;
      }
    }
    return l;
  }

 private:
  //返回每小时吃k根，吃完vec中所有香蕉所用的时间
  int eatingTime(vector<int>& vec, int k) {
    int res = 0;
    for (auto e : vec) {
      res += e / k + (e % k > 0 ? 1 : 0);
    }
    return res;
  }
};