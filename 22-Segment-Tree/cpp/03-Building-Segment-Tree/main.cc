#include "SegmentTree.h"

using namespace std;
int main() {
  vector<int> nums = {-3, 0, 3, -9, 2, -1, 66};

  SegmentTree<int> segTree(nums, [](int a, int b) { return a + b; });

  cout << segTree << endl;

  return 0;
}