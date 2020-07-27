#include <ctime>
#include <iostream>
#include <string>
#include "ArrayGenerator.h"
#include "LinearSearch.h"

using namespace std;

int main() {
  int dataSize[] = {1000000, 10000000};

  for (auto n : dataSize) {
    int *data = ArrayGenerator::generateOrderedArray(n);
    clock_t startTime = clock();
    for (int k = 0; k < 100; ++k) LinearSearch::search(data, n, n);
    clock_t endTime = clock();
    double time = static_cast<double>(endTime - startTime) / CLOCKS_PER_SEC;
    cout << "n = " << n << ", 100 runs :" << time << "s" << endl;
    delete[] data;
  }

  return 0;
}
