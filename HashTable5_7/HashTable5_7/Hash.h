#pragma once
#include <iostream>
using namespace std;

template<class K, class V>
class HashTable
{
	struct Elem {
		pair<K, V> _val;
		State _state;
	};
public:
	HashTable(size_t capacity = 3)
		: _ht(capacity)
		, _size(0) {
		for (size_t i = 0; i < capacity; ++i)
			_ht[i]._state = EMPTY;
	}
	bool Insert(const pair<K, V>& val)
	{
		// ����ϣ��ײ�ռ��Ƿ���� // _CheckCapacity();
		size_t hashAddr = HashFunc(key);
		// size_t startAddr = hashAddr;
		while (_ht[hashAddr]._state != EMPTY)
		{
			if (_ht[hashAddr]._state == EXIST && _ht[hashAddr]._val.first == key)
				return false;
			hashAddr++;
			// hashAddr %= _ht.capacity();
			if (hashAddr == _ht.capacity())
				hashAddr = 0;
			/*
			// תһȦҲû���ҵ���ע��:��̬��ϣ������������Բ��ÿ��ǣ���ϣ����Ԫ�ظ������� һ������������ϣ��ͻ���ʻ�������Ҫ���������͹�ϣ��ͻ����˹�ϣ����Ԫ���ǲ��������
			if(hashAddr == startAddr)
			return false;
			*/
		}
		// ����Ԫ�� _ht[hashAddr]._state = EXIST; _ht[hashAddr]._val = val; _size++;
		return true;
	}

	int Find(const K& key)
	{
		size_t hashAddr = HashFunc(key);
		while (_ht[hashAddr]._state != EMPTY)
		{
			if (_ht[hashAddr]._state == EXIST && _ht[hashAddr]._val.first == key)
				return hashAddr;
			hashAddr++;
		}
		return hashAddr;
	}
	bool Erase(const K& key)
	{
		int index = Find(key);
		if (-1 != index)
		{
			_ht[index]._state = DELETE;
			_size++;
			return true;
		}
		return false;
	}

	size_t Size()const
	{
		return _size;
	}

	bool Empty() const
	{
		return 0 == _size;
	}

	void Swap(HashTable<K, V, HF>& ht)
	{
		swap(_ht, ht._ht);
		swap(_size, ht._size);
	}
private:
	size_t HashFunc(const K& key)
	{
		return key % _ht.capacity();
	}
private:
	vector<Elem> _ht;
	size_t _size;
};

void TestHash()
{
	HashTable<int, int> ht;
	int a[] = { 3, 6, 1, 8, 5, 9 };
	for (auto& e : a)
	{
		ht.Insert(make_pair(e, e));
	}

	cout << ht.Empty() << endl;
}