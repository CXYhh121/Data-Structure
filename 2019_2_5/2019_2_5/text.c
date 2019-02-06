#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

//��������ǰ�����(�ݹ�ʵ��)
int treeSize(struct TreeNode* root)//�����������������ڵ�ĸ���
{
	if (root == NULL)
		return 0;
	else
		return treeSize(root->left) + treeSize(root->right) + 1;
}
//Ϊ����ݹ鹹����Ӻ���
void _preorderTraversal(struct TreeNode* root, int* preorder, int* pindex)
{
	if (root == NULL)
		return;

	preorder[*pindex] = root->val;//���ʸ��ڵ�
	++(*pindex);

	_preorderTraversal(root->left, preorder, pindex);//����������
	_preorderTraversal(root->right, preorder, pindex);//����������
}

int* preorderTraversal(struct TreeNode* root, int* returnSize) {
	*returnSize = treeSize(root);
	int* preorder = (int*)malloc(*returnSize * sizeof(int));

	int index = 0;
	_preorderTraversal(root, preorder, &index);

	return preorder;
}

//���������������(�ݹ�ʵ��)
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

//�������ĺ���������ݹ�ʵ�֣�LeetCode144��
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

//�ж��Ƿ�Ϊ��ͬ����
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