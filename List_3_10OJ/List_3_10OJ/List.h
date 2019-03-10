#include <iostream>
using namespace std;

namespace CXY
{
	class MyLinkedList {
	public:
		/** Initialize your data structure here. */
		MyLinkedList() {
			_head = new Node;
			_head->_next = _head;
			_head->_prev = _head;

			size = 0;
		}

		int get(int index) {
			if (index < 0 || index > size)
				return -1;
			Node* cur = _head;
			for (int i = 0; i < index; ++i)
				cur = cur->_next;

			return cur->_val;
		}

		void addAtHead(int val) {
			Node* newnode = new Node(val);
			Node* next = _head->_next;

			newnode->_prev = _head;
			newnode->_next = next;

			next->_prev = newnode;
			_head->_next = newnode;
			++size;
		}

		/** Append a node of value val to the last element of the linked list. */
		void addAtTail(int val) {
			Node* newnode = new Node(val);
			Node* tail = _head->_prev;

			newnode->_prev = tail;
			newnode->_next = _head;

			_head->_prev = newnode;
			tail->_next = newnode;
			++size;
		}

		void addAtIndex(int index, int val) {
			if (index < 0 || index > size)
				return;
			if (index == size)
				addAtTail(val);

			Node* cur = _head;
			for (int i = 0; i < size; ++i)
			{
				cur = cur->_next;
			}
			Node* newnode = new Node(val);
			Node* prev = cur->_prev;

			newnode->_prev = prev;
			newnode->_next = cur;

			cur->_prev = newnode;
			prev->_next = newnode;
			++size;
		}

		void deleteAtIndex(int index) {
			if (index > 0 && index < size)
			{
				Node* cur = _head;
				for (int i = 0; i < size; ++i)
				{
					cur = cur->_next;
				}

				Node* prev = cur->_prev;

				prev->_next = cur->_next;
				cur->_next->_prev = prev;

				delete cur;
				--size;
			}

		}
		int Getsize()
		{
			return size;
		}
private:
		struct Node
		{
			int _val;
			Node* _prev;
			Node* _next;

			Node(int val = 0)
				:_val(val)
				, _prev(nullptr)
				, _next(nullptr)
			{}
		};
		Node* _head;
		int size;

	};

	void TestList()
	{
		MyLinkedList list;
		list.addAtHead(1);
		list.addAtHead(2);
		list.addAtHead(3);
		list.addAtHead(4);

		/*for (int i = 0; i < list.Getsize(); ++i)
		{
			cout<<
		}*/

	}
}