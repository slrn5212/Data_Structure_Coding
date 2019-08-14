#pragma once
#ifndef SORTHEADER_SELECT_H

#include<iostream>
#include<string>
using namespace std;

/*
*	Selection Sort
*/
template<typename T>
void selectionSort(T arr[], int n) {
	for (int i = 0;i < n;i++) {
		int minIndex = i;
		for (int j = i + 1;j < n;j++) {
			if (arr[j] < arr[minIndex])
				minIndex = j;
		}
		swap(arr[i], arr[minIndex]);
	}
}

// From both ends to exchange the elements in original array, it's a better solution optimize the previous Selection Sort.
template<typename T>
void AdvancedselectionSort(T arr[], int n) {

	int left = 0, right = n - 1;
	while (left < right) {
		int minIndex = left;
		int maxIndex = right;

		// In each rounds must assure arr[minIndex] <= arr[maxIndex]
		if (arr[minIndex] > arr[maxIndex])
			swap(arr[minIndex], arr[maxIndex]);

		//Traversing the array to choose the match positon.
		for (int i = left + 1; i < right; i++)
			if (arr[i] < arr[minIndex])
				minIndex = i;
			else if (arr[i] > arr[maxIndex])
				maxIndex = i;

		swap(arr[left], arr[minIndex]);
		swap(arr[right], arr[maxIndex]);

		left++;
		right--;
	}

	return;
}


/*
*	BubbleSort
*/
template<typename T>
void BubbleSort(T arr[], int n) {

	bool swapped;

	do {
		swapped = false;
		for (int i = 1; i < n; i++)
			if (arr[i - 1] > arr[i]) {
				swap(arr[i - 1], arr[i]);
				swapped = true;

			}

		// 优化, 每一趟Bubble Sort都将最大的元素放在了最后的位置
		// 所以下一次排序, 最后的元素可以不再考虑
		n--;

	} while (swapped);
}


// 我们的第二版bubbleSort,使用newn进行优化
template<typename T>
void AdvancedBubbleSort(T arr[], int n) {

	int newn; // 使用newn进行优化

	do {
		newn = 0;
		for (int i = 1; i < n; i++)
			if (arr[i - 1] > arr[i]) {
				swap(arr[i - 1], arr[i]);

				// 记录最后一次的交换位置,在此之后的元素在下一轮扫描中均不考虑
				newn = i;
			}
		n = newn;
	} while (newn > 0);
}

/*
*	ShellSort
*/
template<typename T>
void shellSort(T arr[], int n) {

	// 计算 increment sequence: 1, 4, 13, 40, 121, 364, 1093...
	int h = 1;
	while (h < n / 3)
		h = 3 * h + 1;

	while (h >= 1) {

		// h-sort the array
		for (int i = h; i < n; i++) {

			// 对 arr[i], arr[i-h], arr[i-2*h], arr[i-3*h]... 使用插入排序
			T e = arr[i];
			int j;
			for (j = i; j >= h && e < arr[j - h]; j -= h)
				arr[j] = arr[j - h];
			arr[j] = e;
		}

		h /= 3;
	}
}

/*
*	Insertion Sort do well in nearly ordered list or having lots of same elements list.
*/
template<typename T>
void InsertionSort(T arr[], int n) {
	for (int i = 1;i < n;i++) {

		// Find right position.
		for (int j = i;j > 0 && arr[j] < arr[j - 1];j--) {
			swap(arr[j], arr[j - 1]);
		}
	}
}


template<typename T>
void AdvancedInsertionSort(T arr[], int n) {
	for (int i = 1;i < n;i++) {

		// Find right position without exchange frequently.
		T e = arr[i];
		int j;
		for (j = i;j > 0 && arr[j - 1] > e;j--) {
			arr[j] = arr[j - 1];
		}
		arr[j] = e;
	}
}


#endif // !SORTHEADER_SELECT_H
