#pragma once
#ifndef SORTITEM_H


#include<iostream>
#include<string>
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

#endif // !SORTITEM_H
