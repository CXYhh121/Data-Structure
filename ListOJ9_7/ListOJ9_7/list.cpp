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

//����˼·
//���������ڻ����ͺ���ٳ����ܵ���һ������һ����
//��ʱ�ÿ���ָ�붼������ͷ��ʼ��������ָ��ÿ����ǰ�ƶ�����λ�ã���ָ��ÿ����ǰ�ƶ�һ��λ�ã�
//�����ָ�뵽��NULL��˵��������NULLΪ��β��û�л��������ָ��׷����ָ�룬���ʾ�л���
//����ʵ�֣�
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


//���ػ��������뻷�ĵ�һ�����
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
//		//���meetΪ�գ�˵�������ڻ�
//		if (meet == NULL)
//		{
//			return NULL;
//		}
//		else
//		{
//			while (1)
//			{
//				//meet��slow��fast�����ĵ㿪ʼ�ߣ�head��ͷ��ʼ��
//				//������������򷵻���������Ľ���
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



//���ƴ����ָ�������

//typedef struct RandomListNode RLNode;
//struct RandomListNode *copyRandomList(struct RandomListNode *head) {
//	RLNode* cur = head;
//	//���˿���ԭ����Ԫ��������ԭ����֮��
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
//	//��������Ԫ�ص����ָ�밴��ԭ��������ָ��һ������
//	while (cur)
//	{
//		//��¼�����ڵ��λ��
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
//	//�������������ԭ�����ϲ�ֳ���
//	RLNode* tail, *copyhead;//����һ���µ������ͷָ���βָ��
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
//		cur->next = next;//��ԭԭ����
//		cur = next;
//	}
//	RLNode* newnode = copyhead->next;
//	free(copyhead);
//
//	return newnode;
//}
