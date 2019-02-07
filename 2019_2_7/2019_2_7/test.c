#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

//���ݶ�������ǰ�����򹹽�������
//Ϊ����ݹ鴴�����Ӻ���
struct TreeNode* _buildTree(int* preorder, int* ppreindex, int* inorder, int inbegin, int inend)
{
	//��������û��Ԫ�أ����ؿ�
	if (inbegin > inend)
		return NULL;
	struct TreeNode* root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
	root->val = preorder[*ppreindex];
	++(*ppreindex);
	//��������ֻ��һ��Ԫ�أ���ֱ�ӽ���Ԫ�ص������ڵ㹹��������������������Ϊ�գ������ظ�
	if (inbegin == inend)
	{
		root->left = NULL;
		root->right = NULL;
		return root;
	}

	//�����䲻ֹһ��Ԫ�أ�������������
	//������������������
	//����ǰ������ҵ��ĸ��ڵ�������������ҵ���Ӧ�ĸ��ڵ㽫�������������仮��
	int rootindex = inbegin; //������������и��ڵ���±�
	while (rootindex <= inend)
	{
		if (inorder[rootindex] == root->val)
			break;
		else
			++rootindex;
	}
	assert(rootindex <= inend);

	//��������������Ϊ[inbegin,rootindex-1]������������
	root->left = _buildTree(preorder, ppreindex, inorder, inbegin, rootindex - 1);
	//��������������Ϊ[rootindex+1,inend]������������
	root->right = _buildTree(preorder, ppreindex, inorder, rootindex + 1, inend);

	return root;  //����ɹ����ظ��ڵ�
}
struct TreeNode* buildTree(int* preorder, int preorderSize, int* inorder, int inorderSize) {
	int preindex = 0;
	return _buildTree(preorder, &preindex, inorder, 0, inorderSize - 1);
}
