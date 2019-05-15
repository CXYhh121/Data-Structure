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
		//load factor ����0.7��ʼ���ݣ���������ԽСЧ��Խ�ߣ��ռ��˷�Խ��
		if (_tabele.size() == 0 || (_size * 10) / _table.size() == 7)
		{//����
			size_t newcapacity = _table.size() == 0 ? 10 : _table.size() * 2;
			HashTable<K, V> _newht(newcapacity);
			//�ɱ���������¼������±��е�λ��
			for (size_t i = 0; i < _table.size(); ++i)
			{
				if (_table[i]._state == EXIST)
					_newht.Insert(_table[i]._kv);
			}
			//����֮�󣬾ɱ����Ϊnewht��newhtΪ�������еľֲ�����
			//���˸ú�����������֮����Զ��������������ͷžɱ���Դ
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

			//����̽������ϣ��ͻ����
			++index;
			if (index == _table.size())
				index = 0;
		}

		//���Ǹ�λ��ûֵ��ֱ�Ӳ���
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
	//size_t _size;//��Ч���ݸ���
	//size_t _capacity;//��ϣ��Ŀռ��С

	vector<HashNode> _table;
	size_t _size;//��ϣ������Ч���ݵĸ���
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