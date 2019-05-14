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
		//����Ϊ�գ�ֱ�Ӳ���
		if (_root == nullptr)
		{
			_root = new Node(kv);
			_root->_col = BLACK;
			return true;
		}

		//��Ϊ�գ����ҵ�����λ���ٲ���ڵ�
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
				return false;//��������Ѿ��и�Ԫ�أ������ʧ��
		}

		//�ҵ�����λ�ã�����ڵ�
		//����Ľڵ���ɫΪ��ɫ���ƻ������������3,���ô���
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

		//����ڵ�ɹ��󣬼��������������û�б��ƻ�
		//��������Ҫ���нڵ����ɫ������������������
		//���Ǹ��ڵ�����Ҹ��ڵ����ɫΪ��ɫ����Ҫ����������������������
		while (parent && parent->_col == RED)
		{
			// ע�⣺grandFatherһ������
			// ��Ϊparent���ڣ��Ҳ��Ǻ�ɫ�ڵ㣬��parentһ�����Ǹ�������һ����˫��
			Node* grandfather = parent->_parent;
			
			//1�����ڵ����游�ڵ������
			if (grandfather->_left == parent)
			{
				Node* uncle = grandfather->_right;
				//1������ڵ����������ڵ����ɫΪ��ɫ
				if (uncle && uncle->_col == RED)
				{
					parent->_col = uncle->_col = BLACK;
					grandfather->_col = RED;

					cur = grandfather;
					parent = cur->_parent;
				}

				//2������ڵ㲻���ڻ�������ڵ����ɫΪ��ɫ
				else
				{
					//1�����cur��parent���Һ��ӣ���ʱ��Ҫ�������������ת��Ϊ���2
					if (parent->_right == cur)
					{
						RotateL(parent);
						swap(cur, parent);
					}

					//1�����cur��parent��z���ӣ���ʱֻ�����һ���ҵ���������parent����ɫ��Ϊ�ڣ�grandparent����ɫ�ú�
					RotateR(grandfather);
					grandfather->_col = RED;
					parent->_col = BLACK;
					break;
				}

			}

			//2�����ڵ����游�ڵ���Һ���
			else
			{
				Node* uncle = grandfather->_left;
				//1������ڵ����������ڵ����ɫΪ��ɫ
				if (uncle && uncle->_col == RED)
				{
					parent->_col = uncle->_col = BLACK;
					grandfather->_col = RED;

					cur = grandfather;
					parent = cur->_parent;
				}

				//2������ڵ㲻���ڻ�������ڵ����ɫΪ��ɫ
				else
				{
					//1������curΪparent�����ӣ��Ƚ���һ���ҵ���ת��Ϊ�����һ����
					if (parent->_left == cur)
					{
						RotateR(parent);
						swap(cur, parent);
					}

					//2������curΪparent���Һ��ӣ�����һ������������parent����ɫ��Ϊ�ڣ�grandparent����ɫ�ú�
					RotateL(grandfather);
					grandfather->_col = RED;
					parent->_col = BLACK;
					break;
				}
			}
		}

		//��ת���֮�󣬽����ڵ����ɫ�óɺ�ɫ
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

		// ����Ҳ�Ǻ����
		if (nullptr == pRoot)
			return true;

		// �����ڵ��Ƿ��������
		if (BLACK != pRoot->_col)
		{
			cout << "Υ����������ʶ������ڵ����Ϊ��ɫ" << endl;
			return false;
		}

		// ��ȡ����һ��·���к�ɫ�ڵ�ĸ���
		size_t blackCount = 0;
		Node* pCur = pRoot;
		while (pCur)
		{
			if (BLACK == pCur->_col)
				blackCount++;
			pCur = pCur->_left;
		}

		// ����Ƿ��������������ʣ�k������¼·���к�ɫ�ڵ�ĸ���
		size_t k = 0;
		return _IsValidRBTree(pRoot, k, blackCount);
	}

	bool _IsValidRBTree(Node* root, size_t k, const size_t blackCount)
	{
		if (nullptr == root)
			return true;

		// ͳ�ƺ�ɫ�ڵ�ĸ���
		if (BLACK == root->_col)
			k++;

		// ��⵱ǰ�ڵ�����˫���Ƿ�Ϊ��ɫ
		Node* parent = root->_parent;
		if (parent && RED == parent->_col && RED == root->_col)
		{
			cout << "Υ����������û������һ��ĺ�ɫ�ڵ�" << endl;
			return false;
		}

		// ���root�����ӽڵ㣬��⵱ǰ·���к�ɫ�ڵ�ĸ����Ƿ�������
		if (nullptr == root->_left&& nullptr == root->_right)
		{
			if (k != blackCount)
			{
				cout << "Υ�������ģ�ÿ��·���к�ɫ�ڵ�ĸ���������ͬ" << endl;
				return false;
			}
		}

		//�ݹ��ж�������������������������
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