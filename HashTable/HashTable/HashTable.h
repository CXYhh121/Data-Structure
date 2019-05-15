#pragma once
#include <iostream>
#include <vector>
using namespace std;

enum State
{
	EMPTY,
	DELETE,
	EXIST
};

template<class K,class V>
struct HashNode
{
	pair<K, V> _kv;
	State _state;
};


template<class K, class V>
class HashTable
{
	typedef HashNode<K, V> HashNode;
public:

	HashTable(size_t N = 10)
	{
		_table.resize(N);
		for (size_t i = 0; i < _table.size(); ++i)
		{
			_table[i]._state = EMPTY;
		}
		_size = 0;
	}

	void CheckCapacity()
	{
		//load factor 等于0.7开始增容，负载因子越小效率越高，空间浪费越多
		if (_tabele.size() == 0 || (_size * 10) / _table.size() == 7)
		{//增容
			size_t newcapacity = _table.size() == 0 ? 10 : _table.size() * 2;
			HashTable<K, V> _newht(newcapacity);
			//旧表的数据重新计算在新表中的位置
			for (size_t i = 0; i < _table.size(); ++i)
			{
				if (_table[i]._state == EXIST)
					_newht.Insert(_table[i]._kv);
			}
			//交换之后，旧表更新为newht，newht为本函数中的局部对象，
			//出了该函数了作用域之后会自动调用析构函数释放旧表资源
			_table.swap(_newht._table);	
		}
	}

	bool Insert(const pair<K, V>& kv)
	{
		size_t index = kv.first % _table.size();
		while (_table[index]._state == EXIST)
		{
			if (_table[index]._kv.first == kv.first)
			{
				return true;
			}

			//线性探测解决哈希冲突问题
			++index;
			if (index == _table.size())
				index = 0;
		}

		//若是该位置没值，直接插入
		_table[index]._kv = kv;
		_table[index]._state = EXIST;
		_size++;

		return true;
	}

	HashNode* Find(const K& key)
	{
		size_t index = key%_table.size();
		while (_table[index]._state != EMPTY)
		{
			if (_table[index]._kv.first == key && _table[index] == EXIST)
			{
				return &_table[index];
			}

			++index;
			if (index == _table.size())
				index = 0;
		}
		return nullptr;
	}

	bool Erase(const K& key)
	{
		HashNode* node = Find(ket);
		if (node != nullptr)
		{
			node->_state = DELETE;
			--_size;
			return true;
		}
		else
		{
			return false;
		}
	}
private:
	//HashNode* _table;
	//size_t _size;//有效数据个数
	//size_t _capacity;//哈希表的空间大小

	vector<HashNode> _table;
	size_t _size;//哈希表中有效数据的个数
};

void TestHashTable()
{
	HashTable<int, int> ht;
	int a[] = { 3, 2, 5, 1 };
	for (auto& e : a)
	{
		ht.Insert(make_pair(e, e));
	}

}