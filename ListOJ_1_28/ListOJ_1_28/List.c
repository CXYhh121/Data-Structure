#define _CRT_SECURE_NO_WARNINGS
#include <string.h>
#include <stdio.h>
#include "List.h"

//�ϲ�������������
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2)//�ϲ������������� 
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

//��֤�����Ƿ�Ϊ��������
//1->2->3->3->2->1
struct ListNode* reverselist(struct ListNode* head)
{
	//���õݹ齫��������
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
	//����ָ���ߵ������м�λ��
	while (fast && fast->next)
	{
		fast = fast->next->next;
		slow = slow->next;
	}
	slow = reverselist(slow);//���ú�벿�ֵ�����

	//�Ƚ�ǰ�벿�ֵ�����ͺ�벿�ֵ������Ƿ���ͬ
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