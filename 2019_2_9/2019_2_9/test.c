#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

void _tree2str(struct TreeNode* t, char*str)
{
	if (t == NULL)
		return;
	//处理根节点，将根节点转化为字符
	char buff[12];
	sprintf(buff, "%d", t->val);
	strcat(str, buff);

	//处理左子树
	if (t->left == NULL)
	{
		if (t->right == NULL)
			return;
		else
			strcat(str, "()");
	}
	else
	{
		strcat(str, "(");
		_tree2str(t->left, str);
		strcat(str, ")");
	}
	//处理右子树
	if (t->right == NULL)
	{
		return;
	}
	else
	{
		strcat(str, "(");
		_tree2str(t->right, str);
		strcat(str, ")");
	}

}
char* tree2str(struct TreeNode* t) {
	char* str = (char*)malloc(1024 * 1024);
	_tree2str(t, str);
	return str;

}
//找两个的点的最近祖先节点

//若所找节点存在返回1，不在返回0
int TreeFind(struct TreeNode* root, struct TreeNode* node)
{
	if (root == NULL)
		return 0;
	if (root == node)
		return 1;
	if (TreeFind(root->left, node) == 1)
		return 1;
	else if (TreeFind(root->right, node) == 1)
		return 1;
	else
		return 0;
}
struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q) {
	if (root == NULL)
		return NULL;
	//若其中一个节点是自己的祖先
	if (root == p || root == q)
		return root;
	int pInLeft = TreeFind(root->left, p);
	int qInLeft = TreeFind(root->left, q);
	//两个节点都在左子树
	if (pInLeft == 1 && qInLeft == 1)
		return lowestCommonAncestor(root->left, p, q);
	//两个节点都在右子树
	else if (pInLeft == 0 && qInLeft == 0)
		return lowestCommonAncestor(root->right, p, q);
	//一个在左子树，一个在右子树
	else
		return root;
}