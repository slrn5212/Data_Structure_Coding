#pragma once
#ifndef SORTITEM_H


#include<iostream>
#include<string>
using namespace std;

struct Student
{
	string name;
	int score;

	//重载小于
	bool operator<(const Student &otherStudent) {
		//return score > otherStudent.score;
		return score != otherStudent.score ?
			score > otherStudent.score : name < otherStudent.name;
	}

	//重载输出
	friend ostream& operator<<(ostream &os, const Student &student) {
		os << "Student: " << student.name << " " << student.score << endl;
		return os;
	}
};

#endif // !SORTITEM_H
