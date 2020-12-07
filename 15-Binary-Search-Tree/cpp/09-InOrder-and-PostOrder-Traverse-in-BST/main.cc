#include <iostream>
#include "BST.h"
using namespace std;

int main() {
  BST<int> bst;
  int nums[] = {5, 3, 6, 8, 4, 2};

  for (auto e : nums) {
    bst.add(e);
  }

  bst.preOrder();
  cout << endl;
  bst.inOrder();
  cout << endl;
  bst.postOrder();

  return 0;
}
