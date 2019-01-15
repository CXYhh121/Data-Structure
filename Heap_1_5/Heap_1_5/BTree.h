#ifndef __BTREE_H__
#define __BTREE_H__
#include"common.h"


//ͨ��ǰ�����������"ABD##E#H##CF##G##"����������
BTNode* BinaryTreeCreate(BTDatatype* array, int* pIndex);
void BinaryTreeDestory(BTNode** root);

int BinaryTreeSize(BTNode* root);
int BinaryTreeLeafSize(BTNode* root);
int BinaryTreeLevelSize(BTNode* root, int k);

BTNode* BinaryTreeFind(BTNode* root, BTDatatype x);

//����
void BinaryTreePrevOrder(BTNode* root);
void BinaryTreeInOrder(BTNode* root);
void BinaryTreePostOrder(BTNode* root);

//�������
void  BinaryTreeLevelOrder(BTNode* root);
//�ж϶������Ƿ�Ϊ��ȫ������
int BinaryTreeComplete(BTNode* root);

void BTreeTest();

#endif //__BTREE_H__