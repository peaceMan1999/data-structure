#define _CRT_SECURE_NO_WARNINGS 1

#pragma once
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>

typedef int STDataType;

struct stack
{
	STDataType* a;
	int sz;
	int capcity;
};
typedef struct stack stack;

void StackInit(stack* st);

void StackPush(stack* st, STDataType x);
void StackPop(stack* st);
STDataType StackTop(stack* st);

bool StackEmpty(stack* st);
int StackSize(stack* st);

void StackDistroy(stack* st);
