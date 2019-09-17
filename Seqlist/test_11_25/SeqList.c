#include"SeqList.h"

void SeqListInit(SeqList* psl, size_t capacity)
{
	assert(psl != NULL);
	//给顺序表分配初始空间
	psl->array = (SLDataType*)malloc(capacity*sizeof(SLDataType));
	psl->_size = 0;
	psl->_capicity = capacity;
}
void SeqListDestory(SeqList* psl)
{
	assert(psl != NULL);
	if (psl->array)
	{
		free(psl->array);
		psl->array = NULL;
		psl->_size = 0;
		psl->_capicity = 0;
	}
	
}
void SeqListPrint(SeqList* psl)
{
	assert(psl);
	if (psl->array != NULL)
	{//打印顺序表的元素
		for (size_t i = 0; i < psl->_size; i++)
		{
			printf("%d ", psl->array[i]);
		}
	}
	printf("\n");
}


void CheckCapacity(SeqList* psl)
{
	
	assert(psl != NULL);

	if (psl->_size == psl->_capicity)
	{
		psl->_capicity *= 2;
		//为顺序表重新申请空间
		psl->array = (SLDataType*)realloc(psl->array, psl->_capicity*sizeof(SLDataType));
		assert(psl->array);
	}
		
}
void SeqListPushBack(SeqList* psl, SLDataType x)
{
	//在顺序表尾上插入数据
	assert(psl);
	CheckCapacity(psl);
	psl->array[psl->_size] = x;
	psl->_size++;
}
void SeqListPopBack(SeqList* psl)
{
	assert(psl);
	psl->array[psl->_size] = 0;
	psl->_size--;
}

void SeqListPushFront(SeqList* psl, SLDataType x)
{//在顺序表头部插入数据
	assert(psl); 
	int end = psl->_size-1;
	while (end>=0)
	{
		psl->array[end + 1] = psl->array[end];
		end--;
	}
	psl->array[0] = x;
	psl->_size++;
}

void SeqListPopFront(SeqList* psl)
{
	assert(psl);
	//将第二个数据依次向前移动
	for (size_t i = 0; i < psl->_size - 1; i++)
	{
		psl->array[i] = psl->array[i + 1];
	}
	psl->_size--;

}
int SeqListFind(SeqList* psl, SLDataType x)
{
	assert(psl);
	for (size_t i = 0; i < psl->_size - 1; i++)
	{
		if (psl->array[i] == x)
			return i;
	}
	return -1;
}

void SeqListInsert(SeqList* psl, size_t pos, SLDataType x)
{
	    assert(psl&&pos <= psl->_size);
		CheckCapacity(psl);
		int end = psl->_size - 1;
		while (end >= (int)pos)
		{
			psl->array[end + 1] = psl->array[end];
			end--;
		}
		psl->array[pos] = x;
	    psl->_size++;
}
void SeqListErase(SeqList* psl, size_t pos)
{
	assert(psl&&pos<psl->_size);
	while (pos<psl->_size)
	{
		psl->array[pos] = psl->array[pos + 1];
		pos++;
	}
	psl->_size--;

}
void SeqListRemove(SeqList* psl, SLDataType x)
{
	assert(psl);
	int pos = SeqListFind(psl, x);
	if (pos != -1)
	{
		while (pos < (int)psl->_size)
		{
			psl->array[pos] = psl->array[pos + 1];
			pos++;
		}
		psl->_size--;
	}
	else
		printf("删除的数不存在！\n");
}
void SeqListModify(SeqList* psl, size_t pos, SLDataType x)
{
	assert(psl && pos < psl->_size);
	psl->array[pos] = x;
}

void SeqListBubbleSort(SeqList* psl)
{
	assert(psl);
	size_t finish = psl->_size;
	while (finish>0)
	{
		for (size_t i = 0; i < finish; i++)
		{
			if (psl->array[i - 1]>psl->array[i])
			{
				SLDataType temp = psl->array[i];
				psl->array[i] = psl->array[i - 1];
				psl->array[i - 1] = temp;
			}
		}
		finish--;
	}
	
}
int  SeqListBinaryFind(SeqList* psl, SLDataType x)
{
	assert(psl);
	int mid;
	int begin = 0;
	int end = psl->_size-1;
	while (begin <= end)
	{
		mid = begin + (end - begin) / 2;
		if (psl->array[mid] > x)
		{
			end = mid - 1;
		}
		else if (psl->array[mid] < x)
		{
			begin = mid + 1;
		}
		else
			return mid;
	}
	if (begin>end)
		return -1;
	else
		return mid;

}
void SeqListRmoveAll(SeqList* psl, SLDataType x)
{
	assert(psl);
	size_t cur = 0;
	size_t dst = 0;
	while (cur < psl->_size-1)
	{
		if (psl->array[cur] != x)
		{
			psl->array[dst] = psl->array[cur];
			++dst;
		}
		++cur;
	}
	psl->_size = dst;

}
void SeqListtest1()
{
	SeqList s;
	SeqListInit(&s, 2);
	SeqListPushBack(&s, 5);
	SeqListPushBack(&s, 1);
	SeqListPushBack(&s, 2);
	SeqListPushBack(&s, 3);
	SeqListPushBack(&s, 6);
	SeqListPushBack(&s, 3);
	SeqListPushBack(&s, 4);
	SeqListPushBack(&s, 3);
	//SeqListPrint(&s);
	//SeqListPopBack(&s);
	//SeqListPushFront(&s, 3);
	//SeqListPopFront(&s);
	//SeqListInsert(&s, 2, 3);
	//SeqListErase(&s, 2);
	//SeqListRemove(&s, 5);
	//SeqListModify(&s, 2, 1);
	//SeqListBubbleSort(&s);
	/*int ret = SeqListBinaryFind(&s, 2);
	if (ret = -1)
	{
		printf("找不到\n");
	}
	else
		printf("所找的数的下标为：", ret);*/
	SeqListRmoveAll(&s, 3);
	SeqListPrint(&s);


	
}
