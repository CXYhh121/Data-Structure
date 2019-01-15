#ifndef __BTREE_H__
#define __BTREE_H__
#include"common.h"


//通过前序遍历的数组"ABD##E#H##CF##G##"构建二叉树
BTNode* BinaryTreeCreate(BTDatatype* array, int* pIndex);
void BinaryTreeDestory(BTNode** root);

int BinaryTreeSize(BTNode* root);
int BinaryTreeLeafSize(BTNode* root);
int BinaryTreeLevelSize(BTNode* root, int k);

BTNode* BinaryTreeFind(BTNode* root, BTDatatype x);

//遍历
void BinaryTreePrevOrder(BTNode* root);
void BinaryTreeInOrder(BTNode* root);
void BinaryTreePostOrder(BTNode* root);

//层序遍历
void  BinaryTreeLevelOrder(BTNode* root);
//判断二叉树是否为完全二叉树
int BinaryTreeComplete(BTNode* root);

void BTreeTest();

#endif //__BTREE_H__