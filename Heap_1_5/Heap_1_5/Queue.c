#include"common.h"
#include"Queue.h"


//���еĳ�ʼ��
void QueueInit(Queue* pq)
{
	assert(pq);
	pq->_head = (QueueNode*)malloc(sizeof(QueueNode));
	assert(pq->_head);
	pq->_tail = pq->_head;
	pq->_head->_next = NULL;

}
void QueueDestory(Queue* pq)
{
	assert(pq);
	QueueNode* cur = pq->_head;
	while (cur)
	{
		QueueNode* next = cur->_next;
		free(cur);
		cur = next;
	}
	
}
void QueuePush(Queue* pq, QDataType x)
{
	assert(pq);

	QueueNode* newnode = (QueueNode*)malloc(sizeof(QueueNode));
	assert(newnode);
	
	newnode->_data = x;
	newnode->_next = NULL;
	pq->_tail->_next = newnode;
	pq->_tail = newnode;
}

int QueueEmpty(Queue* pq)
{
	return pq->_head != pq->_tail;
}
int QueueSize(Queue* pq)
{
	int count = 0;
	if (QueueEmpty(pq) == 0)
		return 0;
	else
	{
		QueueNode* cur = pq->_head->_next;
		while (cur)
		{
			++count;
			cur = cur->_next;
		}
	}
	return count;
}
void QueuePop(Queue* pq)
{
	QueueNode*cur = NULL;

	assert(pq);
	if (QueueEmpty(pq) == 0)
		return;
	cur = pq->_head->_next;//�����ͷ�ĵ�һ��Ԫ��
	if (pq->_tail == cur)//��������ֻ��һ��Ԫ�أ���βָ��ָ��ͷָ��
	{
		pq->_tail = pq->_head;
	}
	pq->_head->_next = cur->_next;//ɾ����һ��Ԫ��
	free(cur);
}
QDataType QueueFront(Queue* pq)
{
	assert(pq);
	return pq->_head->_next->_data;
}

void QueuePrint(Queue* pq)
{
	assert(pq);
	QueueNode* cur = pq->_head->_next;
	while (cur)
	{
		printf("%d ", cur->_data);
		cur = cur->_next;
	}
	printf("\n");
}
void QueueTest()
{
	Queue q;
	//QueueInit(&q);
	//QueuePush(&q, 1);
	//QueuePush(&q, 2);
	//QueuePush(&q, 3);
	////printf("%d\n",QueueFront(&q));
	////QueuePop(&q);
	//printf("%d\n", QueueEmpty(&q));
	//printf("%d\n", QueueSize(&q));
	//QueuePrint(&q);
	QueueDestory(&q);
}