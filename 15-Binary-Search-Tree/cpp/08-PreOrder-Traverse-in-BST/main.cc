#include <iostream>
#include "BST.h"

using namespace std;

int main() {
  int nums[] = {5, 3, 6, 8, 4, 2};
  BST<int> bst;

  for (auto e : nums) bst.add(e);

  bst.preOrder();
  return 0;
}