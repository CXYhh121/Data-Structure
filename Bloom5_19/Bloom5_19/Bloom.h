#include "BitMap.h"
#pragma once

#include <iostream>
using namespace std;


//假设布隆过滤器中元素类型为K，每个元素对应3个哈希函数,即一个值会映射三个位置
template<class K
		class HashFunc1
		class HashFunc2
		class HashFunc3>
class BloomFilter
{
public:
	BloomFilter(size_t size) // 布隆过滤器中元素个数
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

		return true;//可能存在
	}

private:
	BitMap _bmp;
	size_t _size;
};