#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <stack>
#include <queue>
using namespace std;

//用两个栈实现队列
//class MyQueue {
//public:
//	/** Initialize your data structure here. */
//	MyQueue() {
//
//	}
//
//	/** Push element x to the back of queue. */
//	void push(int x) {
//		st1.push(x);
//
//	}
//
//	/** Removes the element from in front of queue and returns that element. */
//	int pop() {
//		if (st2.empty())
//		{
//			while (!st1.empty())
//			{
//				int top = st1.top();
//				st1.pop();
//				st2.push(top);
//			}
//		}
//		int p = st2.top();
//		st2.pop();
//		return p;
//	}
//
//	/** Get the front element. */
//	int peek() {
//		if (st2.empty())
//		{
//			while (st1.empty() != 1)
//			{
//				int top = st1.top();
//				st1.pop();
//				st2.push(top);
//			}
//		}
//		return st2.top();
//
//	}
//
//	/** Returns whether the queue is empty. */
//	bool empty() {
//		if (st1.empty() && st2.empty())
//			return true;
//		else
//			return false;
//	}
//
//private:
//	stack<int> st1;
//	stack<int> st2;
//};

//用队列实现栈
class MyStack {
public:
	/** Initialize your data structure here. */
	MyStack() {

	}

	/** Push element x onto stack. */
	void push(int x) {
		q1.push(x);
	}

	/** Removes the element on top of the stack and returns that element. */
	int pop() {
		int size = q1.size() - 1;
		for (size_t i = 0; i < size; ++i)
		{
			q1.push(q1.front());
			q1.pop();
		}

		int front = q1.front();
		q1.pop();
		return front;

	}

	/** Get the top element. */
	int top() {
		return q1.back();
	}

	/** Returns whether the stack is empty. */
	bool empty() {
		if (q1.empty())
			return true;
		else
			return false;
	}
private:
	queue<int> q1;

};