#pragma once

#include <iostream>
using namespace std;

enum color
{
	RED,
	BLACK
};

template<class K,class V>
struct RBSTreeNode
{
	RBSTreeNode(const pair<K, V>& kv)
	:_left(nullptr)
	, _right(nullptr)
	, _parent(nullptr)
	, _kv(kv)
	, _col(RED)
	{}
	RBSTreeNode<K, V>* _left;
	RBSTreeNode<K, V>* _right;
	RBSTreeNode<K, V>* _parent;

	pair<K, V> _kv;
	color _col;
};

template<class K, class V>
class RBTree
{
	typedef RBSTreeNode<K, V> Node;
public:
	RBTree()
		:_root(nullptr)
	{}

	bool Insert(const pair<K, V>& kv)
	{
		//若树为空，直接插入
		if (_root == nullptr)
		{
			_root = new Node(kv);
			_root->_col = BLACK;
			return true;
		}

		//不为空，先找到插入位置再插入节点
		Node* parent = nullptr;
		Node* cur = _root;

		while (cur)
		{
			parent = cur;
			if (kv.first < cur->_kv.first)
				cur = cur->_left;
			else if (kv.first > cur->_kv.first)
				cur = cur->_right;
			else
				return false;//如果树中已经有该元素，则插入失败
		}

		//找到插入位置，插入节点
		//插入的节点颜色为红色，破坏红黑树的性质3,更好处理
		cur = new Node(kv);
		cur->_col = RED;
		if (kv.first < parent->_kv.first)
		{
			parent->_left = cur;
			cur->_parent = parent;
		}
		else
		{
			parent->_right = cur;
			cur->_parent = parent;
		}

		//插入节点成功后，检查红黑树的性质有没有被破坏
		//若是有则要进行节点的颜色调整以满足红黑树性质
		//若是父节点存在且父节点的颜色为红色则需要调整，否则满足红黑树性质
		while (parent && parent->_col == RED)
		{
			// 注意：grandFather一定存在
			// 因为parent存在，且不是黑色节点，则parent一定不是根，则其一定有双亲
			Node* grandfather = parent->_parent;
			
			//1、父节点是祖父节点的左孩子
			if (grandfather->_left == parent)
			{
				Node* uncle = grandfather->_right;
				//1、叔叔节点存在且叔叔节点的颜色为红色
				if (uncle && uncle->_col == RED)
				{
					parent->_col = uncle->_col = BLACK;
					grandfather->_col = RED;

					cur = grandfather;
					parent = cur->_parent;
				}

				//2、叔叔节点不存在或者叔叔节点的颜色为黑色
				else
				{
					//1、如果cur是parent的右孩子，此时需要进行左单旋将情况转换为情况2
					if (parent->_right == cur)
					{
						RotateL(parent);
						swap(cur, parent);
					}

					//1、如果cur是parent的z左孩子，此时只需进行一个右单旋，并将parent的颜色变为黑，grandparent的颜色置红
					RotateR(grandfather);
					grandfather->_col = RED;
					parent->_col = BLACK;
					break;
				}

			}

			//2、父节点是祖父节点的右孩子
			else
			{
				Node* uncle = grandfather->_left;
				//1、叔叔节点存在且叔叔节点的颜色为红色
				if (uncle && uncle->_col == RED)
				{
					parent->_col = uncle->_col = BLACK;
					grandfather->_col = RED;

					cur = grandfather;
					parent = cur->_parent;
				}

				//2、叔叔节点不存在或者叔叔节点的颜色为黑色
				else
				{
					//1、若是cur为parent的左孩子，先进行一个右单旋转换为情况二一起处理
					if (parent->_left == cur)
					{
						RotateR(parent);
						swap(cur, parent);
					}

					//2、若是cur为parent的右孩子，进行一个左单旋，并将parent的颜色变为黑，grandparent的颜色置红
					RotateL(grandfather);
					grandfather->_col = RED;
					parent->_col = BLACK;
					break;
				}
			}
		}

		//旋转完成之后，将根节点的颜色置成黑色
		_root->_col = BLACK;
		return true;
	}

	void RotateL(Node* parent)
	{
		Node* subR = parent->_right;
		Node* subRL = subR->_left;
		Node* pparent = parent->_parent;

		parent->_right = subRL;
		if (subRL)
			subRL->_parent = parent;

		subR->_left = parent;
		parent->_parent = subR;

		if (parent == _root)
		{
			_root = subR;
			subR->_parent = nullptr;
		}
		else
		{
			if (pparent->_left == parent)
			{
				pparent->_left = subR;
				subR->_parent = pparent;
			}
			else
			{
				pparent->_right = subR;
				subR->_parent = pparent;
			}
		}
	}

	//右单旋
	void RotateR(Node* parent)
	{
		Node* subL = parent->_left;
		Node* subLR = subL->_right;
		Node* pparent = parent->_parent;

		parent->_left = subLR;
		if (subLR)//置parent->_left的时候可以不管subLR是否为空，但是若是subLR为空取其parent就会出错
		{
			subLR->_parent = parent;
		}

		subL->_right = parent;
		parent->_parent = subL;

		if (pparent == _root)
		{
			_root = subL;
			subL->_parent = nullptr;
		}
		else
		{
			if (pparent->_left == parent)
			{
				pparent->_left = subL;
				subL->_parent = pparent;
			}
			else
			{
				pparent->_right = subL;
				subL->_parent = pparent;
			}

		}
	}


	void Inorder()
	{
		_Inorder(_root);
	}

	void _Inorder(Node* root)
	{
		if (root == nullptr)
			return;
		_Inorder(root->_left);
		cout << root->_kv.first << ":" << root->_kv.second << endl;
		_Inorder(root->_right);
	}

	bool IsValidRBTree()
	{
		Node* pRoot = _root;

		// 空树也是红黑树
		if (nullptr == pRoot)
			return true;

		// 检测根节点是否满足情况
		if (BLACK != pRoot->_col)
		{
			cout << "违反红黑树性质二：根节点必须为黑色" << endl;
			return false;
		}

		// 获取任意一条路径中黑色节点的个数
		size_t blackCount = 0;
		Node* pCur = pRoot;
		while (pCur)
		{
			if (BLACK == pCur->_col)
				blackCount++;
			pCur = pCur->_left;
		}

		// 检测是否满足红黑树的性质，k用来记录路径中黑色节点的个数
		size_t k = 0;
		return _IsValidRBTree(pRoot, k, blackCount);
	}

	bool _IsValidRBTree(Node* root, size_t k, const size_t blackCount)
	{
		if (nullptr == root)
			return true;

		// 统计黑色节点的个数
		if (BLACK == root->_col)
			k++;

		// 检测当前节点与其双亲是否都为红色
		Node* parent = root->_parent;
		if (parent && RED == parent->_col && RED == root->_col)
		{
			cout << "违反性质三：没有连在一起的红色节点" << endl;
			return false;
		}

		// 如果root是因子节点，检测当前路径中黑色节点的个数是否有问题
		if (nullptr == root->_left&& nullptr == root->_right)
		{
			if (k != blackCount)
			{
				cout << "违反性质四：每条路径中黑色节点的个数必须相同" << endl;
				return false;
			}
		}

		//递归判断左右子树都满足红黑树的性质
		return _IsValidRBTree(root->_left, k, blackCount) &&
			_IsValidRBTree(root->_right, k, blackCount);
	}

private:
	Node* _root;
};


void TestRBTree()
{
	int a[] = { 5, 3, 15, 10, 8, 7, 17, 16 };
	RBTree<int, int> rt;

	for (auto& e : a)
	{
		rt.Insert(make_pair(e, e));
	}

	cout << rt.IsValidRBTree() << endl;

	rt.Inorder();
}