#include"Heap.h"
void AdjustDown(HPDataType* a, int n,int root)
{//创建小堆
	assert(a);
	int parent = root;
	int child = parent * 2 + 1;

	while (child < n)
	{
		//找左右孩子里面小的那个
		if (a[child + 1] < a[child] && child+1 < n)
			++child;//指向右孩子
		//比较父节点与小的那个孩子的大小
		if (a[parent] > a[child])
		{
			HPDataType tmp = a[parent];
			a[parent] = a[child];
			a[child] = tmp;
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			break;
		}
	}
}
void HeapInit(Heap* hp, HPDataType* a, int n)
{
	assert(hp && a);
	hp->_array = (HPDataType*)malloc(n*sizeof(HPDataType));
	hp->_Capacity = hp->_size = n;
	memcpy(hp->_array, a, sizeof(HPDataType)*n);//用数组a给堆初始化
    //建堆

	for (int i = (hp->_size - 2) / 2; i >= 0; --i)
	{
		AdjustDown(hp->_array,hp->_size, i);
	}
}
void HeapPrint(Heap* hp)
{
	assert(hp);
	for (int i = 0; i < hp->_size; i++)
	{
		printf("%d ", hp->_array[i]);
	}
	printf("\n");
}
void HeapDestory(Heap* hp)
{
	assert(hp);
	free(hp->_array);
	hp->_array = NULL;
	hp->_Capacity = hp->_size = 0;
}
void AdjustUp(HPDataType* a, int n, int child)
{//创建小堆
	assert(a);
	int parent = (child - 1) / 2;

	while (child > 0)
	{
		if (a[parent] > a[child])
		{
			HPDataType tmp = a[parent];
			a[parent] = a[child];
			a[child] = tmp;

			child = parent;
			parent = (child - 1) / 2;
		}
		else
		{
			break;
		}
	}
}
void HeapPush(Heap* hp, HPDataType x)
{
	assert(hp);
	if (hp->_size == hp->_Capacity)
	{
		hp->_Capacity *= 2;
		hp->_array = (HPDataType*)realloc(hp->_array, hp->_Capacity*sizeof(HPDataType));
		assert(hp->_array);
	}
	hp->_array[hp->_size] = x;
	hp->_size++;
	//调堆
	AdjustUp(hp->_array, hp->_size, hp->_size - 1);	
}
void Swap(HPDataType* p1, HPDataType* p2)
{
	HPDataType tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}
void HeapPop(Heap* hp)
{
	assert(hp);
	Swap(&hp->_array[0], &hp->_array[hp->_size - 1]);

	hp->_size--;
	AdjustDown(hp->_array, hp->_size, 0);
}
HPDataType HeapTop(Heap* hp)
{
	assert(hp);
	Swap(&hp->_array[0], &hp->_array[hp->_size - 1]);

	return hp->_array[hp->_size - 1];
	hp->_size--;
	AdjustDown(hp->_array, hp->_size, 0);
}
int HeapSize(Heap* hp)
{
	assert(hp);
	return hp->_size;
}
void HeapTest()
{
	Heap hp;
	int a[10] = { 2, 4, 5, 4, 7, 8, 1, 7, 3, 6 };
	HeapInit(&hp, a, sizeof(a) / sizeof(int));
	//HeapPush(&hp, 0);
	//HeapPop(&hp);
	int ret = HeapSize(&hp);
	printf("%d\n", ret);
	HeapPrint(&hp);
}