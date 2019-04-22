
//�ɴ洢�������ͣ�֧�ֶ�̬������˳���
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


void SeqListInit(SeqList* psl, size_t capacity);//��ʼ��˳���
void SeqListDestroy(SeqList* psl);//����˳���

void CheckCapacity(SeqList* psl);//����
void SeqListPushBack(SeqList* psl, SLDataType x);//β��
void SeqListPopBack(SeqList* psl);//βɾ
void SeqListPushFront(SeqList* psl, SLDataType x);//ͷ��
void SeqListPopFront(SeqList* psl);//ͷɾ




void SeqListPrint(SeqList* psl);
void TestSeqList();

