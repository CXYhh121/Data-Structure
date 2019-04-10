#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
using namespace std;

//二叉树的最大深度，递归求解
//class Solution {
//public:
//	int maxDepth(TreeNode* root) {
//		if (root == NULL)
//			return 0;
//
//		int left = maxDepth(root->left);
//		int right = maxDepth(root->right);
//
//		return (left > right) ? (left + 1) : (right + 1);
//	}
//};

//二叉树的最大深度，非递归求解

//class Solution {
//public:
//	int maxDepth(TreeNode* root) {
//		if (root == NULL)
//			return 0;
//		int num = 0;
//		queue<TreeNode*>  que;
//		que.push(root);
//		while (!que.empty()){
//			int n = que.size();
//			for (int i = 0; i < n; ++i){
//				TreeNode *cur = que.front();
//				if (cur->left != NULL)
//					que.push(cur->left);
//				if (cur->right != NULL)
//					que.push(cur->right);
//				que.pop();
//			}
//			num++;
//		}
//		return num;
//	}
//};


//二叉树的最小深度递归求解
//class Solution {
//public:
//	int minDepth(TreeNode* root) {
//		if (root == NULL)
//			return 0;
//		if (!root->left && !root->right)
//			return 1;
//
//		int left = minDepth(root->left);
//		int right = minDepth(root->right);
//
//		if (!left)
//			return 1 + right;
//		if (!right)
//			return 1 + left;
//
//		return min(left, right) + 1;
//
//	}
//};


//平衡二叉树
//class Solution {
//public:
//	int maxDepth(TreeNode* root) {
//		if (root == NULL)
//			return 0;
//
//		int left = maxDepth(root->left);
//		int right = maxDepth(root->right);
//
//		return (left > right) ? (left + 1) : (right + 1);
//	}
//	bool isBalanced(TreeNode* root) {
//		if (root == NULL)
//			return true;
//		if (abs(maxDepth(root->left) - maxDepth(root->right)) > 1)
//			return false;
//		else
//		{
//			if (isBalanced(root->left) == false)
//				return false;
//			if (isBalanced(root->right) == false)
//				return false;
//			return true;
//		}
//	}
//};