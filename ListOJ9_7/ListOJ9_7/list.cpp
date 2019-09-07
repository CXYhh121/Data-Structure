#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>

using namespace std;

//struct ListNode{
//
//private:
//	ListNode* next;
//
//};

//解题思路
//如果链表存在环，就好像操场的跑道是一个环形一样。
//此时让快慢指针都从链表头开始遍历，快指针每次向前移动两个位置，慢指针每次向前移动一个位置；
//如果快指针到达NULL，说明链表以NULL为结尾，没有环。如果快指针追上慢指针，则表示有环。
//代码实现：
//bool hasCycle(struct ListNode *head) {
//	if (head == NULL || head->next == NULL)
//		return false;
//
//	struct ListNode* fast = head;
//	struct ListNode* slow = head;
//
//	while (fast != NULL && fast->next != NULL)
//	{
//		fast = fast->next->next;
//		slow = slow->next;
//
//		if (fast == slow)
//			return true;
//	}
//	return false;
//}


//返回环形链表入环的第一个结点
//class Solution {
//public:
//	ListNode * hasCycle(ListNode *head) {
//		ListNode* fast = head;
//		ListNode* slow = head;
//
//		while (fast && fast->next)
//		{
//			fast = fast->next->next;
//			slow = slow->next;
//
//			if (slow == fast)
//			{
//				return fast;
//			}
//		}
//
//		return NULL;
//	}
//	ListNode *detectCycle(ListNode *head) {
//
//		ListNode* meet = hasCycle(head);
//		//如果meet为空，说明不存在环
//		if (meet == NULL)
//		{
//			return NULL;
//		}
//		else
//		{
//			while (1)
//			{
//				//meet从slow和fast相遇的点开始走，head从头开始走
//				//如果二者相遇则返回这个相遇的交点
//				if (meet == head)
//					return meet;
//				else
//				{
//					meet = meet->next;
//					head = head->next;
//				}
//			}
//		}
//	}
//};



//复制带随机指针的链表

//typedef struct RandomListNode RLNode;
//struct RandomListNode *copyRandomList(struct RandomListNode *head) {
//	RLNode* cur = head;
//	//依此拷贝原链表元素链接在原链表之后
//	while (cur)
//	{
//		RLNode* copy = (RLNode*)malloc(sizeof(RLNode));
//		RLNode* next = cur->next;
//		copy->label = cur->label;
//		copy->next = cur->next;
//		cur->next = copy;
//
//		cur = next;
//	}
//
//	cur = head;
//	//将拷贝的元素的随机指针按照原链表的随机指针一样放置
//	while (cur)
//	{
//		//记录拷贝节点的位置
//		RLNode* copy = cur->next;
//		if (cur->random)
//		{
//			copy->random = cur->random->next;
//		}
//		else
//		{
//			copy->random = NULL;
//		}
//
//		cur = copy->next;
//	}
//
//
//	//将拷贝的链表从原链表上拆分出来
//	RLNode* tail, *copyhead;//定义一个新的链表的头指针和尾指针
//	tail = copyhead = (RLNode*)malloc(sizeof(RLNode));
//	cur = head;
//	while (cur)
//	{
//		RLNode* copy = cur->next;
//		RLNode* next = copy->next;
//
//		tail->next = copy;
//		tail = copy;
//
//		cur->next = next;//复原原链表
//		cur = next;
//	}
//	RLNode* newnode = copyhead->next;
//	free(copyhead);
//
//	return newnode;
//}
