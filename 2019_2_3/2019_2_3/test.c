#define _CRT_SECURE_NO_WARNINGS
//���ƴ����ָ�������

typedef struct RandomListNode RLNode;
struct RandomListNode *copyRandomList(struct RandomListNode *head) {
	RLNode* cur = head;
	//���˿���ԭ����Ԫ��������ԭ����֮��
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
	//��������Ԫ�ص����ָ�밴��ԭ��������ָ��һ������
	while (cur)
	{
		//��¼�����ڵ��λ��
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


	//�������������ԭ�����ϲ�ֳ���
	RLNode* tail, *copyhead;//����һ���µ������ͷָ���βָ��
	tail = copyhead = (RLNode*)malloc(sizeof(RLNode));
	cur = head;
	while (cur)
	{
		RLNode* copy = cur->next;
		RLNode* next = copy->next;

		tail->next = copy;
		tail = copy;

		cur->next = next;//��ԭԭ����
		cur = next;
	}
	RLNode* newnode = copyhead->next;
	free(copyhead);

	return newnode;
}
