#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

void _tree2str(struct TreeNode* t, char*str)
{
	if (t == NULL)
		return;
	//������ڵ㣬�����ڵ�ת��Ϊ�ַ�
	char buff[12];
	sprintf(buff, "%d", t->val);
	strcat(str, buff);

	//����������
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
	//����������
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
//�������ĵ��������Ƚڵ�

//�����ҽڵ���ڷ���1�����ڷ���0
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
	//������һ���ڵ����Լ�������
	if (root == p || root == q)
		return root;
	int pInLeft = TreeFind(root->left, p);
	int qInLeft = TreeFind(root->left, q);
	//�����ڵ㶼��������
	if (pInLeft == 1 && qInLeft == 1)
		return lowestCommonAncestor(root->left, p, q);
	//�����ڵ㶼��������
	else if (pInLeft == 0 && qInLeft == 0)
		return lowestCommonAncestor(root->right, p, q);
	//һ������������һ����������
	else
		return root;
}