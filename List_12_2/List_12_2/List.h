#define _CRT_SECURE_NO_WARNINGS
#pragma once

#include<stdio.h>
#include<string.h>
#include<assert.h>
#include<stdlib.h>
// 2、带头双向循环链表增删查改实现 
typedef int LTDataType;
typedef struct ListNode
{
	LTDataType _data;
	struct ListNode* _next;
	struct ListNode* _prev;
}ListNode;

typedef struct List
{
	ListNode* _head;
}List;


ListNode* BuyListNode(LTDataType x);

void ListInit(List* plist);
void ListDestory(List* plist);

void ListPrint(List* plist);
void ListPushBack(List* plist, LTDataType x);
void ListPopBack(List* plist);
void ListPushFront(List* plist, LTDataType x);
void ListPopFront(List* plist);

ListNode* ListFind(List* plist, LTDataType x);
// 在pos的前面进行插入 
void ListInsert(ListNode* pos, LTDataType x);
// 删除pos位置的节点 
void ListErase(ListNode* pos);
void ListReverse(List* plist);
void Listtest();