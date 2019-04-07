#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
using namespace std;

//二叉树的层序遍历

struct TreeNode
{
	int val;
	TreeNode* left;
	TreeNode* right;
};
class Solution {
public:
	void pre(TreeNode *root, int depth, vector<vector<int>> &ans) {
		if (!root) return;
		if (depth >= ans.size())
			ans.push_back(vector<int> {});
		ans[depth].push_back(root->val);
		pre(root->left, depth + 1, ans);
		pre(root->right, depth + 1, ans);
	}
	vector<vector<int>> levelOrder(TreeNode* root) {
		vector<vector<int>> ans;
		pre(root, 0, ans);
		return ans;
	}
};

//二叉树的层序遍历II
class Solution {
public:
	void pre(TreeNode *root, int depth, vector<vector<int>> &ans) {
		if (root == NULL) return;
		if (depth >= ans.size())
			ans.push_back(vector<int> {});
		ans[depth].push_back(root->val);
		pre(root->left, depth + 1, ans);
		pre(root->right, depth + 1, ans);
	}
	vector<vector<int>> levelOrderBottom(TreeNode* root) {
		vector<vector<int>> ans;
		pre(root, 0, ans);

		reverse(ans.begin(), ans.end());
		return ans;
	}
};

