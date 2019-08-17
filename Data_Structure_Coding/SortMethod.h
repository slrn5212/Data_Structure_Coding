#pragma once
#ifndef SORTHEADER_SELECT_H

#include<iostream>
#include<string>
#include"SortItem.h"
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
void OptimizedselectionSort(T arr[], int n) {

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
void OptimizedBubbleSort(T arr[], int n) {

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

//sorting arr[l ... r]
template<typename T>
void OptimizedInsertionSort(T arr[], int l, int r) {
	for (int i = l + 1; i <= r; i++) {
		T e = arr[i];
		int j;
		for (j = i; j > l && arr[j - 1] > e;j--) {
			arr[j] = arr[j - 1];
		}
		arr[j] = e;
	}
}

template<typename T>
void BinaryInsertionSort(T arr[], int n) {
	int i, j, low, high, mid;
	for (i = 1;i < n;i++) {
		T e = arr[i];
		
		//Binary Searching in the ordered range of array.
		low = 0; high = i - 1;
		while (low<= high)
		{
			mid = (low + high) / 2;
			if (arr[mid] > e) high = mid - 1;
			else low = mid + 1;
		}
		//Moving elements.
		for (j = i - 1;j >= high + 1;--j) {
			arr[j + 1] = arr[j];
		}
		arr[high + 1] = e;
	}
}

template<typename T>
void OptimizedInsertionSort(T arr[], int n) {
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


/*
	Merge Sort
*/

// merge arr[l ... mid] and a[mid+1 ... r] into an array
template<typename T>
void __merge(T arr[], int l,int mid, int r) {

	T *aux = new T[r - l + 1];
	
	for (int i = l; i <= r;i++) {
		aux[i - l] = arr[i];
	}

	int i = l, j = mid + 1;
	for (int k = l;k <= r;k++) {
		if (i > mid) {
			arr[k] = aux[j - l];
			j++;
		}
		else if (j > r) {
			arr[k] = aux[i - l];
			i++;
		}
		else if (aux[i - l] < aux[j - l]) {
			arr[k] = aux[j - l];
			i++;
		}
		else {
			arr[k] = aux[j - l];
			j++;
		}
	}

	delete[] aux;
}


// 将arr[l...mid]和arr[mid+1...r]两部分进行归并
// 其中aux为完成merge过程所需要的辅助空间
template<typename  T>
void __merge2(T arr[], T aux[], int l, int mid, int r) {

	// 由于aux的大小和arr一样, 所以我们也不需要处理aux索引的偏移量
	// 进一步节省了计算量:)
	for (int i = l; i <= r; i++)
		aux[i] = arr[i];

	// 初始化，i指向左半部分的起始索引位置l；j指向右半部分起始索引位置mid+1
	int i = l, j = mid + 1;
	for (int k = l; k <= r; k++) {

		if (i > mid) {  // 如果左半部分元素已经全部处理完毕
			arr[k] = aux[j]; j++;
		}
		else if (j > r) {  // 如果右半部分元素已经全部处理完毕
			arr[k] = aux[i]; i++;
		}
		else if (aux[i] < aux[j]) {  // 左半部分所指元素 < 右半部分所指元素
			arr[k] = aux[i]; i++;
		}
		else {  // 左半部分所指元素 >= 右半部分所指元素
			arr[k] = aux[j]; j++;
		}
	}
}


//sort arr[l ... r]
template<typename T>
void __mergeSort(T arr[], int l, int r) {
	//if (l >= r) return;
	if (r - l <= 15) {
		OptimizedInsertionSort(arr, l, r);
		return;
	}
	int mid = (l + r) / 2;		// variable 'mid' may overflow
	__mergeSort(arr, l, mid);
	__mergeSort(arr, mid+1, r);
	if(arr[mid] > arr[mid+1])	// optimize in nearly ordered array.
		__merge(arr, l, mid, r);
}


template<typename T>
void mergeSort(T arr[], int n) {
	__mergeSort(arr, 0, n - 1);
}


template<typename T>
void mergeSortBottonToUp(T arr[], int n) {
	for(int size = 1; size <= n; size += size)
		for (int i = 0; i + size < n ; i += size + size) {
			// merge arr[i ... i+size-1] and arr[i+size ... i+2*size-1]
			__merge(arr, i, i + size - 1, min(i + size + size - 1, n-1));
		}
}


template <typename T>
void OptimizemergeSortBottonToUp(T arr[], int n) {

	// 对于小规模数组, 使用插入排序
	for (int i = 0; i < n; i += 16)
		OptimizedInsertionSort(arr, i, min(i + 15, n - 1));

	// 一次性申请aux空间, 并将这个辅助空间以参数形式传递给完成归并排序的各个子函数
	T* aux = new T[n];
	for (int sz = 16; sz <= n; sz += sz)
		for (int i = 0; i < n - sz; i += sz + sz)
			// 对于arr[mid] <= arr[mid+1]的情况,不进行merge
			// 对于近乎有序的数组非常有效,但是对于一般情况,有一定的性能损失
			if (arr[i + sz - 1] > arr[i + sz])
				__merge2(arr, aux, i, i + sz - 1, min(i + sz + sz - 1, n - 1));
	delete[] aux; // 使用C++, new出来的空间不要忘记释放掉:)
}


/*
	Quick Sort
*/
template <typename T>
int __partition2(T arr[], int l, int r) {
	swap(arr[l], arr[rand() % (r - l + 1) + l]);  // Add this process to randomly choose demarcating element.
	T v = arr[l];

	//arr[l+i ... j] < v; arr[j+1 ... i] > v
	int i = l + 1, j = r;
	while (true) {
		//From front to behind to find a even bigger number.
		//From behind to front to find a even smaller number.
		while (i <= r&& arr[i] < v) i++;
		while (j >= l + 1 && arr[j] > v) j--;
		if (i > j) break;
		swap(arr[i], arr[j]);
		i++;
		j--;
	}

	swap(arr[l], arr[j]);

	return j;
}

template <typename T>
int __partition(T arr[], int l, int r) {

	swap(arr[l], arr[rand() % (r - l + 1) + l]);  // Add this process to randomly choose demarcating element.
	T v = arr[l];
	
	//arr[l+i ... j] < v;arr[j+1 ... i] > v
	int j = l;
	for (int i = l + 1;i <= r;i++) {
		if (arr[i] < v) {
			swap(arr[j + 1], arr[i]);
			j++;
		}
	}

	swap(arr[l], arr[j]);
	return j;
}

// sort the range of [l ... r]
template <typename T>
void __quickSort(T arr[], int l, int r) {
	//if (l >= r) return;
	if (r - l <= 15) {
		OptimizedInsertionSort(arr, l, r);
		return;
	}
	int p = __partition(arr, l, r);
	__quickSort(arr, l, p - 1);
	__quickSort(arr, p + 1, r);
}

template <typename T>
void __quickSort2(T arr[], int l, int r) {
	//if (l >= r) return;
	if (r - l <= 15) {
		OptimizedInsertionSort(arr, l, r);
		return;
	}
	int p = __partition2(arr, l, r);
	__quickSort2(arr, l, p - 1);
	__quickSort2(arr, p + 1, r);
}

template <typename T>
void __quickSort3(T arr[], int l, int r) {
	//if (l >= r) return;
	if (r - l <= 15) {
		OptimizedInsertionSort(arr, l, r);
		return;
	}

	// partition
	swap(arr[l], arr[rand() % (r - l + 1) + l]);
	T v = arr[l];

	int lt = l;		//arr[l+1 ... lt] < v
	int gt = r + 1; //arr[gt ... r] > v
	int i = l + 1;	//arr[lt+1 ... i] == v
	while (i < gt) {
		if (arr[i] < v) {
			swap(arr[i], arr[lt + 1]);
			lt++;
			i++;
		}
		else if(arr[i] > v) {
			swap(arr[i], arr[gt - 1]);
			gt--;
		}
		else {// arr[i] == v
			i++;
		}
	}

	swap(arr[l], arr[lt]);

	__quickSort3(arr, l, lt - 1);
	__quickSort3(arr, gt, r);
}

template <typename T>
void quickSort(T arr[], int n) {
	srand(time(NULL));		// The partial of randomly select.
	__quickSort3(arr, 0, n - 1);
}


/*
	HeapSort
*/

//原地堆排序
template <typename T>
void __shifeDown(T arr[], int n, int k) {
	while (2 * k + 1 < n) {
		int j = 2 * k + 1; // 在此轮循环中,arr[k]和arr[j]交换位置
		if (j + 1 < n &&  arr[j + 1] > arr[j])
			j++;
		if (arr[k] >= arr[j])
			break;
		swap(arr[k], arr[j]);
		k = j;
	}
}


template <typename T>
void HeapSort(T arr[], int n) {

	for (int i = (n - 1) / 2;i >= 0;i--)
		__shifeDown(arr, n, i);

	for (int i = n - 1;i > 0;i--) {
		swap(arr[0], arr[i]);
		__shifeDown(arr, i, 0);
	}
}


template <typename T>
void heapSort1(T arr[], int n) {

	MaxHeap<T> maxheap = MaxHeap<T>(n);

	for (int i = 0;i < n;i++)
		maxheap.insert(arr[i]);

	for (int i = n - 1;i >= 0;i--)
		arr[i] = maxheap.extractMax();
		
}


//Heapify
template <typename T>
void heapSort2(T arr[], int n) {

	MaxHeap<T> maxheap = MaxHeap<T>(arr, n);
	for (int i = n - 1;i >= 0;i--)
		arr[i] = maxheap.extractMax();
}
#endif // !SORTHEADER_SELECT_H
