#define _CRT_SECURE_NO_WARNINGS
#include"Stack.h"



void StackInit(Stack* ps)
{
	assert(ps);
	ps->_array = NULL;
	ps->_capacity = ps->_top = 0;
}
void StackDestory(Stack* ps)
{
	assert(ps);
	free(ps->_array);
	ps->_array = NULL;
	ps->_capacity = 0;
	ps->_top = 0;
}

void StackPush(Stack* ps, STDataType x)
{
	assert(ps);
	if (ps->_top == ps->_capacity)
	{
		size_t newcapacity = ps->_capacity == 0 ? 4 : ps->_capacity * 2;
		ps->_array = (STDataType*)realloc(ps->_array, sizeof(STDataType)*newcapacity);
		assert(ps->_array);
		ps->_capacity = newcapacity;
	}
	ps->_array[ps->_top] = x;
	++ps->_top;   

}
void StackPop(Stack* ps)
{
	assert(ps && ps->_top > 0);
	--ps->_top;
}
STDataType StackTop(Stack* ps)
{
	assert(ps && ps->_top > 0);
	return ps->_array[ps->_top -1];
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

void StackPrint(Stack* ps)
{
	assert(ps);
	while (StackEmpty(ps))
	{
		printf("%d ", StackTop(ps));
		StackPop(ps);
	}
	printf("\n");
}
void StackTest()
{
	Stack s;
	StackInit(&s);
	StackPush(&s, 1);
	StackPush(&s, 2);
	StackPush(&s, 3);
	StackPush(&s, 4);

	printf("%d\n", StackTop(&s));
	printf("%d\n", StackEmpty(&s));
	printf("%d\n", StackSize(&s));

	StackPrint(&s);
	StackDestory(&s);
}