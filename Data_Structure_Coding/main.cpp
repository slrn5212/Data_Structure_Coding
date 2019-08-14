#include<iostream>
#include<string>
#include<algorithm>
#include"SortMethod.h"
#include"SortTestHelp.h"

using namespace std;


int main() {
	int n = 10000;
	int* arr = SortTestHelper::generateNearlyOrderArray(n, 10);
	int *arr2 = SortTestHelper::copyIntArray(arr, n);
	//selectionSort(arr, n);
	//SortTestHelper::printArray(arr, n);
	SortTestHelper::testSort("Selection Sort", selectionSort, arr, n);
	SortTestHelper::testSort("Advanced Insertion Sort", AdvancedInsertionSort, arr2, n);


	delete[] arr;
	delete[] arr2;
	cout << endl;
}