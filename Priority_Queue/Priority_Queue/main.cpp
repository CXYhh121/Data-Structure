#define _CRT_SECURE_NO_WARNINGS
#include "Priority_queue.h"
#include "stack.h"
#include "Queue.h"
//仿函数，函数对象
//struct Less
//{
//	bool operator()(int left, int right)
//	{
//		return left < right;
//	}
//};

//template<class T>
//struct Less
//{
//	bool operator()(const T& left, const T& right)
//	{
//		return left < right;
//	}
//};
//
//int main()
//{
//	//priority_queue<int> pq;
//	priority_queue<int, vector<int>, greater<int>> pq;
//	pq.push(3);
//	pq.push(2);
//	pq.push(5);
//	pq.push(0);
//	pq.push(7);
//	pq.push(3);
//
//	while (pq.empty() != 1)
//	{
//		cout << pq.top() << " ";
//		pq.pop();
//	}
//	cout << endl;
//	int a = 1; int b = 2;
//	Less<int> less;//是一个对象，但是可以像使用一个函数一样使用它，称为仿函数
//	cout << less(a, b) << endl;
//	cout << less.operator()(a, b) << endl;
// 
//	return 0;
//}


int main()
{
	//TestPriorityQueue();
	//CXYS::TestStack();
	CXYQ::TestQueue();
	return 0;
}