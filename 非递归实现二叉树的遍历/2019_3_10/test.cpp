#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <vector>
#include <stack>
using namespace std;
//
//class A
//{
//public:
//	void foo()
//	{
//		printf("1");
//	}
//	virtual void fun()
//	{
//		printf("2");
//	}
//};
//class B : public A
//{
//public:
//	void foo()
//	{
//		printf("3");
//	}
//	void fun()
//	{
//		printf("4");
//	}
//};
//int main(void)
//{
//	A a;
//	B b;
//	A *p = &a;
//	p->foo();
//	p->fun();
//	p = &b;
//	p->foo();
//	p->fun();
//	A *ptr = (A *)&b;
//	ptr->foo();
//	ptr->fun();
//	return 0;
//}


class A{
public:
	long a;
};
class B : public A {
public:
	long b;
};
void seta(A* data, int idx) {
	data[idx].a = 2;
}
int main(int argc, char *argv[]) {
	B data[4];
	for (int i = 0; i<4; ++i){
		data[i].a = 1;
		data[i].b = 1;
		seta(data, i);
	}
	for (int i = 0; i<4; ++i){
		std::cout << data[i].a ;
		std::cout << data[i].b;
	}
	return 0;
}


//��������ǰ�����

//class Solution {
//public:
//	vector<int> preorderTraversal(TreeNode* root) {
//		vector<int> preV;
//		if (root == NULL)
//			return preV;
//		stack<TreeNode*> st;
//		TreeNode* cur = root;
//		while (st.empty() != 1 || cur != NULL)
//		{
//			// 1.������·�ڵ㲢��ջ
//			while (cur != NULL)
//			{
//				preV.push_back(cur->val);
//				st.push(cur);
//
//				cur = cur->left;
//			}
//
//			struct TreeNode* top = st.top();
//			st.pop();
//
//			// �����⣺����������
//			cur = top->right;
//		}
//		return preV;
//	}
//};

//���������������
//class Solution {
//public:
//	vector<int> inorderTraversal(TreeNode* root) {
//		vector<int> inV;
//		if (root == NULL)
//			return inV;
//
//		TreeNode* cur = root;
//		stack<TreeNode*> st;
//		while (st.empty() != 1 || cur != NULL)
//		{
//			while (cur != NULL)
//			{
//				st.push(cur);
//				cur = cur->left;
//			}
//			TreeNode* top = st.top();
//			inV.push_back(top->val);
//			st.pop();
//
//			//�����⣬������·����������
//			cur = top->right;
//		}
//		return inV;
//	}
//};

//�������ĺ������
//class Solution {
//public:
//	vector<int> postorderTraversal(TreeNode* root) {
//		vector<int> postV;
//		if (root == NULL)
//			return postV;
//		TreeNode* cur = root;
//		TreeNode* prev = NULL;//����һ��ָ��ָ��cur��ǰһ��λ��
//
//		stack<TreeNode*> st;
//		while (st.empty() != 1 || cur != NULL)
//		{
//			//������·��㲢��ջ
//			while (cur != NULL)
//			{
//				st.push(cur);
//				cur = cur->left;
//			}
//			TreeNode* top = st.top();
//			if (top->right == NULL || top->right == prev)
//			{
//				postV.push_back(top->val);
//				st.pop();
//				prev = top;
//			}
//			else
//			{
//				//�����⣬������·����������
//				cur = top->right;
//			}
//		}
//		return postV;
//
//	}
//};

