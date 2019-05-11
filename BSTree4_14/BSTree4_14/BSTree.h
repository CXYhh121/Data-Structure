#pragma once
#include <iostream>
using namespace std;

namespace CXY
{
	//二叉搜索树，支持增加(Insert)删(Erase)查(Find)
	template <class K>
	struct BSTNode
	{
		BSTNode(const K& value = K())
		:_left(nullptr)
		, _right(nullptr)
		, _val(value)
		{}

		BSTNode<K>* _left;
		BSTNode<K>* _right;
		K _val;
	};

	template <class K>
	class BSTree
	{
		typedef BSTNode<K> Node;
	public:
		BSTree()//构造函数
			:_root(nullptr)
		{}

		void Destroy(Node* root)
		{
			if (root == nullptr)
				return;
			Destroy(root->_left);
			Destroy(root->_right);
			delete root;
		}
		~BSTree()//析构函数
		{
			Destroy(_root);//无法直接递归，因此创建一个Destroy函数
		}

		bool Insert(const K& value)//插入一个元素
		{
			if (_root == nullptr)//若树为空时，可直接插入
			{
				_root = new Node(value);
				return true;
			}

			//查找元素在二叉搜索树中应该插入的位置
			Node* cur = _root;
			Node* parent = nullptr;//记录cur的双亲节点，方便插入新节点

			while (cur)
			{
				parent = cur;
				if (value > cur->_val)
					cur = cur->_right;
				else if (value < cur->_val)
					cur = cur->_left;
				else//元素在树中已经存在，返回false
					return false;
			}
			//找到对应位置，插入元素
			cur = new Node(value);
			if (value > parent->_val)
				parent->_right = cur;
			else
				parent->_left = cur;

			return true;
		}

		Node* Find(const K& value)
		{
			Node* cur = _root;
			while (cur)
			{
				if (value > cur->_val)
					cur = cur->_right;
				else if (value < cur->_val)
					cur = cur->_left;
				else
					return cur;
			}
			return nullptr;
		}

		bool Erase(const K& value)
		{
			if (_root == nullptr)
				return false;
			//查找元素在二叉搜索树中应该删除的位置
			Node* cur = _root;
			Node* parent = nullptr;//记录cur的双亲节点，方便插入新节点

			while (cur)
			{
				if (value > cur->_val)
				{
					parent = cur;
					cur = cur->_right;
				}
					
				else if (value < cur->_val)
				{
					parent = cur;
					cur = cur->_left;
				}	
				else//已经找到，跳出循环
					break;
			}

			Node* del = cur;
			if (cur == nullptr)
				return false;
			//1、节点左为空，父亲指向节点的右，删除节点
			if (cur->_left == nullptr)
			{
				if (parent == nullptr)
					_root = cur->_right;
				else
				{
					if (parent->_left == cur)//如果cur是父亲节点的左孩子
						parent->_left = cur->_right;
					else
						parent->_right = cur->_right;
				}
			}
			//2、节点右为空，父亲指向节点的左，删除节点
			else if (cur->_right == nullptr)
			{
				if (parent == nullptr)
					_root = cur->_left;
				else
				{
					if (parent->_left == cur)//如果cur是父亲节点的左孩子
						parent->_left = cur->_left;
					else
						parent->_right = cur->_left;
				}
			}
			//3、节点左右均不为空，找左树的最右节点或是右树的最左节点作为替代节点与该节点交换之后再删除
			else
			{
				Node* P_replace = cur;//保存替代节点的双亲节点
				Node* replace = cur->_left;//找左树的最右节点
				
				while (replace->_right)
				{
					P_replace = replace;
					replace = replace->_right;
				}

				cur->_val = replace->_val;//交换要删除节点的值与替代节点的值

				//判断替代节点是其双亲节点的左孩子还是右孩子
				//左树的最右节点的右孩子必定为空
				if (P_replace->_left == replace)
					P_replace->_left = replace->_left;
				else
					P_replace->_right = replace->_left;

				del = replace;
			}
			delete del;
			return true;
		}

		void _Inorder(Node* root)
		{
			if (root == nullptr)
				return;
			_Inorder(root->_left);
			cout << root->_val << " ";
			_Inorder(root->_right);
		}
		//本来调用中序遍历时需要穿参数，但是由于_root为类的私有成员，在类外不可见
		//因此在类外调用不需要参数的接口，并在此接口中调用需要参数的函数，类内可以调用私有成员
		void Inorder()
		{
			_Inorder(_root);
		}
	private:
		Node* _root;
	};

	void TestBSTree()
	{
		BSTree<int> st;
		st.Insert(3);
		st.Insert(5);
		st.Insert(2);
		st.Insert(1);
		st.Insert(6);
		st.Insert(4);

		st.Inorder();
		//cout << st.Find(5)->_val << endl;
		st.Erase(5);
		st.Inorder();
	}

}
