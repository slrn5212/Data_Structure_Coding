#include<iostream>
#include<string>
#include<algorithm>
#include"SortMethod.h"
#include"SortTestHelp.h"

using namespace std;


int main() {
	int n = 100000;
	int* arr = SortTestHelper::generateRandomArray(n, 0, 10);
	int *arr2 = SortTestHelper::copyIntArray(arr, n);

	SortTestHelper::testSort("Binary Insertion Sort", quickSort, arr, n);
	SortTestHelper::testSort("Merge Sort", mergeSort, arr2, n);

	delete[] arr;
	delete[] arr2;
	cout << endl;
}