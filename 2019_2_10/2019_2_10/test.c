#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <assert.h>
// ֧�ֶ�̬������ջ
typedef struct TreeNode* STDataType;

typedef struct Stack
{
	STDataType* _array;
	int _top;//ջ��
	int _capacity;//����
}Stack;

void StackInit(Stack* ps)
{
	assert(ps);
	ps->_array = NULL;
	ps->_capacity = ps->_top = 0;
}
void StackDestory(Stack* ps)
{
	assert(ps);
	free(ps->_array);
	ps->_array = NULL;
	ps->_capacity = 0;
	ps->_top = 0;
}

void StackPush(Stack* ps, STDataType x)
{
	assert(ps);
	if (ps->_top == ps->_capacity)
	{
		size_t newcapacity = ps->_capacity == 0 ? 4 : ps->_capacity * 2;
		ps->_array = (STDataType*)realloc(ps->_array, sizeof(STDataType)*newcapacity);
		assert(ps->_array);
		ps->_capacity = newcapacity;
	}
	ps->_array[ps->_top] = x;
	++ps->_top;

}
void StackPop(Stack* ps)
{
	assert(ps && ps->_top > 0);
	--ps->_top;
}
STDataType StackTop(Stack* ps)
{
	assert(ps && ps->_top > 0);
	return ps->_array[ps->_top - 1];
}

int StackEmpty(Stack* ps)
{
	assert(ps);
	return ps->_top == 0 ? 0 : 1;
}
int StackSize(Stack* ps)
{
	assert(ps);
	return ps->_top;
}

//�ǵݹ�ʵ�ֶ�������ǰ�����
int* preorderTraversal(struct TreeNode* root, int* returnSize) {
	Stack st;
	StackInit(&st);

	struct TreeNode* cur = root;
	while (StackEmpty(&st) != 0 || cur != NULL)
	{
		//������·�ڵ㲢��ջ
		while (cur != NULL)
		{
			//printf("%d ",cur->val);

			++(*returnSize);
			StackPush(&st, cur);
			cur = cur->left;
		}

		//ȡջ��Ԫ�أ���������������
		struct TreeNode* top = StackTop(&st);
		StackPop(&st);

		//�����⣺���ʶ�Ӧ��·�ڵ��������
		cur = top->right;

	}

	int* prearray = (int*)malloc(sizeof(int)*(*returnSize));
	int i = 0;
	cur = root;
	while (StackEmpty(&st) != 0 || cur != NULL)
	{
		// 1.������·�ڵ㲢��ջ
		while (cur != NULL)
		{
			printf("%d ", cur->val);
			prearray[i++] = cur->val;

			StackPush(&st, cur);
			cur = cur->left;
		}

		struct TreeNode* top = StackTop(&st);
		StackPop(&st);

		// �����⣺����������
		cur = top->right;
	}

	return prearray;
}



//�ǵݹ�ʵ�ֶ��������������

int* inorderTraversal(struct TreeNode* root, int* returnSize) {
	Stack st;
	StackInit(&st);
	struct TreeNode* cur = root;
	while (StackEmpty(&st) != 0 || cur != NULL)
	{
		// 1.������·�ڵ㲢��ջ
		while (cur != NULL)
		{
			//printf("%d ", cur->val);
			++(*returnSize);

			StackPush(&st, cur);
			cur = cur->left;
		}

		struct TreeNode* top = StackTop(&st);
		StackPop(&st);

		// �����⣺����������
		cur = top->right;
	}

	int* inarray = (int*)malloc(4 * (*returnSize));
	int i = 0;
	cur = root;
	while (StackEmpty(&st) != 0 || cur != NULL)
	{
		// 1.������·�ڵ㲢��ջ
		while (cur != NULL)
		{
			StackPush(&st, cur);
			cur = cur->left;
		}

		struct TreeNode* top = StackTop(&st);
		printf("%d ", top->val);
		inarray[i++] = top->val;
		StackPop(&st);

		// �����⣺����������
		cur = top->right;
	}

	return inarray;
}

//�ǵݹ�ʵ�ֶ������ĺ������
int* postorderTraversal(struct TreeNode* root, int* returnSize) {
	Stack st;
	StackInit(&st);

	//ȷ�������Ķ������м����ڵ�
	struct TreeNode* prev = NULL;
	struct TreeNode* cur = root;
	while (StackEmpty(&st) != 0 || cur != NULL)
	{
		while (cur != NULL)
		{
			//��һֱ��ջ������ĸ��ڵ�
			StackPush(&st, cur);
			cur = cur->left;
		}

		//�������нڵ�ȷ���ڵ��������returnSize�Ĵ�С�����Կ��ٴ洢�ڵ������
		struct TreeNode* top = StackTop(&st);
		if (top->right == NULL || top->right == prev)
		{
			printf("%d ", top->val);
			StackPop(&st);
			prev = top;
			++(*returnSize);
		}
		else
		{
			// �����⣺����������
			cur = top->right;
		}
	}
	//����һ������洢��������Ľڵ�
	int* postarray = (int*)malloc(sizeof(int)*(*returnSize));
	int i = 0;
	prev = NULL;
	cur = root;
	while (StackEmpty(&st) != 0 || cur != NULL)
	{
		// 1.������·�ڵ㲢��ջ
		while (cur != NULL)
		{
			StackPush(&st, cur);
			cur = cur->left;
		}

		struct TreeNode* top = StackTop(&st);
		if (top->right == NULL || top->right == prev)
		{
			StackPop(&st);
			postarray[i++] = top->val;
			prev = top;
		}
		else
		{
			// �����⣺����������
			cur = top->right;
		}
	}

	return postarray;
}

