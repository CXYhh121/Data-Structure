#define _CRT_SECURE_NO_WARNINGS
//栈和队列面试题，判断是否为有效括号
#include <stdio.h>
#include <string.h>
#include <assert.h>
// 支持动态增长的栈
typedef char STDataType;
typedef struct Stack
{
	STDataType* _a;
	int _top; // 栈顶
	int _capacity; // 容量
}Stack;

void StackInit(Stack* ps)
{
	assert(ps);
	ps->_a = NULL;
	ps->_capacity = 0;
	ps->_top = 0;
}

void StackDestory(Stack* ps)
{
	assert(ps);
	free(ps->_a);
	ps->_a = NULL;
	ps->_capacity = 0;
	ps->_top = 0;
}

void StackPush(Stack* ps, STDataType x)
{
	assert(ps);
	if (ps->_top == ps->_capacity)
	{
		size_t newcapacity = ps->_capacity == 0 ? 4 : ps->_capacity * 2;
		ps->_a = (STDataType*)realloc(ps->_a, sizeof(STDataType)*newcapacity);
		assert(ps->_a != NULL);
		ps->_capacity = newcapacity;
	}

	ps->_a[ps->_top] = x;
	ps->_top++;
}

void StackPop(Stack* ps)
{
	assert(ps && ps->_top > 0);
	--ps->_top;
}

STDataType StackTop(Stack* ps)
{
	assert(ps && ps->_top > 0);
	return ps->_a[ps->_top - 1];
}

int StackEmpty(Stack* ps)
{
	assert(ps);
	return ps->_top == 0 ? 0 : 1;
}

int StackSize(Stack* ps)
{
	assert(ps);
	return ps->_top;
}

bool isValid(char* s) {
	Stack st;
	StackInit(&st);
	while (*s)
	{

		if (*s == '(' || *s == '[' || *s == '{')
		{
			StackPush(&st, *s);
		}

		else if (*s == ')')
		{
			if (StackEmpty(&st) == 0)
				return false;
			if (StackTop(&st) == '(')
			{
				StackPop(&st);
			}
			else
			{
				StackDestory(&st);
				return false;
			}
		}
		else if (*s == ']')
		{
			if (StackEmpty(&st) == 0)
				return false;
			if (StackTop(&st) == '[')
			{
				StackPop(&st);
			}
			else
			{
				StackDestory(&st);
				return false;
			}
		}
		else if (*s == '}')
		{
			if (StackEmpty(&st) == 0)
				return false;
			if (StackTop(&st) == '{')
			{
				StackPop(&st);
			}
			else
			{
				StackDestory(&st);
				return false;
			}
		}
		++s;
	}
	if (StackEmpty(&st) == 0)
		return true;
	else
		return false;

}