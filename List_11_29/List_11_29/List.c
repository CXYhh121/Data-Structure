#include"List.h"


void SListInit(SList* plist)
{
	assert(plist);
	plist->_head = NULL;
}

void SListDstory(SList* plist)
{
	assert(plist);
	SListNode* cur = plist->_head;
	while (cur != NULL)
	{
		SListNode* next = cur->_next;
		free(cur);
		cur = next;
	}
	plist->_head = NULL;
}

void SListPrint(SList* plist)
{
	assert(plist);
	SListNode* cur = plist->_head;
	while (cur != NULL)
	{
		printf("%d->", cur->_data);
		cur = cur->_next;
	}
	printf("NULL");
}
SListNode* BuySListNode(SLTDataType x)
{
	SListNode* pnode;
	pnode = (SListNode*)malloc(sizeof(SListNode));
	pnode->_data = x;
	pnode->_next = NULL;
	return pnode;
}
void SListPushFront(SList* plist, SLTDataType x)
{
	assert(plist);
	SListNode* newnode = BuySListNode(x);
	newnode->_next = plist->_head;
	plist->_head = newnode;
}
void SListPushBack(SList* plist, SLTDataType x)
{
	assert(plist);
	if (plist->_head == NULL)
	{
		SListNode* newnode = BuySListNode(x);
	}
	else
	{
		SListNode* tail = plist->_head;
		while (tail->_next != NULL)
		{
			tail = tail->_next;
		}
		SListNode* newtail = BuySListNode(x);
		tail->_next = newtail;
	}
	
}
void SListPopFront(SList* plist)
{
	assert(plist);
	SListNode* next = plist->_head->_next;
	free(plist->_head);
	plist->_head = next;
}
void SListPopBack(SList* plist)
{
	if (plist->_head->_next == NULL)
	{
		free(plist->_head);
		plist->_head = NULL;
	}
	else
	{
		SListNode* prev = NULL;
		SListNode* tail = plist->_head;
		while (tail->_next != NULL)
		{
			prev = tail;
			tail = tail->_next;
		}
		free(tail);
		prev->_next = NULL;
	}
}

SListNode* SListFind(SList* plist, SLTDataType x)
{
	assert(plist);
	SListNode* cur = plist->_head;
	while (cur->_next != NULL)
	{
		if (cur->_data == x)
			return cur;
		else
			cur = cur->_next;
	}
	return cur;
}
// 在pos的后面进行插入 
void SListInsertAfter(SListNode* pos, SLTDataType x)
{
	assert(pos);
	SListNode* newnode = BuySListNode(x);
	assert(newnode);
	newnode->_next = pos->_next;
	pos->_next = newnode;
}
// 在pos的前面进行插入 
void SListEraseAfter(SListNode* pos)
{
	assert(pos && pos->_next);
	SListNode* next = pos->_next;
	SListNode* nextnext = next->_next;
	
	pos->_next = nextnext;
	free(next);
}
void SListRemove(SList* plist, SLTDataType x)
{
	assert(plist);
	if (plist->_head->_next==NULL)
	{
		if (plist->_head->_data == x)
			SListPopFront(plist);
		else
			printf("所删除的数不存在！\n");
	}
	else
	{
		SListNode* cur = plist->_head;
		SListNode* prev = plist->_head;
		while (cur->_next != NULL)
		{
			if (cur->_data == x)
			{
				prev->_next = cur->_next;
			}
			else
			{
				cur = cur->_next;
				prev = prev->_next;
			}
				
		}
	}
}

void Listtest1()
{
	SList list;
	SListInit(&list);
	//SListPrint(&list);
	SListPushFront(&list, 1);
	SListPushFront(&list, 2);
	SListPushFront(&list, 3);
	SListPushFront(&list, 4);
	//SListPushBack(&list, 0);
	//SListPopFront(&list);
	//SListPopBack(&list);
	/*SListNode* pos = SListFind(&list, 3);
	printf("%d\n", pos->_data);
	SListInsertAfter(pos, 6);
	SListEraseAfter(pos);*/
	SListRemove(&list, 2);
	SListPrint(&list);
	SListDstory(&list);

}