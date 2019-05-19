#pragma once

#include <iostream>
#include <vector>
using namespace std;

class BitMap
{
public:
	BitMap(size_t range)
	{
		//����5λ�൱�ڳ���32����1����ΪС��32�����������32�����õ�0
		_bitTable.resize((range >> 5) + 1);
	}

	void SetBit(size_t x)
	{
		size_t index = x >> 5;//����5������λ���ǳ���32
		size_t num = x % 32;

		_bitTable[index] |= (1 << num);
	}

	void RemoveBit(size_t x)
	{
		size_t index = x >> 5;
		size_t num = x % 32;

		//~(1 << num),��ӦλΪ0������λΪ1������֮���Ӧλ��0������λ����
		_bitTable[index] &= ~(1 << num);
	}

	bool TestBit(size_t x)
	{
		size_t index = x >> 5;
		size_t num = x % 32;

		//����λΪ1��1����֮�����1����ڣ�����λΪ0����1��������0���򲻴���
		return _bitTable[index] & (1 << num);
	}

	size_t Size()
	{

	}
private:
	vector<int> _bitTable;//һ��int��С����4���ֽڣ�32������λ
};

