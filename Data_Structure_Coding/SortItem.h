#pragma once
#ifndef SORTITEM_H


#include<iostream>
#include<string>
#include<assert.h>
using namespace std;

struct Student
{
	string name;
	int score;

	//����С��
	bool operator<(const Student &otherStudent) {
		//return score > otherStudent.score;
		return score != otherStudent.score ?
			score > otherStudent.score : name < otherStudent.name;
	}

	//�������
	friend ostream& operator<<(ostream &os, const Student &student) {
		os << "Student: " << student.name << " " << student.score << endl;
		return os;
	}
};


// Template Class
template<typename Item>
class MaxHeap {

private:
	Item* data;
	int count;
	int capacity;

	void shiftUp(int k) {
		while (k > 1 && data[k/2] < data[k])
		{
			swap(data[k / 2], data[k]);
			k /= 2;
		}
	}

	void shiftDown(int k) {
		while (2 * k <= count) {
			int j = 2 * k; // �ڴ���ѭ����,data[k]��data[j]����λ��
			if (j + 1 <= count && data[j + 1] > data[j])
				j++;
			// data[j] �� data[2*k]��data[2*k+1]�е����ֵ

			if (data[k] >= data[j]) 
				break;
			
			swap(data[k], data[j]);
			k = j;
		}
	}

	void putNumberInLine(int num, string &line, int index_cur_level, int cur_tree_width, bool isLeft) {

		int sub_tree_width = (cur_tree_width - 1) / 2;
		int offset = index_cur_level * (cur_tree_width + 1) + sub_tree_width;
		assert(offset + 1 < line.size());
		if (num >= 10) {
			line[offset + 0] = '0' + num / 10;
			line[offset + 1] = '0' + num % 10;
		}
		else {
			if (isLeft)
				line[offset + 0] = '0' + num;
			else
				line[offset + 1] = '0' + num;
		}
	}

	void putBranchInLine(string &line, int index_cur_level, int cur_tree_width) {

		int sub_tree_width = (cur_tree_width - 1) / 2;
		int sub_sub_tree_width = (sub_tree_width - 1) / 2;
		int offset_left = index_cur_level * (cur_tree_width + 1) + sub_sub_tree_width;
		assert(offset_left + 1 < line.size());
		int offset_right = index_cur_level * (cur_tree_width + 1) + sub_tree_width + 1 + sub_sub_tree_width;
		assert(offset_right < line.size());

		line[offset_left + 1] = '/';
		line[offset_right + 0] = '\\';
	}

public:
	//Original Process  O(nlogn)
	MaxHeap(int capacity) {
		data = new Item[capacity + 1];	//Index begin in the '1' place.
		count = 0;
		this->capacity = capacity;
	}

	//Heapify Process   O(n)
	MaxHeap(Item arr[], int n) {

		data = new Item[n + 1];
		capacity = n;
		for (int i = 0;i < n;i++) {
			data[i + 1] = arr[i];
		}
		count = n;
		for (int i = count / 2;i >= 1;i--)
			shiftDown(i);
	}

	~MaxHeap() {
		delete[] data;
	}

	int size() {
		return count;
	}

	bool isEmpty() {
		return count == 0;
	}

	// Insert - ShiftUp
	void insert(Item item) {
		assert(count + 1 <= capacity);
		data[count + 1] = item;
		count++;
		shiftUp(count);
	}

	// Return Max Number - ShiftDown
	Item extractMax() {
		assert(count > 0);
		Item ret = data[1];
		swap(data[1], data[count]);
		count--;
		shiftDown(1);

		return ret;
	}

	void testPrint() {

		// ���ǵ�testPrintֻ�ܴ�ӡ100��Ԫ�����ڵĶѵ���״��Ϣ
		if (size() >= 100) {
			cout << "This print function can only work for less than 100 int";
			return;
		}

		// ���ǵ�testPrintֻ�ܴ���������Ϣ
		if (typeid(Item) != typeid(int)) {
			cout << "This print function can only work for int item";
			return;
		}

		cout << "The max heap size is: " << size() << endl;
		cout << "Data in the max heap: ";
		for (int i = 1; i <= size(); i++) {
			// ���ǵ�testPrintҪ����е�����������[0, 100)�ķ�Χ��
			assert(data[i] >= 0 && data[i] < 100);
			cout << data[i] << " ";
		}
		cout << endl;
		cout << endl;

		int n = size();
		int max_level = 0;
		int number_per_level = 1;
		while (n > 0) {
			max_level += 1;
			n -= number_per_level;
			number_per_level *= 2;
		}

		int max_level_number = int(pow(2, max_level - 1));
		int cur_tree_max_level_number = max_level_number;
		int index = 1;
		for (int level = 0; level < max_level; level++) {
			string line1 = string(max_level_number * 3 - 1, ' ');

			int cur_level_number = min(count - int(pow(2, level)) + 1, int(pow(2, level)));
			bool isLeft = true;
			for (int index_cur_level = 0; index_cur_level < cur_level_number; index++, index_cur_level++) {
				putNumberInLine(data[index], line1, index_cur_level, cur_tree_max_level_number * 3 - 1, isLeft);
				isLeft = !isLeft;
			}
			cout << line1 << endl;

			if (level == max_level - 1)
				break;

			string line2 = string(max_level_number * 3 - 1, ' ');
			for (int index_cur_level = 0; index_cur_level < cur_level_number; index_cur_level++)
				putBranchInLine(line2, index_cur_level, cur_tree_max_level_number * 3 - 1);
			cout << line2 << endl;

			cur_tree_max_level_number /= 2;
		}
	}
};



#endif // !SORTITEM_H
