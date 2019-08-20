#include <iostream>
#include <vector>
#include <string>
#include <time.h>
#include "SequencesST.h"
#include "FileOps.h"
#include "BinaryTree.h"
using namespace std;




// ���Զ�����������˳����ұ�֮������ܲ��
// ����������������ԶԶ����˳����ұ�
int main() {

	// ʹ��ʥ����Ϊ���ǵĲ�������
	string filename = "bible.txt";
	vector<string> words;
	if (FileOps::readFile(filename, words)) {

		cout << "There are totally " << words.size() << " words in " << filename << endl;
		cout << endl;


		// ���� BST
		time_t startTime = clock();

		// ͳ��ʥ�������дʵĴ�Ƶ
		// ע: �����Ƶͳ�Ʒ���Լ�ª, û�п��Ǻܶ��ı������е���������
		// ������ֻ�����ܲ�����
		BST<string, int> bst = BST<string, int>();
		for (vector<string>::iterator iter = words.begin(); iter != words.end(); iter++) {
			int *res = bst.search(*iter);
			if (res == NULL)
				bst.insert(*iter, 1);
			else
				(*res)++;
		}

		// ���ʥ����godһ�ʳ��ֵ�Ƶ��
		if (bst.contain("god"))
			cout << "'god' : " << *bst.search("god") << endl;
		else
			cout << "No word 'god' in " << filename << endl;

		time_t endTime = clock();

		cout << "BST , time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " s." << endl;
		cout << endl;


		// ����˳����ұ� SST
		startTime = clock();

		// ͳ��ʥ�������дʵĴ�Ƶ
		// ע: �����Ƶͳ�Ʒ���Լ�ª, û�п��Ǻܶ��ı������е���������
		// ������ֻ�����ܲ�����
		SequenceST<string, int> sst = SequenceST<string, int>();
		for (vector<string>::iterator iter = words.begin(); iter != words.end(); iter++) {
			int *res = sst.search(*iter);
			if (res == NULL)
				sst.insert(*iter, 1);
			else
				(*res)++;
		}

		// ���ʥ����godһ�ʳ��ֵ�Ƶ��
		if (sst.contain("god"))
			cout << "'god' : " << *sst.search("god") << endl;
		else
			cout << "No word 'god' in " << filename << endl;

		endTime = clock();

		cout << "SST , time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " s." << endl;
	}

	return 0;
}