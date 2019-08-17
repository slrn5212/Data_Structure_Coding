#include<iostream>
#include<string>
#include<algorithm>
#include"SortMethod.h"
#include"SortTestHelp.h"
#include"SortItem.h"
using namespace std;


int main() {
	int n = 100000;
	int* arr = SortTestHelper::generateRandomArray(n, 0, 10);
	int *arr2 = SortTestHelper::copyIntArray(arr, n);

	SortTestHelper::testSort("Heap Sort", HeapSort, arr, n);
	SortTestHelper::testSort("Heap Sort-2", heapSort2, arr2, n);

	delete[] arr;
	delete[] arr2;
	cout << endl;
	
}