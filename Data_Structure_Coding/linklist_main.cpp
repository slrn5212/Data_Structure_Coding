//#include<iostream>
//#include<cstdio>
//#include<cstdlib>
//
//using namespace std;
//
//typedef struct node {
//	int data;
//	node* next;
//}Node, *Linklist;
//
//typedef struct Dnode
//{
//	int data;
//	Dnode *prior, *next;
//}Dnode, *DLinklist;
//
//#define MaxSize 50
//typedef struct SNode
//{
//	int data;
//	int next;
//}SLinkList[MaxSize];
//
///*
//*		���������
//*/
//
////�������鴴����
//node* create_LinkedList(int Array[], int n) {
//	node *p, *pre, *head;
//	head = new node;
//	head->next = NULL;
//	pre = head;
//	for (int i = 0;i < n;i++) {
//		p = new node;
//		p->data = Array[i];
//		p->next = NULL;
//		pre->next = p;
//		pre = p;
//	}
//
//	return head;
//}
//
////���򷵻ؽ��
//node* GetElem(node* head, int i) {
//	int j = 1;
//	node *p = head->next;
//	if (i == 0) return head;
//	else if (i < 1) return NULL;
//	while (p&&j < i) {
//		p = p->next;
//		j++;
//	}
//	return p;
//}
//
////����ֵΪe�ĵ�һ�����
//node* LocateElem(node* head, int e) {
//	node *p = head->next;
//	while (p&&p->data!=e)
//	{
//		p = p->next;
//	}
//	return p;
//}
//
////��ѯ����ĳ��Ԫ�ص�����
//int Search_Node(node* head, int x)
//{
//	/*
//		Finding the number of x in List
//	*/
//	int count = 0; //������
//	node* p = head->next;
//	while (p) {
//		if (p->data == x) {
//			count++;
//		}
//		p = p->next;
//	}
//	return count;
//}
//
////��x�����pos��λ��
//void Insert(node* head, int pos, int x)
//{
//	node*p = head;
//	for (int i = 0;i < pos - 1;i++) {
//		p = p->next;
//	}
//
//	node*q = new node;
//	q->data = x;
//	q->next = p->next;
//	p->next = q;
//}
//
////ɾ��������ֵΪԪ��
//void Del(node* head, int x)
//{
//	node*p = head->next;
//	node*pre = head;
//	while (p != NULL) {
//		if (p->data == x) {
//			pre->next = p->next;
//			delete(p);
//			p = pre->next;
//		}
//		else
//		{
//			pre = p;
//			p = p->next;
//		}
//	}
//}
//
////��ӡ�������
//void ShowList(node *head) {
//	node* p = head->next;
//	cout << "The LinkedList is:" <<endl;
//	while (p) {
//		cout << p->data << " ";
//		p = p->next;
//	}
//	cout << endl;
//}
//
////���
//int LengthofList(node *head) {
//	int count = 0;
//	head = head->next;
//	while (head) {
//		count++;
//		head = head->next;
//	}
//	return count;
//}
//
///*
//	˫���������
//*/
//
////����˫������
//DLinklist Dnode_create_LinkedList(int Array[], int n) {
//	Dnode *head, *pre, *q;
//	head = new Dnode;
//	head->next = NULL;
//	pre = head;
//	for (int i = 0;i < n;i++) {
//		q = new Dnode;
//		q->data = Array[i];
//		if (pre->next != NULL)
//		{
//			q->next = pre->next;
//			pre->next->prior = q;
//			q->prior = pre;
//			pre->next = q;
//		}
//		else {
//			q->next = pre->next;
//			q->prior = pre;
//			pre->next = q;
//		}
//		pre = pre->next;
//	}
//
//	return head;
//}
//
////��ӡ�������
//void Dnode_ShowList(Dnode *head) {
//	Dnode* p = head->next;
//	cout << "The Du-LinkedList is:" << endl;
//	while (p) {
//		cout << p->data << " ";
//		p = p->next;
//	}
//	cout << endl;
//}
//
////ɾ��������ֵΪԪ��
//void Del(Dnode* head, int x)
//{
//	Dnode*p = head->next;
//	Dnode*pre = head;
//	while (p != NULL) {
//		if (p->data == x) {
//			pre->next = p->next;
//			p->next->prior = pre;
//			delete(p);
//			p = pre->next;
//		}
//		else
//		{
//			pre = p;
//			p = p->next;
//		}
//	}
//}
//
//
//int main() {
//	int Array[] = { 5,3,6,1,2,8,10,4,7 };
//	int length = sizeof(Array) / sizeof(Array[0]);
//	DLinklist L = Dnode_create_LinkedList(Array, length);
//	Dnode_ShowList(L);
//	Del(L, 6);
//	Dnode_ShowList(L);
//	return 0;
//}