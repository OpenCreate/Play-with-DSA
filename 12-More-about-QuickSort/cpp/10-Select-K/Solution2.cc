
//https://leetcode-cn.com/problems/kth-largest-element-in-an-array/
class Solution {
 public:
  int findKthLargest(vector<int> &nums, int k) {
    return selectK(nums, 0, nums.size() - 1, nums.size() - k);
  }

  //返回第k大的元素的索引
  int selectK(vector<int> &arr, int l, int r, int k) {
    int p = partition(arr, l, r);

    if (k == p) return arr[p];
    if (k < p) return selectK(arr, l, p - 1, k);
    return selectK(arr, p + 1, r, k);
  }
  //对arr[l,n]的元素进行partition
  int partition(vector<int> &arr, int l, int r) {
    int p = (rand() % (r - l + 1)) + l;
    swap(arr[l], arr[p]);

    // [l + 1, i - 1] <= v, [j + 1, r] >= v
    int i = l + 1, j = r;
    while (true) {
      while (i <= j && arr[i] < arr[l]) {
        i++;
      }
      while (i <= j && arr[j] > arr[l]) {
        j--;
      }

      if (i >= j) break;

      swap(arr[i], arr[j]);
      i++;
      j--;
    }

    swap(arr[l], arr[j]);
    return j;
  }
};