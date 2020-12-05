// https://leetcode-cn.com/problems/capacity-to-ship-packages-within-d-days/
class Solution {
 public:
  int shipWithinDays(vector<int>& weights, int D) {
    //最少一天运完，最多是每天只运一个包裹
    auto max = max_element(weights.begin(), weights.end());
    int l = *max;
    int r = accumulate(weights.begin(), weights.end(), 0);
    while (l < r) {
      int mid = l + (r - l) / 2;
      if (days(weights, mid) <= D)
        r = mid;
      else  // days(weights, mid) > D
        l = mid + 1;
    }
    return l;
  }

 private:
  //返回每天运送重量为k的包裹，需要花费的天数
  int days(vector<int>& weights, int k) {
    int res = 0, cur = 0;
    for (auto e : weights) {
      if (cur + e <= k)
        cur += e;
      else {
        res++;
        cur = e;
      }
    }
    // 最后还要做一次 res ++，cur 还记录着最后一天需要运送的货物重量
    // 最后一天，要加到 res 中，所以 res ++
    res++;
    return res;
  }
};