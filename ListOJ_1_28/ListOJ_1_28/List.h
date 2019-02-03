#define _CRT_SECURE_NO_WARNINGS
#ifndef __LIST_H__
#define __LIST_H__
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>

typedef int SLTDataType;
typedef struct SListNode
{
	SLTDataType _data;
	struct SListNode* _next;

}SListNode;

typedef struct SList
{
	SListNode* _head;
}SList;



void SListInit(SList* plist);
void SListDstory(SList* plist);

SListNode* BuySListNode(SLTDataType x);
void SListPushFront(SList* plist, SLTDataType x);
void SListPushBack(SList* plist, SLTDataType x);
void SListPopFront(SList* plist);
void SListPopBack(SList* plist);

SListNode* SListFind(SList* plist, SLTDataType x);
// 在pos的后面进行插入 
void SListInsertAfter(SListNode* pos, SLTDataType x);
// 在pos的前面进行插入 
void SListEraseAfter(SListNode* pos);
void SListRemove(SList* plist, SLTDataType x);

void SListPrint(SList* plist);
void TestSList();
void SListPopFront(SList* plist);
SListNode* SListFind(SList* plist, SLTDataType x);
// 在pos的后面进行插入 
void SListInsertAfter(SListNode* pos, SLTDataType x);
// 在pos的前面进行插入 
void SListEraseAfter(SListNode* pos);
void SListRemove(SList* plist, SLTDataType x);

void SListPrint(SList* plist);
void Listtest1();




#endif //__LIST_H__