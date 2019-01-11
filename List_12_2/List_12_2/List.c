#include"List.h"

ListNode* BuyListNode(LTDataType x)
{
	ListNode* newnode = (ListNode*)malloc(sizeof(ListNode));
	newnode->_data = x;
	newnode->_next = NULL;
	newnode->_prev = NULL;

	return newnode;
}
void ListInit(List* plist)
{
	assert(plist);
	ListNode* head = BuyListNode(0);
	head->_next = head;
	head->_prev = head;

	plist->_head = head;
}
void ListDestory(List* plist)
{
	assert(plist);
	ListNode* head = plist->_head;
	ListNode* cur = head->_next;

	while (cur != head)
	{
		ListNode* next = cur->_next;
		free(cur);
		cur = next;
	}
	free(head);
	plist->_head = NULL;
}
void ListPrint(List* plist)
{
	assert(plist);
	ListNode* head = plist->_head;
	ListNode* cur = head->_next;

	printf("<-head->");
	while (cur != head)
	{
		printf("<-%d->", cur->_data);
		cur = cur->_next;
	}
	printf("\n");
}
void ListPushBack(List* plist, LTDataType x)
{
	assert(plist);
	ListNode* head = plist->_head;
	ListNode* tail = head->_prev;
	ListNode* newnode = BuyListNode(x);

	tail->_next = newnode;
	newnode->_prev = tail;
	head->_prev = newnode;
	newnode->_next = head;
	//ListInsert(plist->_head->_prev,x);
}

void ListPopBack(List* plist)
{
	assert(plist);
	/*ListNode* head = plist->_head;
	ListNode* tail = head->_prev;
	ListNode* newtail = tail->_prev;

	free(tail);
	newtail->_next = head;
	head->_prev = newtail;*/
	ListErase(plist->_head->_prev);

}
void ListPushFront(List* plist, LTDataType x)
{
	assert(plist);
	ListNode* head = plist->_head;
	ListNode* newnode = BuyListNode(x);
	ListNode* next = head->_next;

	head->_next = newnode;
	newnode->_prev = head;
	newnode->_next = next;
	next->_prev = newnode;
	//ListInsert(plist->_head->_next, x);
}
void ListPopFront(List* plist)
{
	assert(plist);
	//ListNode* head = plist->_head;
	//ListNode* next = head->_next;
	//ListNode* nextnext = next->_next;

	//free(next);
	//head->_next = nextnext;
	//nextnext->_prev = head;
	ListErase(plist->_head->_next);
}

ListNode* ListFind(List* plist, LTDataType x)
{
	assert(plist);
	ListNode* head = plist->_head;
	ListNode* cur = head->_next;

	while (cur != head)
	{
		if (cur->_data == x)
			return cur;
		else
			cur = cur->_next;
	}
	return NULL;
}
// 在pos的前面进行插入 
void ListInsert(ListNode* pos, LTDataType x)
{
	assert(pos);
	ListNode* prev = pos->_prev;
	ListNode* newnode = BuyListNode(x);

	prev->_next = newnode;
	newnode->_prev = prev;

	newnode->_next = pos;
	pos->_prev = newnode;

}
// 删除pos位置的节点 
void ListErase(ListNode* pos)
{
	assert(pos);
	ListNode* next = pos->_next;
	ListNode* nextnext = next->_next;

	free(next);
	pos->_next = nextnext;
	nextnext->_prev = pos;
}
void ListReverse(List* plist)
{
	assert(plist);
	/*ListNode* head = plist->_head;
	ListNode* cur = head->_next;

	while (cur != head)
	{
		ListNode* temp = cur->_next;
		cur->_next = cur->_prev;
		cur->_prev = temp;

		cur = cur->_prev;
	}

	ListNode* temp = head->_next;
	head->_next = head->_prev;
	head->_prev = temp;*/

	ListNode* begin = plist->_head->_next;
	ListNode* end = plist->_head->_prev;

	while (begin != end && end->_next != begin)
	{
		LTDataType tmp = begin->_data;
		begin->_data = end->_data;
		end->_data = tmp;

		begin = begin->_next;
		end = end->_prev;
	}

}

void Listtest()
{
	List list;
	ListInit(&list);
	ListPushBack(&list, 1);
	ListPushBack(&list, 2);
	ListPushBack(&list, 3);
	ListPushBack(&list, 4);
	ListPushFront(&list, 5);
	ListPushFront(&list, 6);
	ListPushFront(&list, 7);
	ListPushFront(&list, 8);
	ListPrint(&list);

	//ListNode* pos = ListFind(&list, 3);
	//	//ListInsert(pos, 30);
	////ListPopFront(&list);
	//ListErase(pos);
	////ListPopBack(&list);
	ListReverse(&list);
	ListPrint(&list);

	ListDestory(&list);


}