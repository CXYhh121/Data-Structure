#pragma once
#include <iostream>
using namespace std;

namespace CXY
{
	//������������֧������(Insert)ɾ(Erase)��(Find)
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
		BSTree()//���캯��
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
		~BSTree()//��������
		{
			Destroy(_root);//�޷�ֱ�ӵݹ飬��˴���һ��Destroy����
		}

		bool Insert(const K& value)//����һ��Ԫ��
		{
			if (_root == nullptr)//����Ϊ��ʱ����ֱ�Ӳ���
			{
				_root = new Node(value);
				return true;
			}

			//����Ԫ���ڶ�����������Ӧ�ò����λ��
			Node* cur = _root;
			Node* parent = nullptr;//��¼cur��˫�׽ڵ㣬��������½ڵ�

			while (cur)
			{
				parent = cur;
				if (value > cur->_val)
					cur = cur->_right;
				else if (value < cur->_val)
					cur = cur->_left;
				else//Ԫ���������Ѿ����ڣ�����false
					return false;
			}
			//�ҵ���Ӧλ�ã�����Ԫ��
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
			//����Ԫ���ڶ�����������Ӧ��ɾ����λ��
			Node* cur = _root;
			Node* parent = nullptr;//��¼cur��˫�׽ڵ㣬��������½ڵ�

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
				else//�Ѿ��ҵ�������ѭ��
					break;
			}

			Node* del = cur;
			if (cur == nullptr)
				return false;
			//1���ڵ���Ϊ�գ�����ָ��ڵ���ң�ɾ���ڵ�
			if (cur->_left == nullptr)
			{
				if (parent == nullptr)
					_root = cur->_right;
				else
				{
					if (parent->_left == cur)//���cur�Ǹ��׽ڵ������
						parent->_left = cur->_right;
					else
						parent->_right = cur->_right;
				}
			}
			//2���ڵ���Ϊ�գ�����ָ��ڵ����ɾ���ڵ�
			else if (cur->_right == nullptr)
			{
				if (parent == nullptr)
					_root = cur->_left;
				else
				{
					if (parent->_left == cur)//���cur�Ǹ��׽ڵ������
						parent->_left = cur->_left;
					else
						parent->_right = cur->_left;
				}
			}
			//3���ڵ����Ҿ���Ϊ�գ������������ҽڵ��������������ڵ���Ϊ����ڵ���ýڵ㽻��֮����ɾ��
			else
			{
				Node* P_replace = cur;//��������ڵ��˫�׽ڵ�
				Node* replace = cur->_left;//�����������ҽڵ�
				
				while (replace->_right)
				{
					P_replace = replace;
					replace = replace->_right;
				}

				cur->_val = replace->_val;//����Ҫɾ���ڵ��ֵ������ڵ��ֵ

				//�ж�����ڵ�����˫�׽ڵ�����ӻ����Һ���
				//���������ҽڵ���Һ��ӱض�Ϊ��
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
		//���������������ʱ��Ҫ����������������_rootΪ���˽�г�Ա�������ⲻ�ɼ�
		//�����������ò���Ҫ�����Ľӿڣ����ڴ˽ӿ��е�����Ҫ�����ĺ��������ڿ��Ե���˽�г�Ա
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
