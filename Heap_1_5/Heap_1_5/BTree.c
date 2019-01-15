#define _CRT_SECURE_NO_WARNINGS
#include"common.h"
#include"BTree.h"
#include"Queue.h"

//通过前序遍历的数组"ABD##E#H##CF##G##"构建二叉树
BTNode* BinaryTreeCreate(BTDatatype* array, int* pIndex)
{
	if (array[(*pIndex)] == '#')
	{
		(*pIndex)++;
		return NULL;
	}

		BTNode* root = (BTNode*)malloc(sizeof(BTNode));
		root->_left = NULL;
		root->_right = NULL;
		root->_data = array[(*pIndex)];

		(*pIndex)++;
		root->_left = BinaryTreeCreate(array, pIndex);
		root->_right = BinaryTreeCreate(array, pIndex);

		return root;
	

}
void BinaryTreeDestory(BTNode** root)
{

}

int BinaryTreeSize(BTNode* root)
{
	if (root == NULL)
		return 0;
	return BinaryTreeSize(root->_left) + BinaryTreeSize(root->_right) + 1;
}
//int BinaryTreeLeafSize(BTNode* root)
//{
//	if (root == NULL)
//		return 0;
//	int LeftLeaf = 0;
//	int RightLeaf = 0;
//
//	if (root->_left == NULL && root->_right == NULL)
//		return 1;
//	LeftLeaf = BinaryTreeLeafSize(root->_left);
//	RightLeaf = BinaryTreeLeafSize(root->_right);
//
//	return LeftLeaf + RightLeaf;
//}
int BinaryTreeLeafSize(BTNode* root)
{
	if (root == NULL)
		return 0;
	if (root->_left == NULL && root->_right == NULL)
		return 1;
	return BinaryTreeLeafSize(root->_left) + BinaryTreeLeafSize(root->_right);
}
int BinaryTreeLevelSize(BTNode* root, int k)
{
	if (root == NULL)
		return 0;
	if (k == 1)
		return 1;
	return BinaryTreeLevelSize(root->_left, k - 1) 
		+ BinaryTreeLevelSize(root->_right, k - 1);
}

BTNode* BinaryTreeFind(BTNode* root, BTDatatype x)
{
	BTNode* ret = NULL;
	if (root == NULL)
		return NULL;
	if (root->_data == x)
		return root;
	ret = BinaryTreeFind(root->_left, x);
	if (ret)
		return ret;
	ret = BinaryTreeFind(root->_right, x);
	if (ret)
		return ret;

	return NULL;
}

//遍历
void BinaryTreePrevOrder(BTNode* root)
{
	if (root == NULL)
		return;
	printf("%c ", root->_data);

	BinaryTreePrevOrder(root->_left);
	BinaryTreePrevOrder(root->_right);
}
void BinaryTreeInOrder(BTNode* root)
{
	if (root == NULL)
		return;
	
	BinaryTreeInOrder(root->_left);
	printf("%c ", root->_data);
	BinaryTreeInOrder(root->_right);

}
void BinaryTreePostOrder(BTNode* root)
{
	if (root == NULL)
		return;
	BinaryTreePostOrder(root->_left);
	BinaryTreePostOrder(root->_right);
	printf("%c ", root->_data);
	
}

//层序遍历
void  BinaryTreeLevelOrder(BTNode* root)
{
	Queue q;
	QueueInit(&q);
	if (root != NULL)
	{
		QueuePush(&q, root);
		while (QueueEmpty(&q) != 0)
		{
			BTNode* front = QueueFront(&q);
			printf("%c ", front->_data);
			QueuePop(&q);
			if (front->_left)
				QueuePush(&q, front->_left);
			if (front->_right)
				QueuePush(&q, front->_right);
		}
		printf("\n");
	}
}
//判断二叉树是否为完全二叉树
int BinaryTreeComplete(BTNode* root)
{
	Queue q;
	QueueInit(&q);
	if (root != NULL)
	{
		QueuePush(&q, root);
		while (QueueEmpty(&q) != 0)
		{
			BTNode* front = QueueFront(&q);
			QueuePop(&q);

			if (front == NULL)
				break;

			QueuePush(&q, front->_left);
			QueuePush(&q, front->_right);
		}
		while (QueueEmpty(&q) != 0)
		{
			BTNode* front = QueueFront(&q);
			if (front != NULL)
			{
				QueueDestory(&q);
				return 0;
			}
			QueuePop(&q);
		}
	}
	return 1;
}


void BTreeTest()
{
	char array[100] = "ABD##E#H##CF##G##";
	//构造二叉树
	int Index = 0;
	BTNode* tree = BinaryTreeCreate(array, &Index);
	
	printf("%d\n", BinaryTreeSize(tree));
	printf("%d\n", BinaryTreeLevelSize(tree,3));
	printf("%d\n", BinaryTreeLeafSize(tree));
	BinaryTreePrevOrder(tree);
	printf("\n");
	BinaryTreeInOrder(tree);
	printf("\n");
	BinaryTreePostOrder(tree);
	printf("\n");
	BinaryTreeLevelOrder(tree);

	printf("%d\n", BinaryTreeComplete(tree));
}