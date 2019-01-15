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

////若所找节点存在返回1，不在返回0
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
//	//若其中一个节点是自己的祖先
//	if (root == p || root == q)
//		return root;
//	int pInLeft = TreeFind(root->left, p);
//	int qInLeft = TreeFind(root->left, q);
//	//两个节点都在左子树
//	if (pInLeft == 1 && qInLeft == 1)
//		return lowestCommonAncestor(root->left, p, q);
//	//两个节点都在右子树
//	else if (pInLeft == 0 && qInLeft == 0)
//		return lowestCommonAncestor(root->right, p, q);
//	//一个在左子树，一个在右子树
//	else
//		return root;
//}