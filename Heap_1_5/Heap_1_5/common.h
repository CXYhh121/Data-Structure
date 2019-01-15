#pragma once
#include<stdio.h>
#include<string.h>
#include<assert.h>
#include<stdlib.h>


typedef char BTDatatype;

typedef struct BinaryTreeNode
{
	BTDatatype _data;
	struct BinaryTreeNode* _left;
	struct BinaryTreeNode* _right;

}BTNode;

typedef BTNode* QDataType;
typedef struct QueueNode
{
	QDataType _data;
	struct QueueNode* _next;
}QueueNode;

typedef struct Queue
{
	QueueNode* _head;
	QueueNode* _tail;	
}Queue;

////�����ҽڵ���ڷ���1�����ڷ���0
//int TreeFind(struct TreeNode* root, struct TreeNode* node)
//{
//	if (root == NULL)
//		return 0;
//	if (root == node)
//		return 1;
//	if (TreeFind(root->left, node) == 1)
//		return 1;
//	else if (TreeFind(root->right, node) == 1)
//		return 1;
//	else
//		return 0;
//}
//struct TreeNode* lowestCommonAncestor(struct
//	TreeNode* root, struct TreeNode* p, struct TreeNode* q) {
//	if (root == NULL)
//		return NULL;
//	//������һ���ڵ����Լ�������
//	if (root == p || root == q)
//		return root;
//	int pInLeft = TreeFind(root->left, p);
//	int qInLeft = TreeFind(root->left, q);
//	//�����ڵ㶼��������
//	if (pInLeft == 1 && qInLeft == 1)
//		return lowestCommonAncestor(root->left, p, q);
//	//�����ڵ㶼��������
//	else if (pInLeft == 0 && qInLeft == 0)
//		return lowestCommonAncestor(root->right, p, q);
//	//һ������������һ����������
//	else
//		return root;
//}