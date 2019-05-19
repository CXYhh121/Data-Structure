#pragma once

#include <iostream>
#include <vector>
using namespace std;

class BitMap
{
public:
	BitMap(size_t range)
	{
		//右移5位相当于除以32，加1是因为小于32的数字如果与32相除则得到0
		_bitTable.resize((range >> 5) + 1);
	}

	void SetBit(size_t x)
	{
		size_t index = x >> 5;//右移5个比特位就是除以32
		size_t num = x % 32;

		_bitTable[index] |= (1 << num);
	}

	void RemoveBit(size_t x)
	{
		size_t index = x >> 5;
		size_t num = x % 32;

		//~(1 << num),对应位为0，其他位为1，相与之后对应位置0，其余位不变
		_bitTable[index] &= ~(1 << num);
	}

	bool TestBit(size_t x)
	{
		size_t index = x >> 5;
		size_t num = x % 32;

		//若该位为1与1相与之后就是1则存在，若该位为0，与1相与后就是0，则不存在
		return _bitTable[index] & (1 << num);
	}

	size_t Size()
	{

	}
private:
	vector<int> _bitTable;//一个int大小就是4个字节，32个比特位
};

