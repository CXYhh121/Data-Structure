#pragma once
#include"common.h"


void QueueInit(Queue* pq);
void QueueDestory(Queue* pq);
void QueuePush(Queue* pq,QDataType x);
void QueuePop(Queue* pq);

QDataType QueueFront(Queue* pq);

int QueueEmpty(Queue* pq);
int QueueSize(Queue* pq);
void QueuePrint(Queue* pq);

void QueueTest();