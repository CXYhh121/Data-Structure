#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include<string.h>

typedef int HPDataType;

typedef struct Heap
{
	HPDataType* _array;
	int _size;
	int _Capacity;
}Heap;

void AdjustDown(HPDataType* a, int n,int root);
void HeapInit(Heap* hp, HPDataType* a, int n);
void HeapDestory(Heap* hp);
void AdjustUp(HPDataType* a, int n, int child);
void HeapPush(Heap* hp, HPDataType x);
void HeapPop(Heap* hp);
HPDataType HeapTop(Heap* hp);
int HeapSize(Heap* hp);
int HeapEmpty(Heap* hp);

//top kŒ Ã‚

//∂—≈≈–Ú
void HeapSort(int* a, int n);
void HeapPrint(Heap* hp);
void HeapTest();