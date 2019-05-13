#pragma once

#include <iostream>
#include <list>
using namespace std;

namespace CXYQ
{
	template<class T,class Container = list<int>>
	class Queue
	{
	public:
		void Push(const T& x)
		{
			_con.push_back(x);
		}

		void Pop()
		{
			_con.pop_front();
		}

		const T& Front()
		{
			return _con.front();
		}

		const T& Back()
		{
			return _con.back();
		}

		size_t Size() const
		{
			return _con.size();
		}

		bool Empty() const
		{
			return _con.empty();
		}
	private:
		Container _con;
		
	};

	void TestQueue()
	{
		Queue<int> q;
		q.Push(2);
		q.Push(3);
		q.Push(1);
		q.Push(6);
		q.Push(3);
		q.Push(8);

		while (!q.Empty())
		{
			cout << q.Front() << " ";
			q.Pop();
		}
		cout << endl;
	}
}