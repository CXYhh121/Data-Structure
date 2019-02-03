#define _CRT_SECURE_NO_WARNINGS
#include <string.h>
#include <stdio.h>
#include "List.h"

//合并两个有序链表
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2)//合并俩个有序链表 
{
	struct ListNode* newhead;
	struct ListNode* newtail;
	if (l1 == NULL) return l2;
	if (l2 == NULL) return l1;
	if (l1->val < l2->val)
	{
		newhead = l1;
		l1 = l1->next;
	}
	else
	{
		newhead = l2;
		l2 = l2->next;
	}
	newtail = newhead;
	while (l1 && l2)
	{
		if (l1->val < l2->val)
		{
			newtail->next = l1;
			newtail = newtail->next;
			l1 = l1->next;
		}
		else
		{
			newtail->next = l2;
			newtail = newtail->next;
			l2 = l2->next;
		}
	}
	if (l1)
	{
		newtail->next = l1;
	}
	if (l2)
	{
		newtail->next = l2;
	}

	return newhead;
}

//验证链表是否为回文链表
//1->2->3->3->2->1
struct ListNode* reverselist(struct ListNode* head)
{
	//利用递归将链表逆置
	if (head == NULL || head->next == NULL) return head;
	struct ListNode* h = reverselist(head->next);
	head->next->next = head;
	head->next = NULL;

	return h;
}

bool isPalindrome(struct ListNode* head) {
	if (head == NULL || head->next == NULL) return true;
	struct ListNode* fast = head;
	struct ListNode* slow = head;
	//让慢指针走到链表中间位置
	while (fast && fast->next)
	{
		fast = fast->next->next;
		slow = slow->next;
	}
	slow = reverselist(slow);//逆置后半部分的链表

	//比较前半部分的链表和后半部分的链表是否相同
	while (slow)
	{
		if (slow->val != head->val)
		{
			return false;
		}
		slow = slow->next;
		head = head->next;
	}

	return true;
}