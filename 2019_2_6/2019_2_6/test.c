#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
//另一棵树的子树
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
bool isSubtree(struct TreeNode* s, struct TreeNode* t) {
	if (s == NULL)
		return false;
	if (isSameTree(s, t))
		return true;
	if (isSubtree(s->left, t))
		return true;
	if (isSubtree(s->right, t))
		return true;

	return false;
}

//返回二叉树的最大深度
int maxDepth(struct TreeNode* root) {
	if (root == NULL)
		return 0;
	int leftdepth = maxDepth(root->left);
	int rightdepth = maxDepth(root->right);

	if (leftdepth > rightdepth)
		return leftdepth + 1;
	else
		return  rightdepth + 1;

}