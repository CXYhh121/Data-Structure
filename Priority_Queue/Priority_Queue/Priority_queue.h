#pragma once

#include <iostream>
#include <vector>
#include <deque>
using namespace std;

template<class T, class Container = vector<T>, class Compare = less<T>>
class PriorityQueue
{
public:
	void Adjustdown(size_t parent)
	{
		size_t child = parent * 2 + 1;

		while (child < _con.Size())
		{
			if (_con[child] < _con[child + 1])
				++child;
			if (_con[parent] < _con[child])
			{
				swap(_con[parent], _con[child]);
				parent = child;
				child = parent * 2 + 1;
			}
			else
			{
				break;
			}
		}
	}
	void AdjustUp(size_t child)
	{
		size_t parent = (child - 1) / 2;

		while (child)
		{
			if (_con[parent] < _con[child])
			{
				swap(_con[parent], _con[child]);
				child = parent;
				parent = (child - 1) / 2;
			}
			else
			{
				break;
			}
		}
	}

	void Push(const T& x)//weicha
	{
		_con.push_back(x);
		AdjustUp(_con.size() - 1);
	}
	
	void Pop()//toushan
	{
		swap(_con[0], _con[_con.Size() - 1]);
		_con.pop_back();
		Adjustdown(0);
	}

	const T& Top()
	{
		return _con[0];
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


class Goods
{
public:
	bool operator<(const Goods r) const
	{
		return _price < r._price;
	}
public:
	int _price;
	int _sales_volume;
	int _evaluation;
	int _comprehensive;
};
struct GoodsPriceLess
{
	bool operator()(const Goods& l, const Goods& r)
	{
		return l._price < r._price;
	}
};

struct GoodsPriceGreater
{
	bool operator()(const Goods& l, const Goods& r)
	{
		return l._price > r._price;
	}
};

void TestPriorityQueue()
{
	PriorityQueue<Goods, vector<Goods>, GoodsPriceLess> goodspq;
	goodspq.Push(Goods{ 1, 2, 3, 4 });
	goodspq.Push(Goods{ 4, 3, 2, 1 });

	Goods top = goodspq.Top();
	cout << top._price << endl;
	cout << top._sales_volume << endl;
	cout << top._evaluation << endl;
	cout << top._comprehensive << endl;
}