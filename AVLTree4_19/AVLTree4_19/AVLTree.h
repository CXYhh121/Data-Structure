#pragma once

#include <iostream>
#include <assert.h>
using namespace std;

template<class K,class V>
struct AVLTreeNode
{
	//AVLTreeNode(const pair<K, V>& kv)
	//:_left(nullptr)
	//, _right(nullptr)
	//, _kv(kv)
	//, _bf(0)
	//{}

	AVLTreeNode* _left;
	AVLTreeNode* _right;
	AVLTreeNode* _parent;
	pair<K, V> _kv;

	int _bf;//平衡因子
};

template<class K, class V>
class AVLTree
{
	typedef AVLTreeNode<K, V> Node;
public:
	AVLTree()
		:_root(nullptr)
	{}

	bool Insert(const pair<K, V>& kv)
	{
		//二叉树搜索树一样插入，插入之后更新平衡因子
		if (_root == nullptr)
		{
			_root = new Node(kv);
			return true;
		}

		Node* cur = _root;
		Node* parent = nullptr;

		while (cur)
		{
			if (kv.first > cur->_kv.first)
			{
				parent = cur;
				cur = cur->_right;
			}
				
			else if (kv.first < cur->_kv.first)
			{
				parent = cur;
				cur = cur->_left;
			}
			else
				return false;//若树中已经有该值，则插入失败
		}
		//找到位置插入该节点
		cur = new Node(kv);
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

		//插入节点成功，更新平衡因子
		while (parent)
		{
			//cur插入parent的左边，parent的bf -1
			//cur插入parent的右边，parent的bf +1
			if (parent->_left == cur)
				parent->_bf--;
			else
				parent->_bf++;
			//1.parent的bf == 0,说明插入之前parent的bf为正负1，AVL树的高度不变，不会影响上层节点的bf，不用调整
			if (parent->_bf == 0)
				break;
			//2.parent的|bf| == 1，说明插入之前parent的bf为0，AVL树的高度改变，更新parent到root节点的bf
			else if (parent->_bf == 1 || parent->_bf == -1)
			{
				cur = parent;
				parent = parent->_parent;
			}
			//3.parent的|bf| == 2,已经破坏该树的平衡，违反AVL树的性质，需要对树进行旋转
			else if (parent->_bf == 2 || parent->_bf == -2)
			{
				//旋转
			}
			else
			{
				assert(false);
			}
		}	
		return true;
	}

	//左单旋
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
		parent->_bf = subR->_bf = 0;
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
		subL->_bf = parent->_bf = 0;
	}

	//左右双旋
	void RotateLR(Node* parent)
	{
		Node* subL = parent->_left;
		Node* subLR = subL->_right;

		int bf = subLR->_bf;
		RotateL(subL);//先左单旋
		RotateR(parent);//再右单旋

		if (bf == 0)
		{
			parent->_bf = subL->_bf = subLR->_bf = 0;
		}
		else if (bf == 1)
		{
			parent->_bf = 0;
			subL->_bf = -1;
			subLR->_bf = 0;
		}
		else if (bf == -1)
		{
			parent->_bf = 1;
			subL->_bf = 0;
			subLR->_bf = 0;
		}
		else
			assert(false);
	}

	//右左双旋
	void RotateRL(Node* parent)
	{
		Node* subR = parent->_right;
		Node* subRL = subR->_left;

		int bf = subRL->_bf;
		RotateR(subR);
		RotateL(parent);

		if (bf == 0)
			parent->_bf = subR->_bf =subRL->_bf = 0;
		else if (bf == 1)
		{
			parent->_bf = -1;
			subR->_bf = 0;
			subRL->_bf = 0;
		}
		else if (bf == -1)
		{
			parent->_bf = 0;
			subR->_bf = 1;
			subRL->_bf = 0;
		}
		else
			assert(false);
	}
private:
	Node* _root;
};

void TestAVLTree()
{
	AVLTree<int, int> at;
}