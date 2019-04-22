#define _CRT_SECURE_NO_WARNINGS

#include "SeqList.h"


void SeqListInit(SeqList* psl, size_t capacity)//初始化顺序表
{
	assert(psl != NULL);
	psl->_array = (SLDataType*)malloc(sizeof(SLDataType) * capacity);
	psl->_size = 0;
	psl->_capacity = capacity;
}

void SeqListDestroy(SeqList* psl)
{
	assert(psl != NULL);
	if (psl->_array)
	{
		free(psl->_array);
		psl->_array = NULL;
		psl->_size = 0;
		psl->_capacity = 0;
	}

}


void CheckCapacity(SeqList* psl)//增容
{
	assert(psl != NULL);
	if (psl->_size == psl->_capacity)
	{
		psl->_capacity *= 2;
		psl->_array = (SLDataType*)realloc(psl->_array, sizeof(SLDataType)*psl->_capacity);
		assert(psl->_array);//判断重新申请内存是否成功
	}
}


void SeqListPushBack(SeqList* psl, SLDataType x)
{
	//在顺序表的尾部插入一个元素，_size++
	assert(psl != NULL);
	CheckCapacity(psl);
	psl->_array[psl->_size] = x;
	psl->_size++;
}


void SeqListPopBack(SeqList* psl)//尾删
{
	assert(psl != NULL);
	psl->_size--;
}

void SeqListPushFront(SeqList* psl, SLDataType x)//头插
{
	assert(psl != NULL);
	int i = psl->_size - 1;
	for (; i >= 0; --i)
	{
		psl->_array[i + 1] = psl->_array[i];
	}
	psl->_array[0] = x;
	psl->_size++;
}

void SeqListPopFront(SeqList* psl)//头删
{
	assert(psl != NULL);
	for (size_t i = 0; i < psl->_size; ++i)
	{
		psl->_array[i] = psl->_array[i + 1];
	}
	psl->_size--;
}

void SeqListPrint(SeqList* psl)
{
	assert(psl != NULL);
	if (psl->_array)
	{
		for (size_t i = 0; i < psl->_size; ++i)
		{
			printf("%d ", psl->_array[i]);
		}
		printf("\n");
	}
}




void TestSeqList()
{
	SeqList s;
	SeqListInit(&s, 2);
	SeqListPushBack(&s, 5);
	SeqListPushBack(&s, 3);
	SeqListPushBack(&s, 6);
	SeqListPushBack(&s, 8);
	SeqListPushBack(&s, 9);
	SeqListPushBack(&s, 1);
	SeqListPushBack(&s, 4);

	//SeqListPopBack(&s);
	SeqListPushFront(&s, 10);
	SeqListPushFront(&s, 100);

	SeqListPrint(&s);

	SeqListPopFront(&s);

	SeqListPrint(&s);

	SeqListDestroy(&s);
}



int main()
{
	TestSeqList();
	return 0;
}