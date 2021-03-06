#include <algorithm>
#include <iostream>
#include "ArrayGenerator.h"
#include "SortingHelper.h"
#include "MergeSort.h"

using namespace std;

int main()
{
    int n = 1000000;

    cout << "Random Array : " << endl;

    int* arr = ArrayGenerator::generateRandomArray(n, n);
    int* arr2 = new int[n];
    std::copy(arr, arr + n, arr2);

    SortingHelper::sortTest("MergeSort", MergeSort::sort, arr, n);
    SortingHelper::sortTest("MergeSort2", MergeSort::sort2, arr2, n);

    delete[] arr;
    delete[] arr2;

    cout << "Ordered Array : " << endl;

    arr = ArrayGenerator::generateOrderedArray(n);
    arr2 = new int[n];
    std::copy(arr, arr + n, arr2);

    SortingHelper::sortTest("MergeSort", MergeSort::sort, arr, n);
    SortingHelper::sortTest("MergeSort2", MergeSort::sort2, arr2, n);

    delete[] arr;
    delete[] arr2;

    return 0;
}