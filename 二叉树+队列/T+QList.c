#define _CRT_SECURE_NO_WARNINGS 1

#include "T+QList.h"

void QueueInit(Queue* que)
{
	que->head = que->tail = NULL;
}

void QueueDestroy(Queue* que)
{
	assert(que);

	QueueNode* cur = que->head;
	while (cur)
	{
		QueueNode* next = cur->next;
		free(cur);
		cur = next;
	}

	que->head = que->tail = NULL;
}

void QueuePush(Queue* que, QDataType x)
{
	assert(que);
	QueueNode* newnode = (QueueNode*)malloc(sizeof(QueueNode));
	if (newnode == NULL)
	{
		perror("malloc");
		exit(-1);
	}
	newnode->data = x;
	newnode->next = NULL;
	if (que->head == NULL)
	{		
		que->head = que->tail = newnode;
	}
	else
	{
		que->tail->next = newnode;
		que->tail = newnode;

	}


}

void QueuePop(Queue* que)
{
	assert(que);
	assert(que->head);

	if (que->head == que->tail)
	{
		free(que->tail);
		que->tail = NULL;
		que->head = NULL;
	}
	else
	{
		QueueNode* next = que->head->next;
		free(que->head);
		que->head = next;
	}

}

QDataType QueueFront(Queue* que)
{
	assert(que);
	assert(que->head);

	return que->head->data;
}

QDataType QueueBack(Queue* que)
{
	assert(que);
	assert(que->head);

	return que->tail->data;
}

void QueueSize(Queue* que)
{
	assert(que);
	assert(que->head);

	QueueNode* cur = que->head;
	int count = 0;
	while (cur)
	{
		count++;
		cur = cur->next;
	}
	printf("%d\n", count);
}

bool QueueEmpty(Queue* que)
{
	assert(que);

	return (que->head == NULL);
}
