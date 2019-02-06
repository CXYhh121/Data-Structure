#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

//二叉树的前序遍历(递归实现)
int treeSize(struct TreeNode* root)//计算所遍历二叉树节点的个数
{
	if (root == NULL)
		return 0;
	else
		return treeSize(root->left) + treeSize(root->right) + 1;
}
//为方便递归构造的子函数
void _preorderTraversal(struct TreeNode* root, int* preorder, int* pindex)
{
	if (root == NULL)
		return;

	preorder[*pindex] = root->val;//访问根节点
	++(*pindex);

	_preorderTraversal(root->left, preorder, pindex);//访问左子树
	_preorderTraversal(root->right, preorder, pindex);//访问右子树
}

int* preorderTraversal(struct TreeNode* root, int* returnSize) {
	*returnSize = treeSize(root);
	int* preorder = (int*)malloc(*returnSize * sizeof(int));

	int index = 0;
	_preorderTraversal(root, preorder, &index);

	return preorder;
}

//二叉树的中序遍历(递归实现)
int treeSize(struct TreeNode* root)
{
	if (root == NULL)
		return 0;
	else
		return treeSize(root->left) + treeSize(root->right) + 1;
}
void _postorderTraversal(struct TreeNode* root, int* postorder, int* pindex)
{
	if (root == NULL)
		return;

	_postorderTraversal(root->left, postorder, pindex);
	postorder[*pindex] = root->val;
	++(*pindex);
	_postorderTraversal(root->right, postorder, pindex);

}
int* postorderTraversal(struct TreeNode* root, int* returnSize) {
	*returnSize = treeSize(root);
	int* postorder = (int*)malloc(*returnSize*sizeof(int));

	int index = 0;
	_postorderTraversal(root, postorder, &index);

	return postorder;
}

//二叉树的后序遍历（递归实现）LeetCode144题
   int treeSize(struct TreeNode* root)
{
	   if (root == NULL)
		   return 0;
	   else
		   return treeSize(root->left) + treeSize(root->right) + 1;
   }
	 void _postorderTraversal(struct TreeNode* root, int* postorder, int* pindex)
	 {
		 if (root == NULL)
			 return;

		 _postorderTraversal(root->left, postorder, pindex);
		 _postorderTraversal(root->right, postorder, pindex);
		 postorder[*pindex] = root->val;
		 ++(*pindex);

	 }
	 int* postorderTraversal(struct TreeNode* root, int* returnSize) {
		 *returnSize = treeSize(root);
		 int* postorder = (int*)malloc(*returnSize*sizeof(int));

		 int index = 0;
		 _postorderTraversal(root, postorder, &index);

		 return postorde;
	 }

//判断是否为相同的数
bool isSameTree(struct TreeNode* p, struct TreeNode* q) {
	if (p == NULL && q == NULL)
		return true;
	else if (p != NULL && q != NULL)
	{
		return p->val == q->val
			&& isSameTree(p->left, q->left)
			&& isSameTree(p->right, q->right);
	}
	else
		return false;
}