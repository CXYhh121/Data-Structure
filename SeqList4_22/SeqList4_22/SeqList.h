
//可存储多种类型，支持动态增长的顺序表
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>


typedef int SLDataType;

typedef struct SeqList
{
	SLDataType* _array;
	size_t _size;
	size_t _capacity;
}SeqList;


void SeqListInit(SeqList* psl, size_t capacity);//初始化顺序表
void SeqListDestroy(SeqList* psl);//销毁顺序表

void CheckCapacity(SeqList* psl);//增容
void SeqListPushBack(SeqList* psl, SLDataType x);//尾插
void SeqListPopBack(SeqList* psl);//尾删
void SeqListPushFront(SeqList* psl, SLDataType x);//头插
void SeqListPopFront(SeqList* psl);//头删




void SeqListPrint(SeqList* psl);
void TestSeqList();

