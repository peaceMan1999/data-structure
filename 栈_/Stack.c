#define _CRT_SECURE_NO_WARNINGS 1

#include "Stack.h"

void StackInit(stack* st)
{
	STDataType* newnode = (STDataType*)malloc(sizeof(STDataType) * 4);
	if (newnode == NULL)
	{
		perror("Init");
		exit(-1);
	}
	st->a = newnode;
	st->capcity = 4;
	st->sz = 0;
}

void StackPush(stack* st, STDataType x)
{
	assert(st);
	if (st->sz == st->capcity)
	{
		STDataType* newnode = (STDataType*)realloc(st->a, sizeof(STDataType) * st->capcity * 2);
		if (newnode == NULL)
		{
			perror("realloc");
			exit(-1);
		}
		st->a = newnode;
		st->capcity *= 2;
	}
	st->a[st->sz] = x;
	st->sz++;
}

void StackPop(stack* st)
{
	assert(st);
	assert(!StackEmpty(st));

	st->sz--;
}

STDataType StackTop(stack* st)
{
	assert(st);
	assert(!StackEmpty(st));

	return st->a[st->sz - 1];
}

bool StackEmpty(stack* st)
{
	assert(st);
	
	return st->sz == 0;
}

int StackSize(stack* st)
{
	assert(st);

	return st->sz;
}

void StackDistroy(stack* st)
{
	assert(st);

	st->capcity = st->sz = 0;
	free(st->a);
	st->a = NULL;
}