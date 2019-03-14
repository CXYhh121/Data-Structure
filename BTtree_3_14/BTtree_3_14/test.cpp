#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <stack>
using namespace std;

//�������Ĳ������

//class Solution {
//public:
//	vector<vector<int>> levelOrder(TreeNode* root) {
//		queue<TreeNode*> nodeq;//����һ�����д洢�ڵ�
//		queue<int> levelq;//����һ�����д洢�ڵ�Ĳ���
//
//		if (root != NULL)
//		{
//			nodeq.push(root);
//			levelq.push(1);
//		}
//
//		vector<vector<int>> vv;
//		while (nodeq.empty() != 1)
//		{
//			TreeNode* node = nodeq.front();
//			nodeq.pop();
//			int level = levelq.front();
//			levelq.pop();
//			//Ϊ���vector��vector���ٿռ�
//			if (level > vv.size())
//				vv.push_back(vector<int>());//���ô�ȱʡֵ���캯��
//			vv[level - 1].push_back(node->val);
//
//			if (node->left)
//			{
//				nodeq.push(node->left);
//				levelq.push(level + 1);
//			}
//
//			if (node->right)
//			{
//				nodeq.push(node->right);
//				levelq.push(level + 1);
//			}
//		}
//
//		return vv;
//
//	}
//};
//


//����������Ƚڵ�
//class Solution {
//public:
//	bool getpath(TreeNode* root, TreeNode* node, stack<TreeNode*>& path)
//	{
//		if (root == NULL)
//			return false;
//		path.push(root);
//		if (root == node)
//			return true;
//
//		if (getpath(root->left, node, path))
//			return true;
//		if (getpath(root->right, node, path))
//			return true;
//
//		path.pop();
//		return false;
//	}
//	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
//		stack<TreeNode*> ppath;
//		stack<TreeNode*> qpath;
//
//		getpath(root, p, ppath);
//		getpath(root, q, qpath);
//
//		while (ppath.size() != qpath.size())
//		{
//			if (ppath.size() > qpath.size())
//				ppath.pop();
//			else
//				qpath.pop();
//		}
//
//		while (ppath.top() != qpath.top())
//		{
//			ppath.pop();
//			qpath.pop();
//		}
//		return ppath.top();
//	}
//};


//����
class Solution {
public:
	string countAndSay(int n) {
		if (n == 1)
			return to_string(1);

		int i = 0;
		string s = countAndSay(n - 1);
		string ans;
		while (i < s.size()) {
			int t = i;
			if (i == s.size() - 1) {
				ans += to_string(1) + s[i];
				break;
			}
			while (i + 1 < s.size() && s[i] == s[i + 1])
				++i;
			ans += to_string(i - t + 1) + s[i];
			++i;
		}
		return ans;

	}
};