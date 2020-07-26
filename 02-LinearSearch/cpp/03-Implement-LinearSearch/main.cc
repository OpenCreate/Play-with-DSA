#include <iostream>
#include "LinearSearch.h"

using namespace std;

int main() {
  int data[] = {22, 33, 15, 8, 79, 12, 90, 66, 5};

  int res = LinearSearch::search(data, sizeof(data) / sizeof(int), 15);
  cout << res << endl;

  int res2 = LinearSearch::search(data, sizeof(data) / sizeof(int), 1024);
  cout << res2 << endl;

  return 0;
}
