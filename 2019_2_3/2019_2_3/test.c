#define _CRT_SECURE_NO_WARNINGS
//复制带随机指针的链表

typedef struct RandomListNode RLNode;
struct RandomListNode *copyRandomList(struct RandomListNode *head) {
	RLNode* cur = head;
	//依此拷贝原链表元素链接在原链表之后
	while (cur)
	{
		RLNode* copy = (RLNode*)malloc(sizeof(RLNode));
		RLNode* next = cur->next;
		copy->label = cur->label;
		copy->next = cur->next;
		cur->next = copy;

		cur = next;
	}

	cur = head;
	//将拷贝的元素的随机指针按照原链表的随机指针一样放置
	while (cur)
	{
		//记录拷贝节点的位置
		RLNode* copy = cur->next;
		if (cur->random)
		{
			copy->random = cur->random->next;
		}
		else
		{
			copy->random = NULL;
		}

		cur = copy->next;
	}


	//将拷贝的链表从原链表上拆分出来
	RLNode* tail, *copyhead;//定义一个新的链表的头指针和尾指针
	tail = copyhead = (RLNode*)malloc(sizeof(RLNode));
	cur = head;
	while (cur)
	{
		RLNode* copy = cur->next;
		RLNode* next = copy->next;

		tail->next = copy;
		tail = copy;

		cur->next = next;//复原原链表
		cur = next;
	}
	RLNode* newnode = copyhead->next;
	free(copyhead);

	return newnode;
}
