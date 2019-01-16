#pragma once
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<assert.h>



// ֧�ֶ�̬������ջ
typedef int STDataType;

typedef struct Stack
{
	STDataType* _array;
	int _top;//ջ��
	int _capacity;//����
}Stack;

void StackInit(Stack* ps);
void StackDestory(Stack* ps);

void StackPush(Stack* ps,STDataType x);
void StackPop(Stack* ps);
STDataType StackTop(Stack* ps);

int StackEmpty(Stack* ps);
int StackSize(Stack* ps);

void StackPrint(Stack* ps);

void StackTest();
