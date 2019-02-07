#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

//根据二叉树的前序中序构建二叉树
//为方便递归创建的子函数
struct TreeNode* _buildTree(int* preorder, int* ppreindex, int* inorder, int inbegin, int inend)
{
	//若区间中没有元素，返回空
	if (inbegin > inend)
		return NULL;
	struct TreeNode* root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
	root->val = preorder[*ppreindex];
	++(*ppreindex);
	//若区间中只有一个元素，可直接将该元素当做根节点构建二叉树，左右子树均为空，并返回根
	if (inbegin == inend)
	{
		root->left = NULL;
		root->right = NULL;
		return root;
	}

	//若区间不止一个元素，划分子问题解决
	//根，左子树，右子树
	//根据前序遍历找到的根节点在中序遍历中找到对应的根节点将左右子树的区间划分
	int rootindex = inbegin; //定义中序遍历中根节点的下标
	while (rootindex <= inend)
	{
		if (inorder[rootindex] == root->val)
			break;
		else
			++rootindex;
	}
	assert(rootindex <= inend);

	//左子树所在区间为[inbegin,rootindex-1]，构造左子树
	root->left = _buildTree(preorder, ppreindex, inorder, inbegin, rootindex - 1);
	//右子树所在区间为[rootindex+1,inend]，构造右子树
	root->right = _buildTree(preorder, ppreindex, inorder, rootindex + 1, inend);

	return root;  //构造成功返回根节点
}
struct TreeNode* buildTree(int* preorder, int preorderSize, int* inorder, int inorderSize) {
	int preindex = 0;
	return _buildTree(preorder, &preindex, inorder, 0, inorderSize - 1);
}
