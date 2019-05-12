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

	int _bf;//ƽ������
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
		//������������һ�����룬����֮�����ƽ������
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
				return false;//�������Ѿ��и�ֵ�������ʧ��
		}
		//�ҵ�λ�ò���ýڵ�
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

		//����ڵ�ɹ�������ƽ������
		while (parent)
		{
			//cur����parent����ߣ�parent��bf -1
			//cur����parent���ұߣ�parent��bf +1
			if (parent->_left == cur)
				parent->_bf--;
			else
				parent->_bf++;
			//1.parent��bf == 0,˵������֮ǰparent��bfΪ����1��AVL���ĸ߶Ȳ��䣬����Ӱ���ϲ�ڵ��bf�����õ���
			if (parent->_bf == 0)
				break;
			//2.parent��|bf| == 1��˵������֮ǰparent��bfΪ0��AVL���ĸ߶ȸı䣬����parent��root�ڵ��bf
			else if (parent->_bf == 1 || parent->_bf == -1)
			{
				cur = parent;
				parent = parent->_parent;
			}
			//3.parent��|bf| == 2,�Ѿ��ƻ�������ƽ�⣬Υ��AVL�������ʣ���Ҫ����������ת
			else if (parent->_bf == 2 || parent->_bf == -2)
			{
				//��ת
			}
			else
			{
				assert(false);
			}
		}	
		return true;
	}

	//����
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
	//�ҵ���
	void RotateR(Node* parent)
	{
		Node* subL = parent->_left;
		Node* subLR = subL->_right;
		Node* pparent = parent->_parent;

		parent->_left = subLR;
		if (subLR)//��parent->_left��ʱ����Բ���subLR�Ƿ�Ϊ�գ���������subLRΪ��ȡ��parent�ͻ����
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

	//����˫��
	void RotateLR(Node* parent)
	{
		Node* subL = parent->_left;
		Node* subLR = subL->_right;

		int bf = subLR->_bf;
		RotateL(subL);//������
		RotateR(parent);//���ҵ���

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

	//����˫��
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