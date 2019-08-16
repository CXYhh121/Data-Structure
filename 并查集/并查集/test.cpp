#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>

using namespace std;

//并查集实现(并查集其实是一个森林)
class UnionFindSet
{
public:
	UnionFindSet(size_t N)
	{
		_ufs.resize(N, -1);
	}
	bool Union(int x1, int x2)
	{
		int root1 = FindRoot(x1);
		int root2 = FindRoot(x2);
		if (root1 == root2)
			return false;
		else
		{
			_ufs[root1] += _ufs[root2];
			_ufs[root2] = root1;
			return true;
		}
	}

	int FindRoot(int x)
	{
		while (_ufs[x] >= 0)
		{
			x = _ufs[x];
		}
		return x;
	}

	size_t Size()
	{
		size_t size = 0;
		for (size_t i = 0; i < _ufs.size(); ++i)
		{
			if (_ufs[i] < 0)
				size++;
		}
		return size;
	}
private:
	vector<int> _ufs;
};




//并查集的应用 朋友圈
//class Solution {
//public:
//	class UnionFindSet
//	{
//	public:
//		UnionFindSet(size_t N)
//		{
//			_ufs.resize(N, -1);
//		}
//		bool Union(int x1, int x2)
//		{
//			int root1 = FindRoot(x1);
//			int root2 = FindRoot(x2);
//			if (root1 == root2)
//				return false;
//			else
//			{
//				_ufs[root1] += _ufs[root2];
//				_ufs[root2] = root1;
//				return true;
//			}
//		}
//
//		int FindRoot(int x)
//		{
//			while (_ufs[x] >= 0)
//			{
//				x = _ufs[x];
//			}
//			return x;
//		}
//
//		size_t Size()
//		{
//			size_t size = 0;
//			for (size_t i = 0; i < _ufs.size(); ++i)
//			{
//				if (_ufs[i] < 0)
//					size++;
//			}
//			return size;
//		}
//	private:
//		vector<int> _ufs;
//	};
//	int findCircleNum(vector<vector<int>>& M) {
//		UnionFindSet UFS(M.size());
//
//		for (int i = 0; i < M.size(); i++)
//		{
//			for (int j = 0; j < M[i].size(); ++j)
//			{
//				if (M[i][j] == 1)
//					UFS.Union(i, j);
//			}
//		}
//		return UFS.Size();
//	}
//};



//等式方程的可满足性
//class Solution {
//public:
//	bool equationsPossible(vector<string>& equations) {
//		UnionFindSet UFS(26);
//		for (size_t i = 0; i < equations.size(); ++i)
//		{
//			if (equations[i][1] == '=')
//			{
//				UFS.Union(equations[i][0] - 'a', equations[i][3] - 'a');
//			}
//		}
//
//		for (size_t i = 0; i < equations.size(); ++i)
//		{
//			if (equations[i][1] == '!')
//			{
//				int root1 = UFS.FindRoot(equations[i][0] - 'a');
//				int root2 = UFS.FindRoot(equations[i][3] - 'a');
//
//				if (root1 == root2)
//					return false;
//			}
//		}
//		return true;
//	}
//};