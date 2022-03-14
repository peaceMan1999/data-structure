#define _CRT_SECURE_NO_WARNINGS 1

#pragma once
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>

typedef int QDataType;

typedef struct QueueNode
{
	struct QueueNode* next;
	QDataType data;
}QueueNode;

typedef struct Queue
{
	struct QueueNode* head;
	struct QueueNode* tail;
}Queue;

void QueueInit(Queue* que);
void QueueDestroy(Queue* que);

void QueuePush(Queue* que, QDataType x);
void QueuePop(Queue* que);

QDataType QueueFront(Queue* que);
QDataType QueueBack(Queue* que);

void QueueSize(Queue* que);
bool QueueEmpty(Queue* que);


