#define _CRT_SECURE_NO_WARNINGS
#include"Sort.h"
#include"Stack.h"
void Swap(int* pa, int* pb)
{
	int tmp = *pa;
	*pa = *pb;
	*pb = tmp;
}
void ArrayPrint(int* a, int n)
{
	for (int i = 0; i < n; ++i)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}
void InsertSort(int* a, int n)
{
	for (int i = 0; i < n-1; ++i)
	{//��[end+1]��ֵ���뵽��������[0,end]��
		int end = i;
		int tmp = a[end + 1];
		while (end >= 0)
		{
			if (a[end] > tmp)
			{
				a[end + 1] = a[end];
				--end;
			}
			else
				break;
		}
		a[end + 1] = tmp;
	}	
}
void ShellSort(int* a, int n)
{
	int gap = n;
	gap = gap / 3 + 1;
	for (int i = 0; i<n - gap; ++i)
	{
		int end = i;
		int tmp = a[end + gap];
		while (end >= 0)
		{
			if (a[end] > tmp)
			{
				a[end + gap] = a[end];
				end -= gap;
			}
			else
				break;
		}
		a[end + gap] = tmp;
	}	
}
void SelectSort(int* a, int n)
{
	int begin = 0;
	int end = n - 1;
	while (begin < end)
	{
		int min = begin;
		int max = end;
		for (int i = begin; i < end; i++)
		{
			if (a[i] < a[min])
				min = i;
			if (a[i] > a[max])
				max = i;
		}
		Swap(&a[begin], &a[min]);
		if (begin == max)
			max = min;
		Swap(&a[end], &a[max]);
		++begin;
		--end;
	}
}
void AdjustDown(int* a, int n, int parent)
{
	//�����
	int child = parent * 2 + 1;//���������±�������ӵ�λ��
	while (child < n)//�����Ӵ���ʱ
	{
		//�ж��Һ����Ƿ���������Һ����ĸ�����
		if (a[child] < a[child + 1] && child + 1 < n)
			++child;
		if (a[child] > a[parent])
		{
			Swap(&a[child], &a[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
			break;
	}
}
void HeapSort(int* a, int n)
{
	//1�������
	for (int i = (n - 2) / 2; i >= 0; --i)
	{
		AdjustDown(a, n, i);
	}

	//2��ѡ��
	int end = n - 1;
	while (end > 0)
	{
		Swap(&a[0], &a[end]);
		AdjustDown(a, end, 0);
		--end;
	}	
}
void BubbleSort(int* a, int n)
{
	int end = n - 1;
	while (end > 0)
	{
		for (int i = 0; i < end; ++i)
		{
			if(a[i + 1] < a[i])
			    Swap(&a[i], &a[i + 1]);
		}
		--end;
	}
}


//����ȡ�м�ѡkey��
int GetMidkey(int* a, int begin, int end)
{
	int mid = begin + ((end - begin) >> 1);
	if (a[begin] > a[mid])
	{
		if (a[begin] < a[end])//a[mid] < a[begin] < a[end]
			return begin;
		else if (a[mid] > a[end])//a[end] < a[mid] <a [begin]
			return mid;
		else//a[mid] < a[end] <a[begin]
			return end;
	}
	else//a[begin] < a[mid]
	{
		if (a[mid] < a[end])//a[begin] < a[mid] < a[end]
			return mid;
		else if (a[begin] > a[end])//a[end] < a[begin] <a[mid]
			return begin;
		else//a[begin] < a[end] <a[mid]
			return end;	
	}
}
//��������hoare�汾
int PartSort1(int* a, int begin, int end)
{
	int key = GetMidkey(a,begin,end);
	Swap(&a[begin], &a[end]);
	key = begin;
	while (begin < end)
	{
		//���ұ���С��key��ֵ�������
		while (begin < end && a[end] >= a[key])
			--end;
		//������Ҵ���key��ֵ�����ұ�
		while (begin < end && a[begin] <= a[key])
			++begin;
		//�����ҵ�������ֵ
		Swap(&a[begin], &a[end]);
	}
	//��key��ֵ����begin��end������λ�ã���key��߶���С�����������ұ߶��Ǵ���������
	Swap(&a[begin], &a[key]);
	return begin;
}

//���������ڿӷ�
int PartSort2(int* a, int begin, int end)
{
	int key = GetMidkey(a, begin, end);
	Swap(&a[begin], &a[key]);
	int tmp = a[begin];
	while (begin < end)
	{
		//��С��key��ֵ������ߵĿ���
		while (begin < end && a[end] >= tmp)
			--end;
		a[begin] = a[end];
		//�Ҵ���key��ֵ������һ���������Ŀ���
		while (begin < end && a[begin] <= tmp)
			++begin;
		a[end] = a[begin];
	}
	//��key��ֵ�������begin��end������λ���ϣ�����Ǳ�keyС��ֵ���ұ��Ǳ�key���ֵ
	a[begin] = tmp;
	return begin;//����key���ڵ�λ��
}

//�����������ָ�뷨
int PartSort3(int*a, int begin, int end)
{
	int prev = begin;
	int cur = begin + 1;
	while (cur <= end)
	{
		if (a[cur] < a[begin] && ++prev != cur)
			Swap(&a[prev], &a[cur]);
			++cur;
	}
	Swap(&a[begin], &a[prev]);
	return prev;
}
void QuickSort(int* a, int left,int right)
{
	if (left >= right)
		return;
	int div = PartSort1(a, left, right);
	//������[left,div-1]
	//������[div+1,right]
	QuickSort(a, left, div - 1);
	QuickSort(a, div + 1, right);
}
void QuickSortOP(int* a, int left, int right)
{
	if (left >= right)
		return;
	int div = PartSort1(a, left, right);
	//������[left,div-1]
	//������[div+1,right]
	if (right - left > 10)
	{
		QuickSort(a, left, div - 1);
		QuickSort(a, div + 1, right);
	}
	else
	{
		InsertSort(a + left, right - left + 1);
	}
}


void QuickSortNonP(int* a, int left, int right)
{
	Stack st;
	StackInit(&st);
	StackPush(&st, right);
	StackPush(&st, left);

	while (StackEmpty(&st) != 0)
	{
		int begin = StackTop(&st);
		StackPop(&st);
		int end = StackTop(&st);
		StackPop(&st);

		int div = PartSort1(a, begin, end);
		if (begin < div - 1)
		{
			StackPush(&st, div - 1);
			StackPush(&st, begin);
		}

		if (div + 1 < end)
		{
			StackPush(&st, end);
			StackPush(&st, div + 1);
		}
	}

}
//�鲢����
void _MergeSort(int* a, int begin, int end, int* tmp)
{
	if (begin >= end)
		return;
	int mid = begin + ((end - begin) >> 1);
	//���������⣺ʹ����[begin,mid],[mid+1,end]�������򣬵ݹ黮��������ֱ��������
	_MergeSort(a, begin, mid, tmp);
	_MergeSort(a, mid + 1, end, tmp);

	//����[begin,mid],[mid+1,end]
	int begin1 = begin;
	int end1 = mid;
	int begin2 = mid + 1;
	int end2 = end;
	int index = begin;
	while (begin1 <= end1 && begin2 <= end2)
	{
		if (a[begin1] < a[begin2])
		{
			tmp[index++] = a[begin1++];
		}
		else
		{
			tmp[index++] = a[begin2++];
		}
	}
	while (begin1 <= end1)
		tmp[index++] = a[begin1++];
	while (begin2 <= end2)
		tmp[index++] = a[begin2++];
	
	//���鲢�������ԭ����
	index = begin;
	while (begin < end)
		a[index++] = tmp[begin++];
}
void MergeSort(int* a, int n)
{
	int* tmp = (int*)malloc(sizeof(int)*n);
	_MergeSort(a, 0, n - 1, tmp);
	free(tmp);
}

//��������
void CountSort(int* a, int n)
{
	//ȷ�����������С
	int max = a[0];
	int min = a[0];
	for (int i = 0; i < n; ++i)
	{
		if (a[i] > max)
			max = a[i];
		if (a[i] < min)
			min = a[i];
	}
	int range = max - min + 1;
	int* count = (int*)malloc(sizeof(int)*range);
	memset(count, 0, sizeof(int)*range);

	for (int i = 0; i < n; ++i)
	{
		count[a[i] - min]++;
	}

	int j = 0;
	for (int i = 0; i < range; ++i)
	{
		while (count[i]--)
		{
			a[j++] = i + min;
		}
	}
}
void SortTest()
{
	int a[] = { 9, 3, 6, 8, 3, 1, 5, 4, 2 };
	InsertSort(a, sizeof(a) / sizeof(int));
	printf("��������");
	ArrayPrint(a, sizeof(a) / sizeof(int));
	
	ShellSort(a, sizeof(a) / sizeof(int));
	printf("ϣ������");
	ArrayPrint(a, sizeof(a) / sizeof(int));
	
	SelectSort(a, sizeof(a) / sizeof(int));
	printf("ѡ������");
	ArrayPrint(a, sizeof(a) / sizeof(int));

	HeapSort(a, sizeof(a) / sizeof(int));
	printf("������  ");
	ArrayPrint(a, sizeof(a) / sizeof(int));

	BubbleSort(a, sizeof(a) / sizeof(int));
	printf("ð������");
	ArrayPrint(a, sizeof(a) / sizeof(int));

	QuickSort(a, 0, (sizeof(a) / sizeof(int)) - 1);
	printf("��������");
	ArrayPrint(a, sizeof(a) / sizeof(int));

	QuickSortOP(a, 0, (sizeof(a) / sizeof(int)) - 1);
	printf("��������OP��");
	ArrayPrint(a, sizeof(a) / sizeof(int));

	QuickSortNonP(a, 0, (sizeof(a) / sizeof(int)) - 1);
	printf("��������ǵݹ飺");
	ArrayPrint(a, sizeof(a) / sizeof(int));

	MergeSort(a,(sizeof(a) / sizeof(int)));
	printf("�鲢����");
	ArrayPrint(a, sizeof(a) / sizeof(int));

	CountSort(a, (sizeof(a) / sizeof(int)));
	printf("��������");
	ArrayPrint(a, sizeof(a) / sizeof(int));
}


