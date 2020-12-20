#include "SegmentTree.h"

using namespace std;
int main() {
  vector<int> nums = {-2, 0, 3, -5, 2, -1};

  SegmentTree<int> segTree(nums, [](int a, int b) { return a + b; });

  cout << segTree << endl;
  cout << segTree.query(0, 2) << "\t";
  cout << segTree.query(2, 5) << "\t";
  cout << segTree.query(0, 5) << endl;

  segTree.set(0, 2);

  cout << segTree.query(0, 5) << endl;

  return 0;
}