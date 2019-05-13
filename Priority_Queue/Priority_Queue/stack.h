#pragma once

#include <iostream>
#include <vector>
using namespace std;

namespace CXYS
{
	template<class T, class Container = vector<int>>
	class Stack
	{
	private:
		Container _con;
	public:
		void Push(const T& x)
		{
			_con.push_back(x);
		}
		void Pop()
		{
			_con.pop_back();
		}

		const T& Top()
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
	};

	void TestStack()
	{
		Stack<int> st;
		st.Push(2);
		st.Push(3);
		st.Push(0);
		st.Push(6);
		st.Push(9);

		while (st.Empty() != 1)
		{
			cout << st.Top() << " ";
			st.Pop();
		}

		cout << endl;

	}
}