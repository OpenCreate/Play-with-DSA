class Solution {
 public:
  int findKthLargest(vector<int> &nums, int k) {
    return selectK(nums, nums.size() - k);
  }

  //返回第k大的元素
  int selectK(vector<int> &arr, int k) {
    int l = 0, r = arr.size() - 1;
    //循环不变量在arr[l,r]中找第k大元素
    while (l <= r) {
      int p = partition(arr, l, r);
      if (p == k) return arr[p];
      if (p < k)
        l = p + 1;
      else
        r = p - 1;
    }

    throw runtime_error("No solution");
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