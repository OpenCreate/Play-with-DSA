// https://leetcode-cn.com/problems/zui-xiao-de-kge-shu-lcof/

class Solution {
 public:
  vector<int> getLeastNumbers(vector<int>& arr, int k) {
    //思路1：用大顶堆
    //思路2：用快速排序
    priority_queue<int> pq;
    for (int i = 0; i < k; ++i) {
      pq.push(arr[i]);
    }

    for (int i = k; i < arr.size(); ++i) {
      if (!pq.empty() && pq.top() > arr[i]) {
        pq.pop();
        pq.push(arr[i]);
      }
    }

    vector<int> res;
    while (!pq.empty()) {
      res.push_back(pq.top());
      pq.pop();
    }

    return res;
  }
};