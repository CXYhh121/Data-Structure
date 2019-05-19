#include "BitMap.h"
#pragma once

#include <iostream>
using namespace std;


//���貼¡��������Ԫ������ΪK��ÿ��Ԫ�ض�Ӧ3����ϣ����,��һ��ֵ��ӳ������λ��
template<class K
		class HashFunc1
		class HashFunc2
		class HashFunc3>
class BloomFilter
{
public:
	BloomFilter(size_t size) // ��¡��������Ԫ�ظ���
		: _bmp(10 * size)
		, _size(0)
	{}

	bool Insert(const K& key)
	{
		size_t bitCount = _bmp.Size();

		size_t index1 = HashFunc1(key) % bitCount;
		size_t index2 = HashFunc2(key) % bitCount;
		size_t index3 = HashFunc3(key) % bitCount;

		_bmp.SetBit(index1);
		_bmp.SetBit(index2);
		_bmp.SetBit(index3);

		++_size;
	}

	bool IsBloomFilter(const K& key)
	{
		size_t bitCount = _bmp.Size();

		size_t index1 = HashFunc1(key) % bitCount;
		if (!_bmp.TestBit(index1))
			return false;

		size_t index2 = HashFunc2(key) % bitCount;
		if (!_bmp.TestBit(index2))
			return false;

		size_t index3 = HashFunc3(key) % bitCount;
		if (!_bmp.TestBit(index3))
			return false;

		return true;//���ܴ���
	}

private:
	BitMap _bmp;
	size_t _size;
};