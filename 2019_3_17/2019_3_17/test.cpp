#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
using namespace std;

//#define N 7
//int fun1(char s[], char a, int n)
//{
//	int j;
//	j = n;
//	while (a < s[j] && j > 0) j--;
//	return j;
//}
//
//int fun2(char s[], char a, int n)
//{
//	int j;
//	j = 1;
//	while (a > s[j] && j <= n)
//		j++;
//	return j;
//}
//int main()
//{
//	char s[N + 1];
//	int k, p;
//	for (k = 1; k <= N; k++)
//		s[k] = 'A' + 2 * k + 1;
//	p = fun1(s, 'M', N);
//	cout << p + fun2(s, 'M', N) << endl;
//
//	return 0;
//}


//设计一个链表
//
//class MyLinkedList {
//public:
//	/** Initialize your data structure here. */
//	MyLinkedList() {
//		_head = new Node(0);
//		_head->_next = _head;
//		_head->_prev = _head;
//
//		size = 0;
//	}
//
//	void print()
//	{
//		int i = size;
//		Node* cur = _head->_next;
//		while (i--)
//		{
//			cout << cur->_val << "->";
//			cur = cur->_next;
//		}
//		cout << endl;
//	}
//	/** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
//	int get(int index) {
//		if (index < 0 || index > size - 1)
//			return -1;
//		Node* cur = _head->_next;
//		while (index--)
//			cur = cur->_next;
//
//		return cur->_val;
//	}
//
//	/** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
//	void addAtHead(int val) {
//		Node* newnode = new Node(val);
//		Node* next = _head->_next;
//
//		newnode->_prev = _head;
//		newnode->_next = next;
//
//		next->_prev = newnode;
//		_head->_next = newnode;
//
//		++size;
//
//	}
//
//	/** Append a node of value val to the last element of the linked list. */
//	void addAtTail(int val) {
//		Node* newnode = new Node(val);
//		Node* tail = _head->_prev;
//
//		newnode->_prev = tail;
//		newnode->_next = _head;
//
//		_head->_prev = newnode;
//		tail->_next = newnode;
//
//		++size;
//	}
//
//	/** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
//	void addAtIndex(int index, int val) {
//		if (index < 0 || index > size)
//			return;
//		if (index == size)
//		{
//			addAtTail(val);
//			return;
//		}
//
//		Node* cur = _head->_next;
//		while (index--)
//			cur = cur->_next;
//		Node* newnode = new Node(val);
//		Node* prev = cur->_prev;
//
//		newnode->_prev = prev;
//		newnode->_next = cur;
//
//		cur->_prev = newnode;
//		prev->_next = newnode;
//
//		++size;
//	}
//
//	/** Delete the index-th node in the linked list, if the index is valid. */
//	void deleteAtIndex(int index) {
//		if (index > size - 1 || index < 0)
//			return;
//		Node* cur = _head->_next;
//		while (index--)
//			cur = cur->_next;
//
//		Node* prev = cur->_prev;
//		prev->_next = cur->_next;
//		cur->_next->_prev = prev;
//		delete cur;
//		--size;
//
//	}
//
//private:
//	struct Node
//	{
//		int _val;
//		Node* _prev;
//		Node* _next;
//
//		Node(int val = 0)
//			:_val(val)
//			, _prev(nullptr)
//			, _next(nullptr)
//		{}
//	};
//	Node* _head;
//	int size;
//
//};


//反向打印一个链表

//struct Node
//{
//	int val;
//	Node* prev;
//	Node* next;
//
//	Node(int val = 0)
//		:val(val)
//		, prev(nullptr)
//		, next(nullptr)
//	{}
//	Node* head;
//};
//class Solution {
//public:
//	
//	typedef Node ListNode;
//	ListNode* ReverseList(ListNode* pHead) {
//		ListNode* newhead = NULL;
//		ListNode* cur = pHead;
//
//		while (cur)
//		{
//			ListNode* next = cur->next;
//
//			cur->next = newhead;
//			newhead = cur;
//			cur = next;
//		}
//		return newhead;
//	}
//	vector<int> printListFromTailToHead(ListNode* head) {
//		ListNode* newhead = ReverseList(head);
//		vector<int> v;
//		ListNode* cur = newhead;
//		while (cur)
//		{
//			v.push_back(cur->val);
//			cur = cur->next;
//		}
//		return v;
//	}
//};
//
//int main()
//{
//	Solution s;
//	Node* head = nullptr;
//	s.printListFromTailToHead(head);
//	return 0;
//}