#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <assert.h>
// 支持动态增长的栈
typedef struct TreeNode* STDataType;

typedef struct Stack
{
	STDataType* _array;
	int _top;//栈顶
	int _capacity;//容量
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

//非递归实现二叉树的前序遍历
int* preorderTraversal(struct TreeNode* root, int* returnSize) {
	Stack st;
	StackInit(&st);

	struct TreeNode* cur = root;
	while (StackEmpty(&st) != 0 || cur != NULL)
	{
		//访问左路节点并入栈
		while (cur != NULL)
		{
			//printf("%d ",cur->val);

			++(*returnSize);
			StackPush(&st, cur);
			cur = cur->left;
		}

		//取栈顶元素，并访问其右子树
		struct TreeNode* top = StackTop(&st);
		StackPop(&st);

		//子问题：访问对应左路节点的右子树
		cur = top->right;

	}

	int* prearray = (int*)malloc(sizeof(int)*(*returnSize));
	int i = 0;
	cur = root;
	while (StackEmpty(&st) != 0 || cur != NULL)
	{
		// 1.访问坐路节点并入栈
		while (cur != NULL)
		{
			printf("%d ", cur->val);
			prearray[i++] = cur->val;

			StackPush(&st, cur);
			cur = cur->left;
		}

		struct TreeNode* top = StackTop(&st);
		StackPop(&st);

		// 子问题：访问右子树
		cur = top->right;
	}

	return prearray;
}



//非递归实现二叉树的中序遍历

int* inorderTraversal(struct TreeNode* root, int* returnSize) {
	Stack st;
	StackInit(&st);
	struct TreeNode* cur = root;
	while (StackEmpty(&st) != 0 || cur != NULL)
	{
		// 1.访问坐路节点并入栈
		while (cur != NULL)
		{
			//printf("%d ", cur->val);
			++(*returnSize);

			StackPush(&st, cur);
			cur = cur->left;
		}

		struct TreeNode* top = StackTop(&st);
		StackPop(&st);

		// 子问题：访问右子树
		cur = top->right;
	}

	int* inarray = (int*)malloc(4 * (*returnSize));
	int i = 0;
	cur = root;
	while (StackEmpty(&st) != 0 || cur != NULL)
	{
		// 1.访问坐路节点并入栈
		while (cur != NULL)
		{
			StackPush(&st, cur);
			cur = cur->left;
		}

		struct TreeNode* top = StackTop(&st);
		printf("%d ", top->val);
		inarray[i++] = top->val;
		StackPop(&st);

		// 子问题：访问右子树
		cur = top->right;
	}

	return inarray;
}

//非递归实现二叉树的后序遍历
int* postorderTraversal(struct TreeNode* root, int* returnSize) {
	Stack st;
	StackInit(&st);

	//确定遍历的二叉树有几个节点
	struct TreeNode* prev = NULL;
	struct TreeNode* cur = root;
	while (StackEmpty(&st) != 0 || cur != NULL)
	{
		while (cur != NULL)
		{
			//从一直入栈到最左的根节点
			StackPush(&st, cur);
			cur = cur->left;
		}

		//访问所有节点确定节点个数（即returnSize的大小）用以开辟存储节点的数组
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
			// 子问题：访问右子树
			cur = top->right;
		}
	}
	//开辟一个数组存储后序遍历的节点
	int* postarray = (int*)malloc(sizeof(int)*(*returnSize));
	int i = 0;
	prev = NULL;
	cur = root;
	while (StackEmpty(&st) != 0 || cur != NULL)
	{
		// 1.访问左路节点并入栈
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
			// 子问题：访问右子树
			cur = top->right;
		}
	}

	return postarray;
}

