#pragma once

//��ɢ�н����ϣ��ͻ����ϣͰ��������
#include <iostream>
#include <vector>
using namespace std;

template<class V>
struct HashNode
{
	//����֮��Ҫ�ù�ϣͰ��װunordered_map/set�����������ܴ�pair<K,V>Ҳ���ܴ�value
	V _valuefiled;
	HashNode<V>* _next;//��ϣͰ�ṹ��һ��vector�����¹�����������һ��ָ��ָ����һ���ڵ��λ��

	HashNode(const V& v)
		:_valuefiled(v)
		, _next(nullptr)
	{}
};

//����֮��Ҫ�ù�ϣͰ��װunordered_map/set�����������ܴ�pair<K,V>Ҳ���ܴ�value
//����pair<K,V>�洢�Ƚϱ���ȡkey���ܱȽϣ���˴��º���ȡkey
template<class K,class V,class KeyOfValue>
class HashTable
{
	typedef HashNode<V> Node;
	typedef HashTable<K, V, KeyOfValue> HashTable;
public:
	HashTable()
		:_size(0)
	{}

	bool insert(const V& v)
	{
		//��������
		CheckCapacity();

		KeyOfValue kov;
		const K& key = kov(v);
		size_t index = key % _table.size();

		Node* cur = _table[index];
		while (cur)
		{
			if (kov(cur->_valuefiled) == key)
				return false;
			cur = cur->_next;
		}
		//�ߵ���˵��û����ͬ��Ԫ�أ����Խ��в��룬
		//���ڹ�ϣͰ���涨������ͻ����������,���Խ���ͷ��Ƚϼ�
		Node* newnode = new Node(v);
		newnode->_next = _table[index];
		_table[index] = newnode;

		++_size;
		return true;
	}

	void CheckCapacity()
	{
		//����������==1ʱ����
		if (_table.size() == _size)
		{
			size_t newsize = _table.size() == 0 ? 10 : _table.size() * 2;
			//���ﲻ��֮ǰ��ɢ��һ������һ���µĹ�ϣ��
			//�ٵ���Insert��ԭ���Ǿɱ�Ľڵ����ֱ���õ��µ�vector�����н��в���
			vector<Node*> newtable;
			newtable.resize(newsize);

			//�����ɱ����µ�vector�������ҵ���Ӧλ�ã����ɱ�ڵ����
			for (size_t i = 0; i < _table.size(); ++i)
			{
				Node* cur = _table[index];
				//���ڵ�Ӿɱ��в�����������¼���ڵ����±��е�λ�ý��в���
				while (cur)
				{
					Node* next = cur->_next;
					size_t index = KeyOfValue()(cur->_valuefiled) % newsize;

					//ͷ�����±���
					cur->_next = newtable[index];
					newtable[index] = cur;

					cur = next;
				}
				//��ԭ���ı��ÿ�
				_table[i] = nullptr;
			}
			//�����¾��������Դ������������±��Զ��������������ͷžɱ���Դ
			_table.swap(newtable);
		}
	}

	Node* Find(const K& key)
	{
		size_t index = key % _table.size();
		Node* cur = _table[index];
		while (cur)
		{
			if (KeyOfValue()(cur->_valuefiled) == key)
				return cur;

			cur = cur->_next;
		}
		return nullptr;
	}

	bool Erase(const K& key)
	{
		size_t index = key % _table.size();
		Node* cur = _table[index];
		Node* prev = nullptr;

		while (cur)
		{
			if (KeyOfValue()(cur->_valuefiled) == key)
			{
				if (prev == nullptr)//ͷɾ
					_table[index] = cur->_next;
				else
					prev->_next = cur->_next;

				delete cur;
				--_size;
				return true;
			}
		}
		return false;
	}
private:
	vector<Node*> _table;//vector�е�sizeΪ��ϣ��Ĵ�С
	size_t _size;//��ϣ���д洢����ЧԪ�صĸ���
};
